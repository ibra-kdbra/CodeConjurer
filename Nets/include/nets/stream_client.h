#pragma once
#include "nets/socket.h"

/*
 * Stream client structure. (TCP)
*/
typedef struct StreamClient_T StreamClient_T;
/*
 * Stream client instance. (TCP)
*/
typedef StreamClient_T* StreamClient;

/*
 * Stream client receive function.
 *
 * streamClient - stream client instance.
 * receiveBuffer - receive buffer instance.
 * byteCount - received byte count.
 */
typedef void(*OnStreamClientReceive)(
	StreamClient streamClient,
	const uint8_t* receiveBuffer,
	size_t byteCount);

/*
 * Create a new stream client instance (TCP).
 * Returns operation Nets result.
 *
 * bufferSize - data buffer size.
 * timeoutTime - time out time. (seconds)
 * onReceive - data receive function.
 * handle - receive function argument.
 * sslContext - SSL context instance or NULL.
 * streamClient - pointer to the stream client.
 */
NetsResult createStreamClient(
	size_t bufferSize,
	double timeoutTime,
	OnStreamClientReceive onReceive,
	void* handle,
	SslContext sslContext,
	StreamClient* streamClient);
/*
 * Destroys stream client instance.
 * streamClient - stream client instance or NULL.
 */
void destroyStreamClient(StreamClient streamClient);

/*
* Returns stream client data buffer size.
* streamClient - stream client instance.
*/
size_t getStreamClientBufferSize(StreamClient streamClient);
/*
* Returns stream client receive function.
* streamClient - stream client instance.
*/
OnStreamClientReceive getStreamClientOnReceive(StreamClient streamClient);
/*
 * Returns stream client handle.
 * streamClient - stream client instance.
 */
void* getStreamClientHandle(StreamClient streamClient);
/*
 * Returns stream client data buffer.
 * streamClient - stream client instance.
 */
uint8_t* getStreamClientBuffer(StreamClient streamClient);
/*
 * Returns stream client socket.
 * streamClient - stream client instance.
 */
Socket getStreamClientSocket(StreamClient streamClient);

/*
 * Returns stream client timeout time. (seconds)
 * streamClient - stream client instance.
 */
double getStreamClientTimeoutTime(
	StreamClient streamClient);
/*
 * Sets stream client timeout time. (seconds)
 *
 * streamClient - stream client instance.
 * timeoutTime - timeout time value.
 */
void setStreamClientTimeoutTime(
	StreamClient streamClient,
	double timeoutTime);

/*
 * Returns stream client SSL context.
 * streamClient - stream client instance.
 */
SslContext getStreamClientSslContext(
	StreamClient streamClient);
/*
 * Sets stream client SSL context.
 *
 * streamClient - stream client instance.
 * sslContext - SSL context instance or NULL.
 */
void setStreamClientSslContext(
	StreamClient streamClient,
	SslContext sslContext);

/*
 * Returns true if stream client has been connected.
 * streamClient - stream client instance.
 */
bool isStreamClientConnected(StreamClient streamClient);
/*
 * Connect stream client to the server by address.
 * Returns operation Nets result.
 *
 * streamClient - stream client instance.
 * remoteAddress - remote socket address.
 * hostname - SNI hostname or NULL.
 */
NetsResult connectAddressStreamClient(
	StreamClient streamClient,
	SocketAddress remoteAddress,
	const char* hostname);
/*
 * Connect stream client to the server by hostname.
 * Returns operation Nets result.
 *
 * streamClient - stream client instance.
 * hostname - server hostname string.
 * service - server service string.
 * setSNI - set SNI hostname.
 */
NetsResult connectHostnameStreamClient(
	StreamClient streamClient,
	const char* hostname,
	const char* service,
	bool setSNI);
/*
 * Disconnect stream client from the server.
 * streamClient - stream client instance.
 */
void disconnectStreamClient(StreamClient streamClient);

/*
 * Receive buffered data.
 * Returns operation Nets result.
 *
 * streamClient - stream client instance.
 */
NetsResult updateStreamClient(StreamClient streamClient);
/*
 * Resets stream client response timeout counter.
 * streamClient - stream client instance.
 */
void resetStreamClientTimeout(StreamClient streamClient);

/*
 * Send data to the server.
 * Returns operation Nets result.
 *
 * streamClient - stream client instance.
 * sendBuffer - data send buffer.
 * byteCount - send byte count.
 */
NetsResult streamClientSend(
	StreamClient streamClient,
	const void* sendBuffer,
	size_t byteCount);

/*
 * Send stream message to the server.
 * Returns operation Nets result.
 *
 * streamClient - stream client instance.
 * sendBuffer - send stream message.
 */
NetsResult streamClientSendMessage(
	StreamClient streamClient,
	StreamMessage streamMessage);