#pragma once
#include "nets/socket.h"

/*
 * Datagram server structure. (UDP)
 */
typedef struct DatagramServer_T DatagramServer_T;
/*
 * Datagram server instance. (UDP)
 */
typedef DatagramServer_T* DatagramServer;

/*
 * Datagram server receive function.
 *
 * datagramServer - datagram server instance.
 * remoteAddress - remote address instance.
 * receiveBuffer - receive buffer size.
 * byteCount - received byte count.
 */
typedef void(*OnDatagramServerReceive)(
	DatagramServer datagramServer,
	SocketAddress remoteAddress,
	const uint8_t* receiveBuffer,
	size_t byteCount);

/*
 * Create a new datagram server (UDP).
 * Returns operation Nets result.
 *
 * addressFamily - local socket address family.
 * service - local address service string.
 * bufferSize - data buffer size.
 * onReceive - datagram receive function.
 * handle - receive function argument.
 * datagramServer - pointer to the datagram server.
 */
NetsResult createDatagramServer(
	AddressFamily addressFamily,
	const char* service,
	size_t bufferSize,
	OnDatagramServerReceive onReceive,
	void* handle,
	DatagramServer* datagramServer);
/*
 * Destroys datagram server instance.
 * datagramServer - datagram server instance or NULL.
 */
void destroyDatagramServer(DatagramServer datagramServer);

/*
 * Returns datagram server data buffer size.
 * datagramServer - datagram server instance.
 */
size_t getDatagramServerBufferSize(DatagramServer datagramServer);
/*
 * Returns datagram server receive function.
 * datagramServer - datagram server instance.
 */
OnDatagramServerReceive getDatagramServerOnReceive(DatagramServer datagramServer);
/*
 * Returns datagram server handle.
 * datagramServer - datagram server instance.
 */
void* getDatagramServerHandle(DatagramServer datagramServer);
/*
 * Returns datagram server socket.
 * datagramServer - datagram server instance.
 */
Socket getDatagramServerSocket(DatagramServer datagramServer);
/*
 * Receive buffered datagrams.
 * Returns operation Nets result.
 *
 * datagramServer - datagram server instance.
 */
NetsResult updateDatagramServer(DatagramServer datagramServer);

/*
 * Send message to the specified address.
 * Returns operation Nets result.
 *
 * datagramServer - datagram server instance.
 * sendBuffer - datagram send buffer.
 * byteCount - send byte count.
 * remoteAddress - destination socket address.
 */
NetsResult datagramServerSend(
	DatagramServer datagramServer,
	const void* sendBuffer,
	size_t byteCount,
	SocketAddress remoteAddress);