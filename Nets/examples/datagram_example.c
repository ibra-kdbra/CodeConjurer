#include "nets/datagram_server.h"
#include "nets/datagram_client.h"

#include "mpmt/thread.h"
#include <stdio.h>

#define SERVER_PORT "12345"
#define RECEIVE_BUFFER_SIZE 4

typedef struct Server
{
	DatagramServer server;
	Thread thread;
	volatile bool isRunning;
} Server;

typedef struct Client
{
	DatagramClient client;
	Thread thread;
	volatile bool isRunning;
} Client;

static void onServerReceive(
	DatagramServer server,
	SocketAddress address,
	const uint8_t* buffer,
	size_t byteCount)
{
	if (byteCount != 1)
	{
		printf("[SERVER]: Incorrect datagram size. "
			"(%zu)\n", byteCount);
		fflush(stdout);
		return;
	}

	printf("[SERVER]: Received request. "
		"(value: %hhu)\n", buffer[0]);
	fflush(stdout);

	NetsResult netsResult = datagramServerSend(
		server,
		buffer,
		1,
		address);

	if (netsResult != SUCCESS_NETS_RESULT)
	{
		printf("[SERVER]: Failed to send response. (error: %s)\n",
			netsResultToString(netsResult));
		fflush(stdout);
	}
}
static void serverHandler(void* argument)
{
#if __linux__ || __APPLE__
	disableSigpipe();
#endif

	Server* server = (Server*)argument;

	while (server->isRunning)
	{
		NetsResult netsResult = updateDatagramServer(
			server->server);

		if (netsResult != SUCCESS_NETS_RESULT)
			sleepThread(0.001);
	}
}

inline static Server* createServer()
{
	Server* server = malloc(sizeof(Server));

	if (server == NULL)
		return NULL;

	DatagramServer datagramServer;

	NetsResult netsResult = createDatagramServer(
		IP_V4_ADDRESS_FAMILY,
		SERVER_PORT,
		RECEIVE_BUFFER_SIZE,
		onServerReceive,
		NULL,
		&datagramServer);

	if (netsResult != SUCCESS_NETS_RESULT)
	{
		printf("Failed to create datagram server. (error: %s)\n",
			netsResultToString(netsResult));
		free(server);
		return NULL;
	}

	server->server = datagramServer;
	server->isRunning = true;

	Thread thread = createThread(
		serverHandler,
		server);

	if (thread == NULL)
	{
		printf("Failed to create server thread.\n");
		destroyDatagramServer(datagramServer);
		free(server);
		return NULL;
	}

	server->thread = thread;
	return server;
}
inline static void destroyServer(Server* server)
{
	if (server == NULL)
		return;

	server->isRunning = false;
	joinThread(server->thread);
	destroyThread(server->thread);
	destroyDatagramServer(server->server);
	free(server);
}

static void onClientReceive(
	DatagramClient client,
	const uint8_t* buffer,
	size_t byteCount)
{
	if (byteCount != 1)
	{
		printf("[CLIENT]: Incorrect datagram size. "
			"(%zu).\n", byteCount);
		fflush(stdout);
		return;
	}

	printf("[CLIENT]: Received response. "
		"(value: %hhu).\n", buffer[0]);
	fflush(stdout);
}
static void clientHandler(void* argument)
{
#if __linux__ || __APPLE__
	disableSigpipe();
#endif

	Client* client = (Client*)argument;

	while (client->isRunning)
	{
		NetsResult netsResult = updateDatagramClient(
			client->client);

		if (netsResult == SUCCESS_NETS_RESULT)
		{
			continue;
		}
		else if (netsResult == IN_PROGRESS_NETS_RESULT)
		{
			sleepThread(0.001);
			continue;
		}

		printf("[CLIENT]: Failed to update client. (error: %s)\n",
			netsResultToString(netsResult));
		fflush(stdout);
		client->isRunning = false;
		return;
	}
}

inline static Client* createClient()
{
	Client* client = malloc(sizeof(Client));

	if (client == NULL)
		return NULL;

	SocketAddress remoteAddress;

	NetsResult netsResult = createSocketAddress(
		LOOPBACK_IP_ADDRESS_V4,
		SERVER_PORT,
		&remoteAddress);

	if (netsResult != SUCCESS_NETS_RESULT)
	{
		printf("Failed to create client socket address. (error: %s)\n",
			netsResultToString(netsResult));
		free(client);
		return NULL;
	}

	DatagramClient datagramClient;

	netsResult = createDatagramClient(
		remoteAddress,
		RECEIVE_BUFFER_SIZE,
		onClientReceive,
		NULL,
		&datagramClient);

	destroySocketAddress(remoteAddress);

	if (netsResult != SUCCESS_NETS_RESULT)
	{
		printf("Failed to create datagram client. (error: %s)\n",
			netsResultToString(netsResult));
		free(client);
		return NULL;
	}

	client->client = datagramClient;
	client->isRunning = true;

	Thread thread = createThread(
		clientHandler,
		client);

	if (thread == NULL)
	{
		printf("Failed to create client thread.\n");
		destroyDatagramClient(datagramClient);
		free(client);
		return NULL;
	}

	client->thread = thread;
	return client;
}
inline static void destroyClient(Client* client)
{
	if (client == NULL)
		return;

	client->isRunning = false;
	joinThread(client->thread);
	destroyThread(client->thread);
	destroyDatagramClient(client->client);
	free(client);
}

int main()
{
	if (initializeNetwork() == false)
	{
		printf("Failed to initialize network.\n");
		return EXIT_FAILURE;
	}

	Server* server = createServer();

	if (server == NULL)
	{
		terminateNetwork();
		return EXIT_FAILURE;
	}

	Client* client = createClient();

	if (client == NULL)
	{
		destroyServer(server);
		terminateNetwork();
		return EXIT_FAILURE;
	}

	uint8_t message = 1;

	NetsResult netsResult = datagramClientSend(
		client->client,
		&message,
		sizeof(uint8_t));

	if (netsResult != SUCCESS_NETS_RESULT)
	{
		printf("Failed to send client datagram. (error: %s)\n",
			netsResultToString(netsResult));
		destroyClient(client);
		destroyServer(server);
		terminateNetwork();
		return EXIT_FAILURE;
	}

	sleepThread(0.1);

	destroyClient(client);
	destroyServer(server);
	terminateNetwork();
	return EXIT_SUCCESS;
}