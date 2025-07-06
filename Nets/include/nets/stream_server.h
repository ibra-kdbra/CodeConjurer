#pragma once
#include "nets/socket.h"

/*
 * Stream server structure. (TCP)
 */
typedef struct StreamServer_T StreamServer_T;
/*
 * Stream server instance. (TCP)
 */
typedef StreamServer_T* StreamServer;

/*
 * Stream server session structure. (TCP)
 */
typedef struct StreamSession_T StreamSession_T;
/*
 * Stream server session instance. (TCP)
 */
typedef StreamSession_T* StreamSession;

/*
 * Stream session create function.
 * Destroys socket on false return result.
 *
 * streamServer - stream server instance.
 * socket - a new accepted socket instance.
 * address - accepted socket address.
 * handle - pointer to the handle.
 */
typedef bool(*OnStreamSessionCreate)(
	StreamServer streamServer,
	StreamSession streamSession,
	void** handle);
/*
 * Stream session destroy function.
 *
 * streamServer - stream server instance.
 * streamSession - stream session instance.
 * netsResult - destruction reason.
 */
typedef void(*OnStreamSessionDestroy)(
	StreamServer streamServer,
	StreamSession streamSession,
	NetsResult netsResult);
/*
 * Stream session receive function
 * Destroys session on failure return result.
 *
 * streamServer - stream server instance.
 * streamSession - stream session instance.
 * receiveBuffer - receive buffer instance.
 * byteCount - received byte count.
 */
typedef NetsResult(*OnStreamSessionReceive)(
	StreamServer streamServer,
	StreamSession streamSession,
	const uint8_t* receiveBuffer,
	size_t byteCount);
/*
 * Stream session update function.
 * Destroys session on failure return result.
 *
 * streamServer - stream server instance.
 * streamSession - stream session instance.
 */
typedef NetsResult(*OnStreamSessionUpdate)(
	StreamServer streamServer,
	StreamSession streamSession);

/*
 * Create a new stream server instance (TCP).
 * Returns operation Nets result.
 *
 * addressFamily - local socket address family.
 * service - local address service string.
 * sessionBufferSize - session receive buffer size.
 * connectionQueueSize - pending connections queue size.
 * dataBufferSize - data buffer size.
 * timeoutTime - session timeout time. (seconds)
 * onCreate - session create function.
 * onDestroy - session destroy function.
 * onReceive - data receive function.
 * onUpdate - session update function.
 * handle - receive function argument.
 * sslContext - SSL context or NULL.
 * streamServer - pointer to the stream server.
 */
NetsResult createStreamServer(
	AddressFamily addressFamily,
	const char* service,
	size_t sessionBufferSize,
	size_t connectionQueueSize,
	size_t dataBufferSize,
	double timeoutTime,
	OnStreamSessionCreate onCreate,
	OnStreamSessionDestroy onDestroy,
	OnStreamSessionReceive onReceive,
	OnStreamSessionUpdate onUpdate,
	void* handle,
	SslContext sslContext,
	StreamServer* streamServer);
/*
 * Destroys stream server instance.
 * streamServer - stream server instance or NULL.
 */
void destroyStreamServer(StreamServer streamServer);

/*
 * Returns stream server session buffer size.
 * streamServer - stream server instance.
 */
size_t getStreamServerSessionBufferSize(StreamServer streamServer);
/*
 * Returns stream server data buffer size.
 * streamServer - stream server instance.
 */
size_t getStreamServerDataBufferSize(StreamServer streamServer);
/*
 * Returns stream server create function.
 * streamServer - stream server instance.
 */
OnStreamSessionCreate getStreamServerOnCreate(StreamServer streamServer);
/*
 * Returns stream server destroy function.
 * streamServer - stream server instance.
 */
OnStreamSessionDestroy getStreamServerOnDestroy(StreamServer streamServer);
/*
 * Returns stream server receive function.
 * streamServer - stream server instance.
 */
OnStreamSessionReceive getStreamServerOnReceive(StreamServer streamServer);
/*
 * Returns stream server update function.
 * streamServer - stream server instance.
 */
OnStreamSessionUpdate getStreamServerOnUpdate(StreamServer streamServer);
/*
 * Returns stream server session timeout time. (seconds)
 * streamServer - stream server instance.
 */
double getStreamServerTimeoutTime(StreamServer streamServer);
/*
 * Returns stream server handle.
 * streamServer - stream server instance.
 */
void* getStreamServerHandle(StreamServer streamServer);
/*
 * Returns stream server data buffer.
 * streamServer - stream server instance.
 */
uint8_t* getStreamServerDataBuffer(StreamServer streamServer);
/*
 * Returns stream server socket.
 * streamServer - stream server instance.
 */
Socket getStreamServerSocket(StreamServer streamServer);
/*
 * Returns stream session socket.
 * streamSession - stream session instance.
 */
Socket getStreamSessionSocket(StreamSession streamSession);
/*
 * Returns stream session socket address.
 * streamSession - stream session instance.
 */
SocketAddress getStreamSessionAddress(StreamSession streamSession);
/*
 * Returns stream session handle.
 * streamSession - stream session instance.
 */
void* getStreamSessionHandle(StreamSession streamSession);

/*
 * Update stream server sessions.
 * Returns true if update actions occurred.
 *
 * streamServer - stream server instance.
 */
bool updateStreamServer(StreamServer streamServer);

/*
 * Send data to the specified session.
 * Returns operation Nets result.
 *
 * streamSession - stream session instance.
 * sendBuffer - data send buffer.
 * byteCount - send byte count.
 */
NetsResult streamSessionSend(
	StreamSession streamSession,
	const void* sendBuffer,
	size_t byteCount);
/*
 * Send stream message to the specified session.
 * Returns operation Nets result.
 *
 * streamSession - stream session instance.
 * sendBuffer - send stream message.
 */
NetsResult streamSessionSendMessage(
	StreamSession streamSession,
	StreamMessage streamMessage);