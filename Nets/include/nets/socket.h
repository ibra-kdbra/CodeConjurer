#pragma once
#include "nets/defines.h"

#include <string.h>
#include <stdbool.h>

/*
 * Internet Protocol V4 any address.
 */
#define ANY_IP_ADDRESS_V4 "0.0.0.0"
/*
 * Internet Protocol V6 any address.
 */
#define ANY_IP_ADDRESS_V6 "::"

/*
 * Internet protocol V4 loopback address.
 */
#define LOOPBACK_IP_ADDRESS_V4 "127.0.0.1"
/*
 * Internet protocol V6 loopback address.
 */
#define LOOPBACK_IP_ADDRESS_V6 "::1"

/*
 * Current computer IP address.
 */
#define LOCALHOST_HOSTNAME "localhost"
/*
 * System-allocated, dynamic port.
 */
#define ANY_IP_ADDRESS_SERVICE "0"

/*
 * Maximum numeric host string length.
 */
#define MAX_NUMERIC_HOST_LENGTH 46
/*
 * Maximum numeric service string length.
 */
#define MAX_NUMERIC_SERVICE_LENGTH 6

/*
 * IPv4 address size in bytes.
 */
#define IP_V4_SIZE 4
/*
 * IPv6 address size in bytes.
 */
#define IP_V6_SIZE 16

/*
 * Socket structure.
 */
typedef struct Socket_T Socket_T;
/*
 * Socket instance.
 */
typedef Socket_T* Socket;

/*
 * Socket address structure.
 */
typedef struct SocketAddress_T SocketAddress_T;
/*
 * Socket address instance.
 */
typedef SocketAddress_T* SocketAddress;

/*
 * Secure socket layer context structure.
 */
typedef struct SslContext_T SslContext_T;
/*
 * Secure socket layer context instance.
 */
typedef SslContext_T* SslContext;

/*
 * Socket internet protocol address family.
 */
typedef enum AddressFamily_T
{
	IP_V4_ADDRESS_FAMILY = 0,
	IP_V6_ADDRESS_FAMILY = 1,
	ADDRESS_FAMILY_COUNT = 2,
} AddressFamily_T;
/*
 * Socket internet protocol address family type.
 */
typedef uint8_t AddressFamily;

/*
 * Socket communication type.
 */
typedef enum SocketType_T
{
	STREAM_SOCKET_TYPE = 0,
	DATAGRAM_SOCKET_TYPE = 1,
	SOCKET_TYPE_COUNT = 2,
} SocketType_T;
/*
 * Socket communication type.
 */
typedef uint8_t SocketType;

/*
 * Socket connection shutdown.
 */
typedef enum SocketShutdown_T
{
	RECEIVE_ONLY_SOCKET_SHUTDOWN = 0,
	SEND_ONLY_SOCKET_SHUTDOWN = 1,
	RECEIVE_SEND_SOCKET_SHUTDOWN = 2,
	SOCKET_SHUTDOWN_COUNT = 3,
} SocketShutdown_T;
/*
 * Socket connection shutdown type.
 */
typedef uint8_t SocketShutdown;

/*
 * Socket security protocol.
 */
typedef enum SecurityProtocol_T
{
	TLS_SECURITY_PROTOCOL = 0,
	TLS_1_2_SECURITY_PROTOCOL = 1,
	SECURITY_PROTOCOL_COUNT = 2,
} SecurityProtocol_T;
/*
 * Socket security protocol type.
 */
typedef uint8_t SecurityProtocol;

/*
 * Initialize network subsystems.
 * Returns true on success.
 */
bool initializeNetwork();
/*
 * Terminate network subsystems.
 */
void terminateNetwork();
/*
 * Returns true if network subsystems are initialized.
*/
bool isNetworkInitialized();

/*
 * Disable SIGPIPE signal generation. (Linux only)
 */
void disableSigpipe();

/*
 * Create a new socket instance.
 * Returns operation Nets result.
 *
 * socketType - socket communication type.
 * addressFamily - internet protocol address family.
 * socketAddress - socket local bind address.
 * isBlocking - socket in blocking mode.
 * isOnlyIPV6 - socket in IPv6 only mode.
 * sslContext - SSL context or NULL.
 * socket - pointer to the socket.
 */
NetsResult createSocket(
	SocketType socketType,
	AddressFamily addressFamily,
	SocketAddress socketAddress,
	bool isBlocking,
	bool isOnlyIPV6,
	SslContext sslContext,
	Socket* socket);
/*
 * Destroys socket instance.
 * socket - socket instance or NULL.
 */
