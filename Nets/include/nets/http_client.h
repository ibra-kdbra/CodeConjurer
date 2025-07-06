#pragma once
#include "nets/stream_client.h"

// ================================================
// Note: this is simple HTTP client implementation.
// ================================================

// TODO: add Brotli compression support

/*
 * HTTP client structure.
*/
typedef struct HttpClient_T HttpClient_T;
/*
 * HTTP client instance.
*/
typedef HttpClient_T* HttpClient;

/*
 * HTTP key value pair structure.
 */
typedef struct HttpPair
{
	const char* key;
	const char* value;
	int keyLength;
	int valueLength;
} HttpPair;

/*
 * Create a new HTTP client instance.
 * Returns operation Nets result.
 *
 * dataBufferSize - data buffer size.
 * responseBufferSize - HTTP response buffer size.
 * headerBufferSize - HTTP header buffer size.
 * timeoutTime - time out time. (seconds)
 * useCompression - accept compressed response.
 * sslContext - SSL context instance or NULL.
 * httpClient - pointer to the HTTP client.
 */
NetsResult createHttpClient(
	size_t dataBufferSize,
	size_t responseBufferSize,
	size_t headerBufferSize,
	double timeoutTime,
	bool useCompression,
	SslContext sslContext,
	HttpClient* httpClient);
void destroyHttpClient(HttpClient httpClient);

/*
 * Returns HTTP client response buffer size.
 * httpClient - HTTP client instance.
 */
size_t getHttpResponseBufferSize(HttpClient httpClient);
/*
 * Returns HTTP client header buffer size.
 * httpClient - HTTP client instance.
 */
size_t getHttpHeaderBufferSize(HttpClient httpClient);
/*
 * Returns HTTP client stream.
 * httpClient - HTTP client instance.
 */
StreamClient getHttpClientStream(HttpClient httpClient);
/*
 * Returns true if HTTP client uses compression.
 * httpClient - HTTP client instance.
 */
bool isHttpClientUseCompression(HttpClient httpClient);
/*
 * Returns HTTP client status code.
 * httpClient - HTTP client instance.
 */
int getHttpClientStatusCode(HttpClient httpClient);
/*
 * Returns HTTP client server response.
 * httpClient - HTTP client instance.
 */
const char* getHttpClientResponse(HttpClient httpClient);
/*
 * Returns HTTP client server response length.
 * httpClient - HTTP client instance.
 */
size_t getHttpClientResponseLength(HttpClient httpClient);
/*
 * Returns HTTP client server response headers.
 * httpClient - HTTP client instance.
 */
const HttpPair* getHttpClientHeaders(HttpClient httpClient);
/*
 * Returns HTTP client server response headers count.
 * httpClient - HTTP client instance.
 */
size_t getHttpClientHeaderCount(HttpClient httpClient);

/*
 * Send HTTP GET request to the server.
 * Returns operation Nets result.
 *
 * httpClient - HTTP client instance.
 * url - URL string.
 * urlLength - URL string length
 * headers - HTTP headers or NULL.
 * headerCount - HTTP header count or 0.
 * keepAlive - keep connection alice. (speedup)
 */
NetsResult httpClientSendGET(
	HttpClient httpClient,
	const char* url,
	size_t urlLength,
	const HttpPair* headers,
	size_t headerCount,
	bool keepAlive);
/*
 * Send HTTP POST request to the server.
 * Returns operation Nets result.
 *
 * httpClient - HTTP client instance.
 * url - URL string.
 * urlLength - URL string length
 * pairs - key/value pairs.
 * pairCount -key/value pair count.
 * headers - HTTP headers or NULL.
 * headerCount - HTTP header count or 0.
 * isMultipart - use for binary values.
 * keepAlive - keep connection alice. (speedup)
 */
NetsResult httpClientSendPOST(
	HttpClient httpClient,
	const char* url,
	size_t urlLength,
	const HttpPair* pairs,
	size_t pairCount,
	const HttpPair* headers,
	size_t headerCount,
	bool isMultipart,
	bool keepAlive);

/*
 * Returns HTTP client header
 * on success, otherwise NULL.
 *
 * httpClient - HTTP client instance.
 * key - header key string.
 * length - key string length.
 */
const HttpPair* getHttpClientHeader(
	HttpClient httpClient,
	const char* key,
	int length);

/*
 * Encode URL string.
 * Returns encoded string length on success, otherwise 0.
 *
 * string - source string.
 * stringLength - source string length.
 * buffer - encoded string buffer.
 * bufferSize - encoded string buffer size.
 */
inline static size_t encodeUrl(
	const char* string,
	size_t stringLength,
	char* buffer,
	size_t bufferSize)
{
	assert(string);
	assert(stringLength > 0);
	assert(buffer);
	assert(bufferSize > 0);
	assert(stringLength <= bufferSize);

	const char hexChars[16] = {
		'0', '1', '2', '3', '4',
		'5', '6', '7', '8', '9',
		'A', 'B', 'C', 'D', 'E', 'F',
	};

	const uint8_t* array = (const uint8_t*)string;
	size_t index = 0;

	for (size_t i = 0; i < stringLength; i++)
	{
		uint8_t value = array[i];

		if ((value > '/' && value < ':') ||
			(value > '@' && value < '[') ||
			(value > '`' && value < '{') ||
			value == '-' || value == '.' || value == '_')
		{
			if (index == bufferSize)
				return 0;

			buffer[index++] = (char)value;
		}
		else
		{
			if (index + 3 > bufferSize)
				return 0;

			buffer[index + 0] = '%';
			buffer[index + 1] = hexChars[(value >> 4u) & 15u];
			buffer[index + 2] = hexChars[value & 15u];
			index += 3;
		}
	}

	if (index == bufferSize)
		return 0;

	buffer[index] = '\0';
	return index;
}
/*
 * Decode URL string.
 * Returns decoded string length on success, otherwise 0.
 *
 * string - encoded string.
 * stringLength - encoded string length.
 * buffer - decoded string buffer.
 */
inline static size_t decodeUrl(
	const char* string,
	size_t stringLength,
	char* buffer)
{
	const uint8_t* inputArray = (const uint8_t*)string;
	uint8_t* outputArray = (uint8_t*)buffer;
	size_t size = 0, index = 0;

	while (index < stringLength)
	{
		char* pointer = memchr(
			string + index,
			'%',
			stringLength - index);

		if (!pointer)
			return 0;

		size_t newIndex = pointer - string;

		if (newIndex + 3 > stringLength)
			return 0;

		size_t copySize = newIndex - index;
		memcpy(buffer + size, string + index,
			copySize * sizeof(char));
		index = newIndex;
		size += copySize;

		uint8_t value;
		uint8_t charValue = inputArray[index + 1];

		if (charValue > '/' && charValue < ':')
			value = (charValue - '0') << 4u;
		else if (charValue > '@' && charValue < 'G')
			value = (charValue - '7') << 4u;
		else
			return 0;

		charValue = inputArray[index + 2];

		if (charValue > '/' && charValue < ':')
			value |= charValue - '0';
		else if (charValue > '@' && charValue < 'G')
			value |= charValue - '7';
		else
			return 0;

		outputArray[size++] = value;
		index += 3;
	}

	return size;
}