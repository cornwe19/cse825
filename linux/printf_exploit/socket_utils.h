#pragma once

#ifndef _SOCKET_UTILS_H_
#define _SOCKET_UTILS_H_

#include <netinet/in.h>
#include <sys/types.h>

#include "common.h"

// Define a few delegates for base station and remote host to implement as callbacks for events in the system
typedef void (*SocketCallback)( int socket, unicast_pkt data, sockaddr_in sender, struct timeval** timeout );
typedef void (*ConsoleCallback)( const char* message, bool* exit );
typedef void (*TimeoutCallback)( struct timeval** timeout );

// Static class defining some utility methods used in base station and remote host
class SocketUtils
{
public:
	static int BindSocket( int type, int& port, const char** error );
	static void ReceiveMessages( int* descriptors, int descriptors_len,
                                SocketCallback socketMessageReceived,
                                ConsoleCallback consoleMessageReceived,
                                TimeoutCallback timeoutFired = NULL );
	static int SendMessage( const char* dest_ip, int dest_port, unicast_pkt message, const char** error );
	static void SendMessage( const char* dest_ip, int dest_port, unicast_pkt message, int dest_sock );
};

#endif