void destroySocket(Socket socket);

/*
 * Returns socket connection type.
 * socket - socket instance.
 */
SocketType getSocketType(Socket socket);
/*
 * Returns socket address family type.
 * socket - socket instance.
 */
AddressFamily getSocketFamily(Socket socket);
/*
 * Returns true if socket is in blocking mode.
 * socket - socket instance.
 */
bool isSocketBlocking(Socket socket);
/*
 * Returns true if IPV6 socket is not accepting IPV4.
 * socket - socket instance.
 */
bool isSocketOnlyV6(Socket socket);
/*
 * Get local socket address.
 * Returns true on success.
 *
 * socket - socket instance.
 * socketAddress - socket address instance.
 */
bool getSocketLocalAddress(
	Socket socket,
	SocketAddress socketAddress);
/*
 * Get remote socket address.
 * Returns true on success.
 *
 * socket - socket instance.
 * socketAddress - socket address instance.
 */
bool getSocketRemoteAddress(
	Socket socket,
	SocketAddress socketAddress);
/*
 * Returns socket SSL context.
 * socket - socket instance.
 */
SslContext getSocketSslContext(Socket socket);

/*
 * Returns true if stream socket sends without caching.
 * socket - socket instance.
 */
bool isSocketNoDelay(
	Socket socket);
/*
 * Sets socket no delay mode.
 *
 * socket - socket instance.
 * value - no delay mode value.
 */
void setSocketNoDelay(
	Socket socket,
	bool value);

/*
 * Returns true if socket is in listening state.
 * socket - socket instance.
 */
bool isSocketListening(Socket socket);
/*
 * Maximum number of queued connections.
 */
size_t getMaxSocketQueueSize();
/*
 * Returns socket pending connections queue size.
 * socket - socket instance.
 */
size_t getSocketQueueSize(Socket socket);

/*
 * Put socket in a listening state.
 * Returns operation Nets result.
 *
 * socket - socket instance.
 * queueSize - pending connections queue size.
 */
NetsResult listenSocket(
	Socket socket,
	size_t queueSize);

/*
 * Accept a new socket connection.
 * Returns operation Nets result.
 *
 * socket - socket instance.
 * accepted - pointer to the accepted socket.
 */
NetsResult acceptSocket(
	Socket socket,
	Socket* accepted);
/*
 * Accept socket SSL connection.
 * Returns operation Nets result.
 *
 * socket - socket instance.
 */
NetsResult acceptSslSocket(Socket socket);

/*
 * Connect socket to the address.
 * Returns operation Nets result.
 *
 * socket - socket instance.
 * remoteAddress - remote address instance.
 */
NetsResult connectSocket(
	Socket socket,
	SocketAddress remoteAddress);
/*
 * Connect socket SSL.
 * Returns operation Nets result,
 *
 * socket - socket instance.
 * hostname - SNI hostname or NULL.
 */
NetsResult connectSslSocket(
	Socket socket,
	const char* hostname);

/*
 * Shutdown part of the full-duplex connection.
 * Returns operation Nets result.
 *
 * socket - socket instance.
 * shutdown - socket connection shutdown.
 */
NetsResult shutdownSocket(
	Socket socket,
	SocketShutdown shutdown);

/*
 * Receive socket message.
 * Returns operation Nets result.
 *
 * socket - socket instance.
 * receiveBuffer - message receive buffer.
 * bufferSize - message receive buffer size.
 * byteCount - pointer to the byte count.
 */
NetsResult socketReceive(
	Socket socket,
	void* receiveBuffer,
	size_t bufferSize,
	size_t* byteCount);
/*
 * Send socket message.
 * Returns operation Nets result.
 *
 * socket - socket instance.
 * sendBuffer - message send buffer.
 * byteCount - send byte count.
 */
NetsResult socketSend(
	Socket socket,
	const void* sendBuffer,
	size_t byteCount);
/*
 * Receive socket message from address.
 * Returns operation Nets result.
 *
 * socket - socket instance.
 * remoteAddress - remote socket address.
 * receiveBuffer - message receive buffer.
 * bufferSize - message receive buffer size.
 * byteCount - pointer to the byte count.
 */
NetsResult socketReceiveFrom(
	Socket socket,
	SocketAddress remoteAddress,
	void* receiveBuffer,
	size_t bufferSize,
	size_t* byteCount);
/*
 * Send socket message to the address.
 * Returns operation Nets result.
 *
 * socket - socket instance.
 * sendBuffer - message send buffer.
 * byteCount - message byte count to send.
 * socketAddress - remote socket address.
 */
