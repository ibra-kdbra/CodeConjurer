#include "nets/http_client.h"
#include "nets/compression.h"
#include "mpmt/thread.h"

#include <stdio.h>
#include <ctype.h>
#include <errno.h>

struct HttpClient_T
{
	size_t responseBufferSize;
	size_t headerBufferSize;
	char* lastHostname;
	size_t lastHostnameLength;
	StreamClient handle;
	char* response;
	HttpPair* headers;
	size_t chunkSize;
	size_t responseLength;
	size_t headerCount;
	z_stream* zlibStream;
	uint16_t statusCode;
	bool isChunked;
	bool isCompressed;
	bool isClose;
	bool isBody;
	NetsResult result;
	bool isRunning;
};

static int cmpHttpHeaders(const void* a, const void* b)
{
	const HttpPair* ah = (const HttpPair*)a;
	const HttpPair* bh = (const HttpPair*)b;

	int difference = ah->keyLength - bh->keyLength;

	if (difference != 0)
		return difference;

	const char* ak = ah->key;
	const char* bk = bh->key;
	int length = ah->keyLength;

	for (int i = 0; i < length; i++)
	{
		difference = tolower(ak[i]) - tolower(bk[i]);

		if (difference != 0)
			return difference;
	}

	return 0;
}

inline static void finalizeResponse(HttpClient httpClient)
{
	assert(httpClient);

	if (httpClient->isClose)
		disconnectStreamClient(httpClient->handle);
	if (httpClient->zlibStream && httpClient->isCompressed)
		httpClient->responseLength = httpClient->zlibStream->total_out;

	httpClient->response[httpClient->responseLength] = '\0';
	httpClient->result = SUCCESS_NETS_RESULT;
	httpClient->isRunning = false;
}
inline static NetsResult processResponseLine(
	HttpClient httpClient,
	const char* line,
	size_t length)
{
	assert(httpClient);
	assert(line);

	if (length > 0 && line[length - 1] == '\r')
		length--;

	if (length == 0)
	{
		if (!httpClient->isBody)
		{
			qsort(httpClient->headers,
				httpClient->headerCount,
				sizeof(HttpPair),
				cmpHttpHeaders);

			const HttpPair* header = getHttpClientHeader(
				httpClient,
				"Content-Length",
				14);

			if (header)
			{
				errno = 0;

				int64_t chunkSize = (int64_t)strtol(
					header->value,
					NULL,
					10);

				if (chunkSize == 0)
				{
					if (errno != 0)
						return BAD_DATA_NETS_RESULT;
					return SUCCESS_NETS_RESULT;
				}

				if (chunkSize < 0)
					return BAD_DATA_NETS_RESULT;
				if ((size_t)chunkSize + 1 > httpClient->responseBufferSize)
					return OUT_OF_MEMORY_NETS_RESULT;

				httpClient->chunkSize = chunkSize;
			}
			else
			{
				header = getHttpClientHeader(
					httpClient,
					"Transfer-Encoding",
					17);

				if (!header || header->valueLength != 7 ||
					memcmp(header->value, "chunked", 7 * sizeof(char)) != 0)
				{
					return BAD_DATA_NETS_RESULT;
				}

				httpClient->isChunked = true;
			}

			header = getHttpClientHeader(
				httpClient,
				"Content-Encoding",
				16);

			if (header)
			{
				if (!httpClient->zlibStream || header->valueLength != 4 ||
					memcmp(header->value, "gzip", 4 * sizeof(char)) != 0)
				{
					return BAD_DATA_NETS_RESULT;
				}

				httpClient->isCompressed = true;
			}

			header = getHttpClientHeader(
				httpClient,
				"Connection",
				10);

			if (header)
			{
				if (header->valueLength == 5 &&
					memcmp(header->value, "close", 5 * sizeof(char)) == 0)
				{
					httpClient->isClose = true;
				}
				else if (header->valueLength != 10 &&
					memcmp(header->value, "keep-alive", 10 * sizeof(char)) != 0)
				{
					return BAD_DATA_NETS_RESULT;
				}
			}

			httpClient->isBody = true;
		}

		return SUCCESS_NETS_RESULT;
	}

	if (httpClient->statusCode == 0)
	{
		if (length < 10 || memcmp(line, "HTTP/1.1 ", 9 * sizeof(char)) != 0)
			return BAD_DATA_NETS_RESULT;

		uint16_t statusCode = (uint16_t)strtol(
			line + 9,
			NULL,
			10);

		if (statusCode == 0)
			return BAD_DATA_NETS_RESULT;

		httpClient->statusCode = statusCode;
	}
	else if (!httpClient->isBody)
	{
		if (httpClient->headerCount == httpClient->headerBufferSize)
			return OUT_OF_MEMORY_NETS_RESULT;

		const char* pointer = memchr(line, ':', length);
		int keyLength = pointer ? (int)(pointer - line) : 0;

		if (keyLength == 0 || length < keyLength + 2)
			return BAD_DATA_NETS_RESULT;

		int valueLength = (int)(length - (keyLength + 2));

		if (valueLength == 0)
			return BAD_DATA_NETS_RESULT;

		char* key = malloc((keyLength + 1) * sizeof(char));

		if (!key)
			return OUT_OF_MEMORY_NETS_RESULT;

		memcpy(key, line,
			keyLength * sizeof(char));
		key[keyLength] = '\0';

		char* value = malloc((valueLength + 1) * sizeof(char));

		if (!value)
		{
			free(key);
			return OUT_OF_MEMORY_NETS_RESULT;
		}

		memcpy(value, line + (length - valueLength),
			valueLength * sizeof(char));
		value[valueLength] = '\0';

		HttpPair header = {
			key, value,
			keyLength, valueLength
		};

		httpClient->headers[httpClient->headerCount++] = header;
	}
	else
	{
		errno = 0;

		int64_t chunkSize = (int64_t)strtol(
			line,
			NULL,
			16);

		if (chunkSize == 0)
		{
			if (errno != 0)
				return BAD_DATA_NETS_RESULT;

			finalizeResponse(httpClient);
			return SUCCESS_NETS_RESULT;
		}

		if (chunkSize < 0)
			return BAD_DATA_NETS_RESULT;
		if (httpClient->responseLength + chunkSize + 1 > httpClient->responseBufferSize)
			return OUT_OF_MEMORY_NETS_RESULT;

		httpClient->chunkSize = chunkSize;
	}

	return SUCCESS_NETS_RESULT;
}
static void onStreamClientReceive(
	StreamClient streamClient,
	const uint8_t* receiveBuffer,
	size_t byteCount)
{
	assert(streamClient);
	assert(receiveBuffer);

	HttpClient httpClient = (HttpClient)
		getStreamClientHandle(streamClient);

	if (byteCount == 0)
	{
		httpClient->result = CONNECTION_IS_CLOSED_NETS_RESULT;
		httpClient->isRunning = false;
		return;
	}

	size_t lineOffset = 0;

	if (httpClient->isBody && httpClient->chunkSize > 0)
	{
		size_t chunkSize = httpClient->chunkSize;
		char* response = httpClient->response;

		if (chunkSize < byteCount)
		{
			if (httpClient->isCompressed)
			{
				z_stream* zlibStream = httpClient->zlibStream;
				zlibStream->avail_in = (uInt)chunkSize;
				zlibStream->next_in = (Bytef*)receiveBuffer;

				int result = inflate(zlibStream, Z_NO_FLUSH);

				if (result != Z_OK && result != Z_STREAM_END)
				{
					httpClient->result = zlibErrorToNetsResult(result);
					httpClient->isRunning = false;
					return;
				}
			}
			else
			{
				memcpy(response + httpClient->responseLength,
					receiveBuffer, chunkSize * sizeof(char));
				httpClient->responseLength += chunkSize;
			}

			httpClient->chunkSize = 0;
			lineOffset += chunkSize;
		}
		else
		{
			if (httpClient->isCompressed)
			{
				z_stream* zlibStream = httpClient->zlibStream;
				zlibStream->avail_in = (uInt)byteCount;
				zlibStream->next_in = (Bytef*)receiveBuffer;

				int result = inflate(zlibStream, Z_NO_FLUSH);

				if (result != Z_OK && result != Z_STREAM_END)
				{
					httpClient->result = zlibErrorToNetsResult(result);
					httpClient->isRunning = false;
					return;
				}
			}
			else
			{
				memcpy(response + httpClient->responseLength,
					receiveBuffer, byteCount * sizeof(char));
				httpClient->responseLength += byteCount;
			}

			httpClient->chunkSize -= byteCount;

			if (!httpClient->isChunked && httpClient->chunkSize == 0)
				finalizeResponse(httpClient);

			return;
		}
	}

	const char* buffer = (const char*)receiveBuffer;

	while (lineOffset < byteCount)
	{
		const char* pointer = memchr(
			buffer + lineOffset,
			'\n',
			byteCount - lineOffset);

		if (!pointer)
			break;

		size_t index = pointer - buffer;

		NetsResult netsResult;

		if (httpClient->chunkSize > 0)
		{
			size_t chunkSize = httpClient->chunkSize;
			size_t size = index - lineOffset;

			if (chunkSize + size > httpClient->responseBufferSize)
			{
				httpClient->result = OUT_OF_MEMORY_NETS_RESULT;
				httpClient->isRunning = false;
				return;
			}

			char* response = httpClient->response;

			memcpy(response + chunkSize,
				receiveBuffer, size * sizeof(char));

			netsResult = processResponseLine(
				httpClient,
				response,
				chunkSize + size);

			httpClient->chunkSize = 0;
		}
		else
		{
			netsResult = processResponseLine(
				httpClient,
				buffer + lineOffset,
				index - lineOffset);
		}

		if (netsResult != SUCCESS_NETS_RESULT)
		{
			httpClient->result = netsResult;
			httpClient->isRunning = false;
			return;
		}

		lineOffset = index + 1;

		if (lineOffset == byteCount)
			return;

		if (httpClient->isBody)
		{
			size_t length = byteCount - lineOffset;
			size_t chunkSize = httpClient->chunkSize;
			char* response = httpClient->response;

			if (chunkSize < length)
			{
				if (chunkSize > 0)
				{
					if (httpClient->isCompressed)
					{
						z_stream* zlibStream = httpClient->zlibStream;
						zlibStream->avail_in = (uInt)chunkSize;
						zlibStream->next_in = (Bytef*)(receiveBuffer + lineOffset);

						int result = inflate(zlibStream, Z_NO_FLUSH);

						if (result != Z_OK && result != Z_STREAM_END)
						{
							httpClient->result = zlibErrorToNetsResult(result);
							httpClient->isRunning = false;
							return;
						}
					}
					else
					{
						memcpy(response + httpClient->responseLength,
							receiveBuffer + lineOffset, chunkSize * sizeof(char));
						httpClient->responseLength += chunkSize;
					}

					httpClient->chunkSize = 0;
					lineOffset += chunkSize;
				}
			}
			else
			{
				if (httpClient->isCompressed)
				{
					z_stream* zlibStream = httpClient->zlibStream;
					zlibStream->avail_in = (uInt)length;
					zlibStream->next_in = (Bytef*)(receiveBuffer + lineOffset);

					int result = inflate(zlibStream, Z_NO_FLUSH);

					if (result != Z_OK && result != Z_STREAM_END)
					{
						httpClient->result = zlibErrorToNetsResult(result);
						httpClient->isRunning = false;
						return;
					}
				}
				else
				{
					memcpy(response + httpClient->responseLength,
						receiveBuffer + lineOffset, length * sizeof(char));
					httpClient->responseLength += length;
				}

				httpClient->chunkSize -= length;

				if (!httpClient->isChunked && httpClient->chunkSize == 0)
					finalizeResponse(httpClient);

				return;
			}
		}
	}

	if (lineOffset != byteCount)
	{
		size_t size = byteCount - lineOffset;
		size_t chunkSize = httpClient->chunkSize;

		if (chunkSize + size > httpClient->responseBufferSize)
		{
			httpClient->result = OUT_OF_MEMORY_NETS_RESULT;
			httpClient->isRunning = false;
			return;
		}

		memcpy(httpClient->response + chunkSize,
			receiveBuffer + lineOffset, size * sizeof(char));
		httpClient->chunkSize += size;
	}
}

