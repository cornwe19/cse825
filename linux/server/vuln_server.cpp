#include <iostream>

#include "socket_utils.h"

#define OUTPUT_PREFIX "server>> "

using namespace std;

void OnServerMessage( int socket, unicast_pkt data, sockaddr_in sender, struct timeval** timeout );
void OnConsoleMessage( const char* message, bool* shouldExit ); 

int main( int argc, char** argv )
{
   int udpPort = -1;
   const char* error = NULL;

   int listeningSocket = SocketUtils::BindSocket( SOCK_DGRAM, udpPort, &error );

   if( error )
   {
      cerr << OUTPUT_PREFIX << error << endl; 
   }
   else
   {
      cout << OUTPUT_PREFIX << "server running on port: " << udpPort << " -- press 'q' to quit" << endl;
   }

   SocketUtils::ReceiveMessages( &listeningSocket, 1, OnServerMessage, OnConsoleMessage, NULL );

   close( listeningSocket );

   return 0;
}

void OnServerMessage( int socket, unicast_pkt data, sockaddr_in sender, struct timeval** timeout )
{
   cout << OUTPUT_PREFIX << "received message: " << data.data << " from host" << endl;
}

void OnConsoleMessage( const char* message, bool* shouldExit )
{
   if( strncmp( message, "q", 1 ) == 0 )
   {
      *shouldExit = true;
      cout << OUTPUT_PREFIX << "shutting down" << endl;
   }
}