NetsResult socketSendTo(
	Socket socket,
	const void* sendBuffer,
	size_t byteCount,
	SocketAddress remoteAddress);

// TODO: add async address resolve

/*
 * Create a new socket address.
 * Returns operation Nets result.
 *
 * host - address host name string.
 * service - address service name string.
 * socketAddress - pointer to the address.
 */
NetsResult createSocketAddress(
	const char* host,
	const char* service,
	SocketAddress* socketAddress);
/*
 * Create a new any socket address.
 * Returns operation Nets result.
 *
 * addressFamily - address family type.
 * socketAddress - pointer to the address.
 */
NetsResult createAnySocketAddress(
	AddressFamily addressFamily,
	SocketAddress* socketAddress);
/*
 * Create a new socket address copy.
 * Returns address on success, otherwise NULL.
 *
 * socketAddress - socket address instance.
 */
SocketAddress createSocketAddressCopy(SocketAddress socketAddress);
/*
 * Destroys socket address instance.
 * socketAddress - socket address or NULL.
 */
void destroySocketAddress(SocketAddress socketAddress);

/*
 * Resolve a new resolved socket address array.
 * Returns operation Nets result.
 *
 * host - address host name string.
 * service - address service name string.
 * family - socket address family.
 * type - socket connection type.
 * socketAddresses - pointer to the socket address array.
 * addressCount - pointer to the socket address count.
 */
NetsResult resolveSocketAddresses(
	const char* host,
	const char* service,
	AddressFamily family,
	SocketType type,
	SocketAddress** socketAddresses,
	size_t* addressCount);
/*
 * Destroys resolved socket address array.
 *
 * socketAddresses - socket address array instance.
 * addressCount - socket address count.
 */
void destroyResolvedSocketAddresses(
	SocketAddress* socketAddresses,
	size_t addressCount);

/*
 * Returns URL part locations.
 *
 * url - uniform resource locator string.
 * urlLength - URL string length.
 * hostOffset - pointer to the host part offset or NULL.
 * hostLength - pointer to the host part length or NULL.
 * serviceOffset - pointer to the service part offset or NULL.
 * serviceLength - pointer to the service part length or NULL.
 * pathOffset - pointer to the path part offset or NULL.
 */
void getUrlParts(
	const char* url,
	size_t urlLength,
	size_t* hostOffset,
	size_t* hostLength,
	size_t* serviceOffset,
	size_t* serviceLength,
	size_t* pathOffset);
// TODO: also return username, and parse URI format

/*
 * Copy source socket address to the destination.
 *
 * sourceAddress - socket address instance.
 * destinationAddress - socket address instance.
 */
void copySocketAddress(
	SocketAddress sourceAddress,
	SocketAddress destinationAddress);

/*
 * Compare two addresses.
 *
 * a - socket address instance.
 * b - socket address instance.
 */
int compareSocketAddress(
	SocketAddress a,
	SocketAddress b);

/*
 * Returns socket address family.
 * socketAddress - socket address instance.
 */
AddressFamily getSocketAddressFamily(
	SocketAddress socketAddress);
/*
 * Returns socket address family IP byte array size.
 * addressFamily - socket address family.
 */
size_t getSocketAddressFamilyIpSize(
	AddressFamily addressFamily);
/*
 * Returns socket IP address byte array size.
 * socketAddress - socket address instance.
 */
size_t getSocketAddressIpSize(
	SocketAddress socketAddress);

/*
 * Returns socket IP address byte array.
 * socketAddress - socket address instance.
 */
const uint8_t* getSocketAddressIp(
	SocketAddress socketAddress);
/*
 * Set socket IP address byte array.
 *
 * socketAddress - socket address instance.
 * ip - IP byte array.
 */
void setSocketAddressIp(
	SocketAddress socketAddress,
	const uint8_t* ip);

/*
 * Returns socket address port number.
 * socketAddress - socket address instance.
 */
uint16_t getSocketAddressPort(
	SocketAddress socketAddress);
/*
 * Set socket address port number.
 *
 * socketAddress - socket address instance.
 * port - socket address port.
 */
void setSocketAddressPort(
	SocketAddress socketAddress,
	uint16_t port);

/*
 * Get socket address host name.
 * Returns true on success.
 *
 * socketAddress - socket address instance.
 * host - pointer to the host name.
 * length - host name string length.
 */
bool getSocketAddressHost(
	SocketAddress socketAddress,
	char* host,
	size_t length);
