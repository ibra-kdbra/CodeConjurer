
#include "nets/http_client.h"
#include <stdio.h>

#define DATA_BUFFER_SIZE 2048
#define RESPONSE_BUFFER_SIZE 65536
#define HEADER_BUFFER_SIZE 16
#define TIMEOUT_TIME 2.0
#define REQUEST_URL "www.google.com"

int main()
{
	#if NETS_SUPPORT_OPENSSL
	if (initializeNetwork() == false)
	{
		printf("Failed to initialize network.\n");
		return EXIT_FAILURE;
	}

	SslContext sslContext;

	NetsResult netsResult = createPublicSslContext(
		TLS_SECURITY_PROTOCOL,
		NULL,
		NULL,
		&sslContext);

	if (netsResult != SUCCESS_NETS_RESULT)
	{
		printf("Failed to create SSL context. (error: %s)\n",
			netsResultToString(netsResult));
		terminateNetwork();
		return EXIT_FAILURE;
	}

	HttpClient httpClient;

	netsResult = createHttpClient(
		DATA_BUFFER_SIZE,
		RESPONSE_BUFFER_SIZE,
		HEADER_BUFFER_SIZE,
		TIMEOUT_TIME,
		true,
		sslContext,
		&httpClient);

	if (netsResult != SUCCESS_NETS_RESULT)
	{
		printf("Failed to create HTTP client. (error: %s)\n",
			netsResultToString(netsResult));
		destroySslContext(sslContext);
		terminateNetwork();
		return EXIT_FAILURE;
	}

	netsResult = httpClientSendGET(
		httpClient,
		REQUEST_URL,
		strlen(REQUEST_URL),
		NULL,
		0,
		false);

	if (netsResult != SUCCESS_NETS_RESULT)
	{
		printf("Failed to get page. (error: %s)\n",
			netsResultToString(netsResult));
		destroyHttpClient(httpClient);
		destroySslContext(sslContext);
		terminateNetwork();
		return EXIT_FAILURE;
	}

	printf("RESPONSE:\n\n%.*s",
		(int)getHttpClientResponseLength(httpClient),
		getHttpClientResponse(httpClient));

	destroyHttpClient(httpClient);
	destroySslContext(sslContext);
	terminateNetwork();
	#endif

	return EXIT_SUCCESS;
}