NetsResult createHttpClient(
	size_t dataBufferSize,
	size_t responseBufferSize,
	size_t headerBufferSize,
	double timeoutTime,
	bool useCompression,
	SslContext sslContext,
	HttpClient* httpClient)
{
	assert(dataBufferSize > 0);
	assert(responseBufferSize > 0);
	assert(timeoutTime > 0.0);
	assert(httpClient);

	HttpClient httpClientInstance = calloc(
		1, sizeof(HttpClient_T));

	if (!httpClientInstance)
		return OUT_OF_MEMORY_NETS_RESULT;

	httpClientInstance->chunkSize = 0;
	httpClientInstance->responseLength = 0;
	httpClientInstance->lastHostname = NULL;
	httpClientInstance->lastHostnameLength = 0;
	httpClientInstance->headerCount = 0;
	httpClientInstance->statusCode = 0;
	httpClientInstance->isChunked = false;
	httpClientInstance->isCompressed = false;
	httpClientInstance->isClose = false;
	httpClientInstance->isBody = false;
	httpClientInstance->result = SUCCESS_NETS_RESULT;
	httpClientInstance->isRunning = false;

	StreamClient handle;

	NetsResult netsResult = createStreamClient(
		dataBufferSize,
		timeoutTime,
		onStreamClientReceive,
		httpClientInstance,
		sslContext,
		&handle);

	if (netsResult != SUCCESS_NETS_RESULT)
	{
		destroyHttpClient(httpClientInstance);
		return netsResult;
	}

	httpClientInstance->handle = handle;

	char* response = malloc(
		responseBufferSize * sizeof(char));

	if (!response)
	{
		destroyHttpClient(httpClientInstance);
		return OUT_OF_MEMORY_NETS_RESULT;
	}

	httpClientInstance->response = response;
	httpClientInstance->responseBufferSize = responseBufferSize;

	HttpPair* headers = malloc(
		headerBufferSize * sizeof(HttpPair));

	if (!headers)
	{
		destroyHttpClient(httpClientInstance);
		return OUT_OF_MEMORY_NETS_RESULT;
	}

	httpClientInstance->headers = headers;
	httpClientInstance->headerBufferSize = headerBufferSize;

	if (useCompression)
	{
		z_stream* zlibStream = calloc(
			1, sizeof(z_stream));

		if (!zlibStream)
		{
			destroyHttpClient(httpClientInstance);
			return OUT_OF_MEMORY_NETS_RESULT;
		}

		httpClientInstance->zlibStream = zlibStream;

		int result = inflateInit2(zlibStream, 31);

		if (result != Z_OK)
		{
			destroyHttpClient(httpClientInstance);
			return zlibErrorToNetsResult(result);
		}
	}
	else
	{
		httpClientInstance->zlibStream = NULL;
	}

	*httpClient = httpClientInstance;
	return SUCCESS_NETS_RESULT;
}
void destroyHttpClient(HttpClient httpClient)
{
	if (!httpClient)
		return;

	destroyStreamClient(httpClient->handle);

	z_stream* zlibStream = httpClient->zlibStream;

	if (zlibStream)
	{
		inflateEnd(zlibStream);
		free(zlibStream);
	}

	HttpPair* headers = httpClient->headers;

	if (headers)
	{
		size_t headerCount = httpClient->headerCount;

		for (size_t i = 0; i < headerCount; i++)
		{
			const HttpPair* header = &headers[i];
			free((char*)header->value);
			free((char*)header->key);
		}

		free(headers);
	}

	free(httpClient->response);
	free(httpClient->lastHostname);
	free(httpClient);
}