/*
 * Returns socket address service name.
 * Returns true on success.
 *
 * socketAddress - socket address instance.
 * service - pointer to the service name.
 * length - service name string length.
 */
bool getSocketAddressService(
	SocketAddress socketAddress,
	char* service,
	size_t length);
/*
 * Get socket address host and service name.
 * Returns true on success.
 *
 * socketAddress - socket address instance.
 * host - pointer to the host name.
 * hostLength - host name string length.
 * service - pointer to the service name.
 * serviceLength - service name string length.
 */
bool getSocketAddressHostService(
	SocketAddress socketAddress,
	char* host,
	size_t hostLength,
	char* service,
	size_t serviceLength);

/*
 * Create a new public SSL context.
 * Returns operation Nets result.
 *
 * securityProtocol - security protocol type.
 * certificateFilePath - certificate file path string or NULL.
 * certificatesDirectory - certificate's directory path string or NULL.
 * sslContext - pointer to the SSL context.
 */
NetsResult createPublicSslContext(
	SecurityProtocol securityProtocol,
	const char* certificateFilePath,
	const char* certificatesDirectory,
	SslContext* sslContext);
/*
 * Create a new private SSL context.
 * Returns operation Nets result.
 *
 * securityProtocol - security protocol type.
 * certificateFilePath - certificates file path string.
 * privateKeyFilePath - private key file path string.
 * certificateChain - file path is certificate chain.
 * sslContext - pointer to the SSL context.
 */
NetsResult createPrivateSslContext(
	SecurityProtocol securityProtocol,
	const char* certificateFilePath,
	const char* privateKeyFilePath,
	bool certificateChain,
	SslContext* sslContext);

/*
 * Destroys SSL context instance.
 * sslContext - SSL context instance or NULL.
 */
void destroySslContext(SslContext sslContext);

/*
 * Returns SSL context security protocol.
 * sslContext - SSL context instance.
 */
SecurityProtocol getSslContextSecurityProtocol(SslContext sslContext);

/*
 * Splits and handles received stream data to the messages.
 * Returns operation Nets result.
 *
 * receiveBuffer - message receive buffer.
 * byteCount - message received byte count.
 * messageBuffer - receive message buffer.
 * messageBufferSiz - receive message buffer size.
 * messageByteCount - pointer to the message buffer byte count.
 * messageLengthSize - message length header size.
 * receiveFunction - pointer to the reception handler.
 * functionHandle - receive function handle or NULL.
 */
