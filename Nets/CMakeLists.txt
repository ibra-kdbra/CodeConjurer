cmake_minimum_required(VERSION 3.22)

if(CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
	message(FATAL_ERROR "Prevented in-tree build")
endif()

if(TARGET nets-static)
	return()
endif()

include(cmake/package-managers.cmake)

project(nets VERSION 2.0.3 LANGUAGES C
	DESCRIPTION "Secure multi-platform networking library \
		with implemented TCP / UDP / HTTP server and client"
	HOMEPAGE_URL "https://github.com/cfnptr/nets")

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

option(NETS_BUILD_EXAMPLES "Build Nets usage examples" ON)
option(NETS_USE_OPENSSL "Use OpenSSL for secure communication" ON)
option(NETS_ALLOW_DEPRECATED_SSL "Allow deprecated OpenSSL functions" OFF)

find_package(ZLIB REQUIRED)

if(NETS_USE_OPENSSL)
	find_package(OpenSSL)

	if(OpenSSL_FOUND)
		set(NETS_SUPPORT_OPENSSL 1)
	else()
		set(NETS_SUPPORT_OPENSSL 0)
	endif()

	if(NETS_ALLOW_DEPRECATED_SSL)
		set(NETS_SUPPORT_DEPRECATED_SSL 1)
	else()
		set(NETS_SUPPORT_DEPRECATED_SSL 0)
	endif()
else()
	set(NETS_SUPPORT_OPENSSL 0)
	set(NETS_SUPPORT_DEPRECATED_SSL 0)
endif()

include(TestBigEndian)
TEST_BIG_ENDIAN(IS_BIG_ENDIAN)

if(IS_BIG_ENDIAN)
	set(NETS_LITTLE_ENDIAN 0)
else()
	set(NETS_LITTLE_ENDIAN 1)
endif()

set(NETS_INCLUDE_DIRECTORIES ${ZLIB_INCLUDE_DIRS} 
	${PROJECT_BINARY_DIR}/include ${PROJECT_SOURCE_DIR}/include)
set(NETS_LINK_LIBRARIES mpmt-static mpio-static ZLIB::ZLIB)

set(MPMT_BUILD_SHARED OFF CACHE BOOL "" FORCE)
set(MPMT_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(MPMT_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(libraries/mpmt)

set(MPIO_BUILD_SHARED OFF CACHE BOOL "" FORCE)
set(MPIO_BUILD_TESTS OFF CACHE BOOL "" FORCE)
add_subdirectory(libraries/mpio)

configure_file(cmake/defines.h.in include/nets/defines.h)

if(NETS_USE_OPENSSL AND OpenSSL_FOUND)
	list(APPEND NETS_LINK_LIBRARIES OpenSSL::SSL OpenSSL::Crypto)
endif()

set(NETS_SOURCES source/datagram_client.c source/datagram_server.c source/http_client.c 
	source/socket.c source/stream_client.c source/stream_server.c)

add_library(nets-static STATIC ${NETS_SOURCES})
target_link_libraries(nets-static PUBLIC ${NETS_LINK_LIBRARIES})
target_include_directories(nets-static PUBLIC ${NETS_INCLUDE_DIRECTORIES})

if(NETS_BUILD_EXAMPLES)
	add_executable(nets-datagram-example examples/datagram_example.c)
	target_link_libraries(nets-datagram-example PRIVATE nets-static)
	target_include_directories(nets-datagram-example PRIVATE
		${PROJECT_BINARY_DIR}/include ${PROJECT_SOURCE_DIR}/include)

	add_executable(nets-https-example examples/https_example.c)
	target_link_libraries(nets-https-example PRIVATE nets-static)
	target_include_directories(nets-https-example PRIVATE
		${PROJECT_BINARY_DIR}/include ${PROJECT_SOURCE_DIR}/include)
endif()