size_t getHttpResponseBufferSize(HttpClient httpClient)
{
	assert(httpClient);
	return httpClient->responseBufferSize;
}
size_t getHttpHeaderBufferSize(HttpClient httpClient)
{
	assert(httpClient);
	return httpClient->headerBufferSize;
}
StreamClient getHttpClientStream(HttpClient httpClient)
{
	assert(httpClient);
	return httpClient->handle;
}
bool isHttpClientUseCompression(HttpClient httpClient)
{
	assert(httpClient);
	return httpClient->zlibStream;
}
int getHttpClientStatusCode(HttpClient httpClient)
{
	assert(httpClient);
	return httpClient->statusCode;
}
const char* getHttpClientResponse(HttpClient httpClient)
{
	assert(httpClient);
	return httpClient->response;
}
size_t getHttpClientResponseLength(HttpClient httpClient)
{
	assert(httpClient);
	return httpClient->responseLength;
}
const HttpPair* getHttpClientHeaders(HttpClient httpClient)
{
	assert(httpClient);
	return httpClient->headers;
}
size_t getHttpClientHeaderCount(HttpClient httpClient)
{
	assert(httpClient);
	return httpClient->headerCount;
}

inline static NetsResult clearHttpClient(HttpClient httpClient)
{
	assert(httpClient);

	HttpPair* headerBuffer = httpClient->headers;
	size_t headerBufferSize = httpClient->headerCount;

	for (size_t i = 0; i < headerBufferSize; i++)
	{
		const HttpPair* header = &headerBuffer[i];
		free((char*)header->value);
		free((char*)header->key);
	}

	if (httpClient->zlibStream)
	{
		z_stream* zlibStream = httpClient->zlibStream;
		int zlibResult = inflateReset(zlibStream);

		if (zlibResult != Z_OK)
			return zlibErrorToNetsResult(zlibResult);

		zlibStream->avail_out = (uInt)(httpClient->responseBufferSize - 1);
		zlibStream->next_out = (Bytef*)httpClient->response;
	}

	httpClient->chunkSize = 0;
	httpClient->responseLength = 0;
	httpClient->headerCount = 0;
	httpClient->statusCode = 0;
	httpClient->isChunked = false;
	httpClient->isCompressed = false;
	httpClient->isClose = false;
	httpClient->isBody = false;
	httpClient->result = TIMED_OUT_NETS_RESULT;
	httpClient->isRunning = true;
	return SUCCESS_NETS_RESULT;
}
NetsResult httpClientSendGET(
	HttpClient httpClient,
	const char* url,
	size_t urlLength,
	const HttpPair* headers,
	size_t headerCount,
	bool keepAlive)
{
	assert(httpClient);
	assert(url);
	assert(urlLength > 0);

	assert((headers && headerCount > 0) ||
		(!headers && headerCount == 0));

#ifndef NDEBUG
	for (size_t i = 0; i < headerCount; i++)
	{
		HttpPair header = headers[i];
		assert(header.key);
		assert(header.keyLength > 0);
		assert(header.value);
		assert(header.valueLength > 0);
	}
#endif

	StreamClient streamClient = httpClient->handle;
	size_t hostOffset, hostLength, serviceOffset, serviceLength, pathOffset;

	getUrlParts(url,
		urlLength,
		&hostOffset,
		&hostLength,
		&serviceOffset,
		&serviceLength,
		&pathOffset);

	if (hostLength == 0)
		return BAD_DATA_NETS_RESULT;
	if (hostLength > 255)
		return OUT_OF_MEMORY_NETS_RESULT;

	char host[256];

	memcpy(host, url + hostOffset,
		hostLength * sizeof(char));
	host[hostLength] = '\0';

	char serviceBuffer[32];
	char* service;

	if (serviceLength != 0)
	{
		if (serviceLength > 31)
			return OUT_OF_MEMORY_NETS_RESULT;

		memcpy(serviceBuffer, url + serviceOffset,
			serviceLength * sizeof(char));
		serviceBuffer[serviceLength] = '\0';
		service = serviceBuffer;
	}
	else
	{
		service = NULL;
	}

	size_t pathLength = urlLength - pathOffset;
	size_t requestLength = pathLength + hostLength + 38;
	requestLength += keepAlive ? 12 : 7;

	if (httpClient->zlibStream)
		requestLength += 23;

	for (size_t i = 0; i < headerCount; i++)
	{
		const HttpPair* header = &headers[i];
		requestLength += header->keyLength + header->valueLength + 4;
	}

	if (requestLength > getStreamClientBufferSize(streamClient))
		return OUT_OF_MEMORY_NETS_RESULT;

	char* request = (char*)getStreamClientBuffer(streamClient);

	request[0] = 'G'; request[1] = 'E'; request[2] = 'T';
	request[3] = ' '; request[4] = '/';
	size_t index = 5;

	memcpy(request + index, url + pathOffset,
		pathLength * sizeof(char));
	index += pathLength;

	request[index + 0] = ' '; request[index + 1] = 'H';
	request[index + 2] = 'T'; request[index + 3] = 'T';
	request[index + 4] = 'P'; request[index + 5] = '/';
	request[index + 6] = '1'; request[index + 7] = '.';
	request[index + 8] = '1'; request[index + 9] = '\r';
	request[index + 10] = '\n'; request[index + 11] = 'H';
	request[index + 12] = 'o'; request[index + 13] = 's';
	request[index + 14] = 't'; request[index + 15] = ':';
	request[index + 16] = ' ';
	index += 17;

	memcpy(request + index, host,
		hostLength * sizeof(char));
	index += hostLength;

	request[index + 0] = '\r'; request[index + 1] = '\n';
	request[index + 2] = 'C'; request[index + 3] = 'o';
	request[index + 4] = 'n'; request[index + 5] = 'n';
	request[index + 6] = 'e'; request[index + 7] = 'c';
	request[index + 8] = 't'; request[index + 9] = 'i';
	request[index + 10] = 'o'; request[index + 11] = 'n';
	request[index + 12] = ':'; request[index + 13] = ' ';
	index += 14;

	if (keepAlive)
	{
		request[index + 0] = 'k'; request[index + 1] = 'e';
		request[index + 2] = 'e'; request[index + 3] = 'p';
		request[index + 4] = '-'; request[index + 5] = 'a';
		request[index + 6] = 'l'; request[index + 7] = 'i';
		request[index + 8] = 'v'; request[index + 9] = 'e';
		request[index + 10] = '\r'; request[index + 11] = '\n';
		index += 12;
	}
	else
	{
		request[index + 0] = 'c'; request[index + 1] = 'l';
		request[index + 2] = 'o'; request[index + 3] = 's';
		request[index + 4] = 'e'; request[index + 5] = '\r';
		request[index + 6] = '\n';
		index += 7;
	}

	if (httpClient->zlibStream)
	{
		request[index + 0] = 'A'; request[index + 1] = 'c';
		request[index + 2] = 'c'; request[index + 3] = 'e';
		request[index + 4] = 'p'; request[index + 5] = 't';
		request[index + 6] = '-'; request[index + 7] = 'E';
		request[index + 8] = 'n'; request[index + 9] = 'c';
		request[index + 10] = 'o'; request[index + 11] = 'd';
		request[index + 12] = 'i'; request[index + 13] = 'n';
		request[index + 14] = 'g'; request[index + 15] = ':';
		request[index + 16] = ' '; request[index + 17] = 'g';
		request[index + 18] = 'z'; request[index + 19] = 'i';
		request[index + 20] = 'p'; request[index + 21] = '\r';
		request[index + 22] = '\n';
		index += 23;
	}

	for (size_t i = 0; i < headerCount; i++)
	{
		HttpPair header = headers[i];
		memcpy(request + index, header.key,
			header.keyLength * sizeof(char));
		index += header.keyLength;

		request[index + 0] = ':'; request[index + 1] = ' ';
		index += 2;

		memcpy(request + index, header.value,
			header.valueLength * sizeof(char));
		index += header.valueLength;

		request[index + 0] = '\r'; request[index + 1] = '\n';
		index += 2;
	}

	request[index + 0] = '\r'; request[index + 1] = '\n';
	index += 2;

	assert(index == requestLength);

	NetsResult netsResult = clearHttpClient(httpClient);

	if (netsResult != SUCCESS_NETS_RESULT)
		return netsResult;

	bool isAlreadyConnected = false;

	if (isStreamClientConnected(streamClient))
	{
		if (httpClient->lastHostnameLength != hostLength || memcmp(
			httpClient->lastHostname, host, hostLength * sizeof(char)) != 0)
		{
			disconnectStreamClient(streamClient);

			netsResult = connectHostnameStreamClient(
				streamClient,
				host,
				service ? service : "443",
				true);

			if (netsResult != SUCCESS_NETS_RESULT)
				return netsResult;

			setSocketNoDelay(
				getStreamClientSocket(streamClient),
				true);

			if (keepAlive)
			{
				char* hostname = malloc(
					(hostLength + 1) * sizeof(char));

				if (!hostname)
				{
					disconnectStreamClient(streamClient);
					return OUT_OF_MEMORY_NETS_RESULT;
				}

				free(httpClient->lastHostname);
				httpClient->lastHostname = hostname;
				httpClient->lastHostnameLength = hostLength;
				memcpy(hostname, host, hostLength * sizeof(char));
				hostname[hostLength] = '\0';
			}
		}
		else
		{
			isAlreadyConnected = true;
		}
	}
	else
	{
		netsResult = connectHostnameStreamClient(
			streamClient,
			host,
			service ? service : "443",
			true);

		if (netsResult != SUCCESS_NETS_RESULT)
			return netsResult;

		setSocketNoDelay(
			getStreamClientSocket(streamClient),
			true);

		if (keepAlive)
		{
			char* hostname = malloc(
				(hostLength + 1) * sizeof(char));

			if (!hostname)
			{
				disconnectStreamClient(streamClient);
				return OUT_OF_MEMORY_NETS_RESULT;
			}

			free(httpClient->lastHostname);
			httpClient->lastHostname = hostname;
			httpClient->lastHostnameLength = hostLength;
			memcpy(hostname, host, hostLength * sizeof(char));
			hostname[hostLength] = '\0';
		}
	}

	resetStreamClientTimeout(streamClient);

	netsResult = streamClientSend(
		streamClient,
		request,
		requestLength);

	if (netsResult != SUCCESS_NETS_RESULT)
	{
		if (isAlreadyConnected)
		{
			disconnectStreamClient(streamClient);

			netsResult = connectHostnameStreamClient(
				streamClient,
				host,
				service ? service : "443",
				true);

			if (netsResult != SUCCESS_NETS_RESULT)
				return netsResult;

			setSocketNoDelay(
				getStreamClientSocket(streamClient),
				true);

			netsResult = streamClientSend(
				streamClient,
				request,
				requestLength);

			if (netsResult != SUCCESS_NETS_RESULT)
			{
				disconnectStreamClient(streamClient);
				return netsResult;
			}
		}
		else
		{
			disconnectStreamClient(streamClient);
			return netsResult;
		}
	}

	while (httpClient->isRunning)
	{
		netsResult = updateStreamClient(streamClient);

		if (netsResult == SUCCESS_NETS_RESULT)
			continue;

		if (netsResult != IN_PROGRESS_NETS_RESULT)
		{
			disconnectStreamClient(streamClient);
			return netsResult;
		}

		sleepThread(0.001);
	}

	if (!keepAlive)
		disconnectStreamClient(streamClient);

	return httpClient->result;
}
NetsResult httpClientSendPOST(
	HttpClient httpClient,
	const char* url,
	size_t urlLength,
	const HttpPair* pairs,
	size_t pairCount,
	const HttpPair* headers,
	size_t headerCount,
	bool isMultipart,
	bool keepAlive)
{
	assert(httpClient);
	assert(url);
	assert(urlLength > 0);
	assert(pairs);
	assert(pairCount > 0);
	assert(!isMultipart); // TODO:

	assert((headers && headerCount > 0) ||
		(!headers && headerCount == 0));

#ifndef NDEBUG
	for (size_t i = 0; i < headerCount; i++)
	{
		HttpPair header = headers[i];
		assert(header.key);
		assert(header.keyLength > 0);
		assert(header.value);
		assert(header.valueLength > 0);
	}
	for (size_t i = 0; i < pairCount; i++)
	{
		HttpPair pair = pairs[i];
		assert(pair.key);
		assert(pair.keyLength > 0);
		assert(pair.value);
		assert(pair.valueLength > 0);
	}
#endif

	StreamClient streamClient = httpClient->handle;
	size_t hostOffset, hostLength, serviceOffset, serviceLength, pathOffset;

	getUrlParts(url,
		urlLength,
		&hostOffset,
		&hostLength,
		&serviceOffset,
		&serviceLength,
		&pathOffset);

	if (hostLength == 0)
		return BAD_DATA_NETS_RESULT;
	if (hostLength > 255)
		return OUT_OF_MEMORY_NETS_RESULT;

	char host[256];

	memcpy(host, url + hostOffset,
		hostLength * sizeof(char));
	host[hostLength] = '\0';

	char serviceBuffer[32];
	char* service;

	if (serviceLength != 0)
	{
		if (serviceLength > 31)
			return OUT_OF_MEMORY_NETS_RESULT;

		memcpy(serviceBuffer, url + serviceOffset,
			serviceLength * sizeof(char));
		serviceBuffer[serviceLength] = '\0';
		service = serviceBuffer;
	}
	else
	{
		service = NULL;
	}

	size_t pathLength = urlLength - pathOffset;
	size_t requestLength = pathLength + hostLength + 71;
	requestLength += keepAlive ? 12 : 7;

	if (httpClient->zlibStream)
		requestLength += 23;
	if (!isMultipart)
		requestLength += 35;

	for (size_t i = 0; i < headerCount; i++)
	{
		const HttpPair* header = &headers[i];
		requestLength += header->keyLength + header->valueLength + 4;
	}

	size_t minPairCount = pairCount - 1;
	size_t contentLength = 0;

	for (size_t i = 0; i < pairCount; i++)
	{
		const HttpPair* pair = &pairs[i];
		contentLength += pair->keyLength + pair->valueLength + 1;

		if (i < minPairCount)
			contentLength++;
	}

	if (contentLength > UINT32_MAX)
		return OUT_OF_MEMORY_NETS_RESULT;

	requestLength += contentLength;

	char clString[16];
	int clStringLength = snprintf(clString, 16, "%u", (uint32_t)contentLength);

	if (clStringLength <= 0)
		return UNKNOWN_ERROR_NETS_RESULT;

	requestLength += clStringLength;

	if (requestLength > getStreamClientBufferSize(streamClient))
		return OUT_OF_MEMORY_NETS_RESULT;

	char* request = (char*)getStreamClientBuffer(streamClient);

	request[0] = 'P'; request[1] = 'O'; request[2] = 'S';
	request[3] = 'T'; request[4] = ' '; request[5] = '/';
	size_t index = 6;

	memcpy(request + index, url + pathOffset,
		pathLength * sizeof(char));
	index += pathLength;

	request[index + 0] = ' '; request[index + 1] = 'H';
	request[index + 2] = 'T'; request[index + 3] = 'T';
	request[index + 4] = 'P'; request[index + 5] = '/';
	request[index + 6] = '1'; request[index + 7] = '.';
	request[index + 8] = '1'; request[index + 9] = '\r';
	request[index + 10] = '\n'; request[index + 11] = 'H';
	request[index + 12] = 'o'; request[index + 13] = 's';
	request[index + 14] = 't'; request[index + 15] = ':';
	request[index + 16] = ' ';
	index += 17;

	memcpy(request + index, host,
		hostLength * sizeof(char));
	index += hostLength;

	request[index + 0] = '\r'; request[index + 1] = '\n';
	request[index + 2] = 'C'; request[index + 3] = 'o';
	request[index + 4] = 'n'; request[index + 5] = 'n';
	request[index + 6] = 'e'; request[index + 7] = 'c';
	request[index + 8] = 't'; request[index + 9] = 'i';
	request[index + 10] = 'o'; request[index + 11] = 'n';
	request[index + 12] = ':'; request[index + 13] = ' ';
	index += 14;

	if (keepAlive)
	{
		request[index + 0] = 'k'; request[index + 1] = 'e';
		request[index + 2] = 'e'; request[index + 3] = 'p';
		request[index + 4] = '-'; request[index + 5] = 'a';
		request[index + 6] = 'l'; request[index + 7] = 'i';
		request[index + 8] = 'v'; request[index + 9] = 'e';
		request[index + 10] = '\r'; request[index + 11] = '\n';
		index += 12;
	}
	else
	{
		request[index + 0] = 'c'; request[index + 1] = 'l';
		request[index + 2] = 'o'; request[index + 3] = 's';
		request[index + 4] = 'e'; request[index + 5] = '\r';
		request[index + 6] = '\n';
		index += 7;
	}

	if (httpClient->zlibStream)
	{
		request[index + 0] = 'A'; request[index + 1] = 'c';
		request[index + 2] = 'c'; request[index + 3] = 'e';
		request[index + 4] = 'p'; request[index + 5] = 't';
		request[index + 6] = '-'; request[index + 7] = 'E';
		request[index + 8] = 'n'; request[index + 9] = 'c';
		request[index + 10] = 'o'; request[index + 11] = 'd';
		request[index + 12] = 'i'; request[index + 13] = 'n';
		request[index + 14] = 'g'; request[index + 15] = ':';
		request[index + 16] = ' '; request[index + 17] = 'g';
		request[index + 18] = 'z'; request[index + 19] = 'i';
		request[index + 20] = 'p'; request[index + 21] = '\r';
		request[index + 22] = '\n';
		index += 23;
	}

	request[index + 0] = 'C'; request[index + 1] = 'o';
	request[index + 2] = 'n'; request[index + 3] = 't';
	request[index + 4] = 'e'; request[index + 5] = 'n';
	request[index + 6] = 't'; request[index + 7] = '-';
	request[index + 8] = 'T'; request[index + 9] = 'y';
	request[index + 10] = 'p'; request[index + 11] = 'e';
	request[index + 12] = ':'; request[index + 13] = ' ';
	index += 14;

	if (isMultipart)
	{
		abort();
	}
	else
	{
		request[index + 0] = 'a'; request[index + 1] = 'p';
		request[index + 2] = 'p'; request[index + 3] = 'l';
		request[index + 4] = 'i'; request[index + 5] = 'c';
		request[index + 6] = 'a'; request[index + 7] = 't';
		request[index + 8] = 'i'; request[index + 9] = 'o';
		request[index + 10] = 'n'; request[index + 11] = '/';
		request[index + 12] = 'x'; request[index + 13] = '-';
		request[index + 14] = 'w'; request[index + 15] = 'w';
		request[index + 16] = 'w'; request[index + 17] = '-';
		request[index + 18] = 'f'; request[index + 19] = 'o';
		request[index + 20] = 'r'; request[index + 21] = 'm';
		request[index + 22] = '-'; request[index + 23] = 'u';
		request[index + 24] = 'r'; request[index + 25] = 'l';
		request[index + 26] = 'e'; request[index + 27] = 'n';
		request[index + 28] = 'c'; request[index + 29] = 'o';
		request[index + 30] = 'd'; request[index + 31] = 'e';
		request[index + 32] = 'd'; 	request[index + 33] = '\r';
		request[index + 34] = '\n';
		index += 35;
	}

	request[index + 0] = 'C'; request[index + 1] = 'o';
	request[index + 2] = 'n'; request[index + 3] = 't';
	request[index + 4] = 'e'; request[index + 5] = 'n';
	request[index + 6] = 't'; request[index + 7] = '-';
	request[index + 8] = 'L'; request[index + 9] = 'e';
	request[index + 10] = 'n'; request[index + 11] = 'g';
	request[index + 12] = 't'; request[index + 13] = 'h';
	request[index + 14] = ':'; request[index + 15] = ' ';
	index += 16;

	memcpy(request + index, clString,
		clStringLength * sizeof(char));
	index += clStringLength;

	request[index + 0] = '\r'; request[index + 1] = '\n';
	index += 2;

	for (size_t i = 0; i < headerCount; i++)
	{
		HttpPair header = headers[i];
		memcpy(request + index, header.key,
			header.keyLength * sizeof(char));
		index += header.keyLength;

		request[index + 0] = ':'; request[index + 1] = ' ';
		index += 2;

		memcpy(request + index, header.value,
			header.valueLength * sizeof(char));
		index += header.valueLength;

		request[index + 0] = '\r'; request[index + 1] = '\n';
		index += 2;
	}

	request[index + 0] = '\r'; request[index + 1] = '\n';
	index += 2;

	for (size_t i = 0; i < pairCount; i++)
	{
		HttpPair pair = pairs[i];
		memcpy(request + index, pair.key,
			pair.keyLength * sizeof(char));
		index += pair.keyLength;

		request[index++] = '=';

		memcpy(request + index, pair.value,
			pair.valueLength * sizeof(char));
		index += pair.valueLength;

		if (i < minPairCount)
			request[index++] = '&';
	}

	assert(index == requestLength);

	NetsResult netsResult = clearHttpClient(httpClient);

	if (netsResult != SUCCESS_NETS_RESULT)
		return netsResult;

	bool isAlreadyConnected = false;

	if (isStreamClientConnected(streamClient))
	{
		if (httpClient->lastHostnameLength != hostLength || memcmp(
			httpClient->lastHostname, host, hostLength * sizeof(char)) != 0)
		{
			disconnectStreamClient(streamClient);

			netsResult = connectHostnameStreamClient(
				streamClient,
				host,
				service ? service : "443",
				true);

			if (netsResult != SUCCESS_NETS_RESULT)
				return netsResult;

			setSocketNoDelay(
				getStreamClientSocket(streamClient),
				true);

			if (keepAlive)
			{
				char* hostname = malloc(
					(hostLength + 1) * sizeof(char));

				if (!hostname)
				{
					disconnectStreamClient(streamClient);
					return OUT_OF_MEMORY_NETS_RESULT;
				}

				free(httpClient->lastHostname);
				httpClient->lastHostname = hostname;
				httpClient->lastHostnameLength = hostLength;
				memcpy(hostname, host, hostLength * sizeof(char));
				hostname[hostLength] = '\0';
			}
		}
		else
		{
			isAlreadyConnected = true;
		}
	}
	else
	{
		netsResult = connectHostnameStreamClient(
			streamClient,
			host,
			service ? service : "443",
			true);

		if (netsResult != SUCCESS_NETS_RESULT)
			return netsResult;

		setSocketNoDelay(
			getStreamClientSocket(streamClient),
			true);

		if (keepAlive)
		{
			char* hostname = malloc(
				(hostLength + 1) * sizeof(char));

			if (!hostname)
			{
				disconnectStreamClient(streamClient);
				return OUT_OF_MEMORY_NETS_RESULT;
			}

			free(httpClient->lastHostname);
			httpClient->lastHostname = hostname;
			httpClient->lastHostnameLength = hostLength;
			memcpy(hostname, host, hostLength * sizeof(char));
			hostname[hostLength] = '\0';
		}
	}

	resetStreamClientTimeout(streamClient);

	netsResult = streamClientSend(
		streamClient,
		request,
		requestLength);

	if (netsResult != SUCCESS_NETS_RESULT)
	{
		if (isAlreadyConnected)
		{
			disconnectStreamClient(streamClient);

			netsResult = connectHostnameStreamClient(
				streamClient,
				host,
				service ? service : "443",
				true);

			if (netsResult != SUCCESS_NETS_RESULT)
				return netsResult;

			setSocketNoDelay(
				getStreamClientSocket(streamClient),
				true);

			netsResult = streamClientSend(
				streamClient,
				request,
				requestLength);

			if (netsResult != SUCCESS_NETS_RESULT)
			{
				disconnectStreamClient(streamClient);
				return netsResult;
			}
		}
		else
		{
			disconnectStreamClient(streamClient);
			return netsResult;
		}
	}

	while (httpClient->isRunning)
	{
		netsResult = updateStreamClient(streamClient);

		if (netsResult == SUCCESS_NETS_RESULT)
			continue;

		if (netsResult != IN_PROGRESS_NETS_RESULT)
		{
			disconnectStreamClient(streamClient);
			return netsResult;
		}

		sleepThread(0.001);
	}

	if (!keepAlive)
		disconnectStreamClient(streamClient);

	return httpClient->result;
}

const HttpPair* getHttpClientHeader(
	HttpClient httpClient,
	const char* key,
	int length)
{
	assert(httpClient);
	assert(key);
	assert(length > 0);

	HttpPair searchHeader = {
		key, NULL,
		length, 0,
	};

	return bsearch(
		&searchHeader,
		httpClient->headers,
		httpClient->headerCount,
		sizeof(HttpPair),
		cmpHttpHeaders);
}