inline static NetsResult handleStreamMessage(
	const uint8_t* receiveBuffer,
	size_t byteCount,
	uint8_t* messageBuffer,
	size_t messageBufferSize,
	size_t* messageByteCount,
	uint8_t messageLengthSize,
	NetsResult(*receiveFunction)(
		const uint8_t*, size_t, void*),
	void* functionHandle)
{
	assert(receiveBuffer);
	assert(messageBuffer);
	assert(messageBufferSize > 0);
	assert(messageByteCount);

	assert(messageLengthSize == sizeof(uint8_t) ||
		messageLengthSize == sizeof(uint16_t) ||
		messageLengthSize == sizeof(uint32_t) ||
		messageLengthSize == sizeof(uint64_t));
	assert(messageBufferSize >= messageLengthSize);

	// Check instead of assert for safety
	if (byteCount == 0)
		return CONNECTION_IS_CLOSED_NETS_RESULT;

	size_t _messageByteCount = *messageByteCount;
	size_t pointer = 0;

	// Handle received data with buffered data
	if (_messageByteCount > 0)
	{
		// Message buffer has not full size
		if (_messageByteCount < messageLengthSize)
		{
			size_t messageSizePart = (size_t)
				messageLengthSize - _messageByteCount;

			// Received not full message size
			if (messageSizePart > byteCount)
			{
				// Store part of the received message size
				memcpy(messageBuffer + _messageByteCount,
					receiveBuffer, byteCount * sizeof(uint8_t));
				*messageByteCount += byteCount;
				return SUCCESS_NETS_RESULT;
			}

			// Copy remaining message size part
			memcpy(messageBuffer + _messageByteCount,
				receiveBuffer, messageSizePart * sizeof(uint8_t));
			pointer += messageSizePart;
			_messageByteCount += messageSizePart;
		}

		// Decode received message size
		uint64_t messageSize;

		if (messageLengthSize == sizeof(uint8_t))
		{
			messageSize = messageBuffer[0];
		}
		else if (messageLengthSize == sizeof(uint16_t))
		{
#if NETS_LITTLE_ENDIAN
			messageSize = *(uint16_t*)messageBuffer;
#else
			datagramSize = swapBytes16(*(uint16_t*)datagramBuffer);
#endif
		}
		else if (messageLengthSize == sizeof(uint32_t))
		{
#if NETS_LITTLE_ENDIAN
			messageSize = *(uint32_t*)messageBuffer;
#else
			datagramSize = swapBytes32(*(uint32_t*)datagramBuffer);
#endif
		}
		else if (messageLengthSize == sizeof(uint64_t))
		{
#if NETS_LITTLE_ENDIAN
			messageSize = *(uint64_t*)messageBuffer;
#else
			datagramSize = swapBytes64(*(uint64_t*)datagramBuffer);
#endif
		}
		else
		{
			abort();
		}

		// Received message is bigger than buffer
		if (messageSize > messageBufferSize - messageLengthSize)
			return OUT_OF_MEMORY_NETS_RESULT;

		size_t neededPartSize = messageSize -
			(_messageByteCount - messageLengthSize);

		// Received not full message
		if (neededPartSize > byteCount - pointer)
		{
			size_t messagePartSize = byteCount - pointer;

			memcpy(messageBuffer + _messageByteCount,
				receiveBuffer + pointer, messagePartSize * sizeof(uint8_t));
			*messageByteCount = _messageByteCount + messagePartSize;
			return SUCCESS_NETS_RESULT;
		}

		memcpy(messageBuffer + _messageByteCount,
			receiveBuffer + pointer, neededPartSize * sizeof(uint8_t));

		NetsResult netsResult = receiveFunction(
			messageBuffer + messageLengthSize,
			messageSize,
			functionHandle);

		if (netsResult != SUCCESS_NETS_RESULT)
			return netsResult;

		*messageByteCount = 0;
		pointer += neededPartSize;
	}

	// Continue until all received data handled
	while (pointer < byteCount)
	{
		// Received not full message size
		if (messageLengthSize > byteCount - pointer)
		{
			size_t messageSizePart = byteCount - pointer;

			memcpy(messageBuffer, receiveBuffer + pointer,
				messageSizePart * sizeof(uint8_t));
			*messageByteCount += messageSizePart;
			return SUCCESS_NETS_RESULT;
		}

		// Decode received message size
		uint64_t messageSize;

		if (messageLengthSize == sizeof(uint8_t))
		{
			messageSize = receiveBuffer[pointer];
		}
		else if (messageLengthSize == sizeof(uint16_t))
		{
#if NETS_LITTLE_ENDIAN
			messageSize = *(uint16_t*)(receiveBuffer + pointer);
#else
			datagramSize = swapBytes16(*(uint16_t*)(receiveBuffer + pointer));
#endif
		}
		else if (messageLengthSize == sizeof(uint32_t))
		{
#if NETS_LITTLE_ENDIAN
			messageSize = *(uint32_t*)(receiveBuffer + pointer);
#else
			datagramSize = swapBytes32(*(uint32_t*)(receiveBuffer + pointer));
#endif
		}
		else if (messageLengthSize == sizeof(uint64_t))
		{
#if NETS_LITTLE_ENDIAN
			messageSize = *(uint64_t*)(receiveBuffer + pointer);
#else
			datagramSize = swapBytes64(*(uint64_t*)(receiveBuffer + pointer));
#endif
		}
		else
		{
			abort();
		}

		// Received message is bigger than buffer
		if (messageSize > messageBufferSize - messageLengthSize)
			return OUT_OF_MEMORY_NETS_RESULT;

		// Received not full message
		if (messageSize > (byteCount - pointer) - messageLengthSize)
		{
			size_t messagePartSize = byteCount - pointer;

			memcpy(messageBuffer, receiveBuffer + pointer,
				messagePartSize * sizeof(uint8_t));
			*messageByteCount += messagePartSize;
			return SUCCESS_NETS_RESULT;
		}

		// Handle received message data
		NetsResult netsResult = receiveFunction(
			receiveBuffer + pointer + messageLengthSize,
			messageSize,
			functionHandle);

		if (netsResult != SUCCESS_NETS_RESULT)
			return netsResult;

		pointer += messageLengthSize + messageSize;
	}

	return SUCCESS_NETS_RESULT;
}

// For library symbols
NetsResult sHandleStreamMessage(
	const uint8_t* receiveBuffer,
	size_t byteCount,
	uint8_t* messageBuffer,
	size_t messageBufferSize,
	size_t* messageByteCount,
	uint8_t messageLengthSize,
	NetsResult(*receiveFunction)(
		const uint8_t*, size_t, void*),
	void* functionHandle);