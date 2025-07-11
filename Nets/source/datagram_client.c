#include "nets/datagram_client.h"

struct DatagramClient_T
{
	size_t bufferSize;
	OnDatagramClientReceive onReceive;
	void* handle;
	uint8_t* buffer;
	Socket socket;
};

NetsResult createDatagramClient(
	SocketAddress remoteAddress,
	size_t bufferSize,
	OnDatagramClientReceive onReceive,
	void* handle,
	DatagramClient* datagramClient)
{
	assert(remoteAddress);
	assert(bufferSize > 0);
	assert(onReceive);
	assert(datagramClient);

	DatagramClient datagramClientInstance = calloc(
		1, sizeof(DatagramClient_T));

	if (!datagramClientInstance)
		return OUT_OF_MEMORY_NETS_RESULT;

	datagramClientInstance->onReceive = onReceive;
	datagramClientInstance->handle = handle;

	uint8_t* buffer = malloc(
		bufferSize * sizeof(uint8_t));

	if (!buffer)
	{
		destroyDatagramClient(datagramClientInstance);
		return OUT_OF_MEMORY_NETS_RESULT;
	}

	datagramClientInstance->buffer = buffer;
	datagramClientInstance->bufferSize = bufferSize;

	uint8_t addressFamily =
		getSocketAddressFamily(remoteAddress);

	SocketAddress socketAddress;

	NetsResult netsResult = createAnySocketAddress(
		addressFamily,
		&socketAddress);

	if (netsResult != SUCCESS_NETS_RESULT)
	{
		destroyDatagramClient(datagramClientInstance);
		return netsResult;
	}

	Socket socket;

	netsResult = createSocket(
		DATAGRAM_SOCKET_TYPE,
		addressFamily,
		socketAddress,
		false,
		false,
		NULL,
		&socket);

	destroySocketAddress(socketAddress);

	if (netsResult != SUCCESS_NETS_RESULT)
	{
		destroyDatagramClient(datagramClientInstance);
		return netsResult;
	}

	datagramClientInstance->socket = socket;

	netsResult = connectSocket(
		socket,
		remoteAddress);

	if (netsResult != SUCCESS_NETS_RESULT)
	{
		destroyDatagramClient(datagramClientInstance);
		return netsResult;
	}

	*datagramClient = datagramClientInstance;
	return SUCCESS_NETS_RESULT;
}
void destroyDatagramClient(DatagramClient datagramClient)
{
	if (!datagramClient)
		return;

	Socket socket = datagramClient->socket;

	if (socket)
	{
		shutdownSocket(socket, RECEIVE_SEND_SOCKET_SHUTDOWN);
		destroySocket(socket);
	}

	free(datagramClient->buffer);
	free(datagramClient);
}

size_t getDatagramClientBufferSize(DatagramClient datagramClient)
{
	assert(datagramClient);
	return datagramClient->bufferSize;
}
OnDatagramClientReceive getDatagramClientOnReceive(DatagramClient datagramClient)
{
	assert(datagramClient);
	return datagramClient->onReceive;
}
void* getDatagramClientHandle(DatagramClient datagramClient)
{
	assert(datagramClient);
	return datagramClient->handle;
}
uint8_t* getDatagramClientBuffer(DatagramClient datagramClient)
{
	assert(datagramClient);
	return datagramClient->buffer;
}
Socket getDatagramClientSocket(DatagramClient datagramClient)
{
	assert(datagramClient);
	return datagramClient->socket;
}

NetsResult updateDatagramClient(DatagramClient datagramClient)
{
	assert(datagramClient);

	uint8_t* receiveBuffer = datagramClient->buffer;
	size_t byteCount;

	NetsResult netsResult = socketReceive(
		datagramClient->socket,
		receiveBuffer,
		datagramClient->bufferSize,
		&byteCount);

	if (netsResult != SUCCESS_NETS_RESULT)
		return netsResult;

	datagramClient->onReceive(
		datagramClient,
		receiveBuffer,
		byteCount);
	return SUCCESS_NETS_RESULT;
}

NetsResult datagramClientSend(
	DatagramClient datagramClient,
	const void* sendBuffer,
	size_t byteCount)
{
	assert(datagramClient);
	assert(sendBuffer);
	assert(byteCount > 0);

	return socketSend(
		datagramClient->socket,
		sendBuffer,
		byteCount);
}