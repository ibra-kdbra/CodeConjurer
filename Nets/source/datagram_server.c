#include "nets/datagram_server.h"

struct DatagramServer_T
{
	size_t bufferSize;
	OnDatagramServerReceive onReceive;
	void* handle;
	uint8_t* buffer;
	SocketAddress address;
	Socket socket;
};

NetsResult createDatagramServer(
	AddressFamily addressFamily,
	const char* service,
	size_t bufferSize,
	OnDatagramServerReceive onReceive,
	void* handle,
	DatagramServer* datagramServer)
{
	assert(addressFamily < ADDRESS_FAMILY_COUNT);
	assert(service);
	assert(bufferSize > 0);
	assert(onReceive);
	assert(datagramServer);

	DatagramServer datagramServerInstance = calloc(
		1, sizeof(DatagramServer_T));

	if (!datagramServerInstance)
		return OUT_OF_MEMORY_NETS_RESULT;

	datagramServerInstance->onReceive = onReceive;
	datagramServerInstance->handle = handle;

	uint8_t* receiveBuffer = malloc(
		bufferSize * sizeof(uint8_t));

	if (!receiveBuffer)
	{
		destroyDatagramServer(datagramServerInstance);
		return OUT_OF_MEMORY_NETS_RESULT;
	}

	datagramServerInstance->buffer = receiveBuffer;
	datagramServerInstance->bufferSize = bufferSize;

	SocketAddress socketAddress;

	NetsResult netsResult = createSocketAddress(
		addressFamily == IP_V4_ADDRESS_FAMILY ?
			ANY_IP_ADDRESS_V4 : ANY_IP_ADDRESS_V6,
		service,
		&socketAddress);

	if (netsResult != SUCCESS_NETS_RESULT)
	{
		destroyDatagramServer(datagramServerInstance);
		return netsResult;
	}

	datagramServerInstance->address = socketAddress;

	Socket socket;

	netsResult = createSocket(
		DATAGRAM_SOCKET_TYPE,
		addressFamily,
		socketAddress,
		false,
		false,
		NULL,
		&socket);

	if (netsResult != SUCCESS_NETS_RESULT)
	{
		destroyDatagramServer(datagramServerInstance);
		return netsResult;
	}

	datagramServerInstance->socket = socket;

	*datagramServer = datagramServerInstance;
	return SUCCESS_NETS_RESULT;
}
void destroyDatagramServer(DatagramServer datagramServer)
{
	if (!datagramServer)
		return;

	Socket socket = datagramServer->socket;

	if (socket)
	{
		shutdownSocket(socket, RECEIVE_SEND_SOCKET_SHUTDOWN);
		destroySocket(socket);
	}

	destroySocketAddress(datagramServer->address);
	free(datagramServer->buffer);
	free(datagramServer);
}

size_t getDatagramServerReceiveBufferSize(DatagramServer datagramServer)
{
	assert(datagramServer);
	return datagramServer->bufferSize;
}
OnDatagramServerReceive getDatagramServerOnReceive(DatagramServer datagramServer)
{
	assert(datagramServer);
	return datagramServer->onReceive;
}
void* getDatagramServerHandle(DatagramServer datagramServer)
{
	assert(datagramServer);
	return datagramServer->handle;
}
Socket getDatagramServerSocket(DatagramServer datagramServer)
{
	assert(datagramServer);
	return datagramServer->socket;
}

NetsResult updateDatagramServer(DatagramServer datagramServer)
{
	assert(datagramServer);

	uint8_t* receiveBuffer = datagramServer->buffer;
	size_t byteCount;

	NetsResult netsResult = socketReceiveFrom(
		datagramServer->socket,
		datagramServer->address,
		receiveBuffer,
		datagramServer->bufferSize,
		&byteCount);

	if (netsResult != SUCCESS_NETS_RESULT)
		return netsResult;

	datagramServer->onReceive(
		datagramServer,
		datagramServer->address,
		receiveBuffer,
		byteCount);
	return SUCCESS_NETS_RESULT;
}

NetsResult datagramServerSend(
	DatagramServer datagramServer,
	const void* sendBuffer,
	size_t byteCount,
	SocketAddress remoteAddress)
{
	assert(datagramServer);
	assert(sendBuffer);
	assert(byteCount > 0);
	assert(remoteAddress);

	return socketSendTo(
		datagramServer->socket,
		sendBuffer,
		byteCount,
		remoteAddress);
}