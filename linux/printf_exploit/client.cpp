#include "socket_utils.h"
#include <sys/socket.h>

#include <stdlib.h>
#include <iostream>

#define OUTPUT_PREFIX "client>> "

using namespace std;

int main( int argc, char** argv )
{
   if( argc != 4 )
   {
      cout << "Usage: " << argv[0] << " <server_IP> <server_port> <message>" << endl;
      return PROGRAM_FAILURE;
   }

   char* serverIP = argv[1];
   int serverPort = atoi( argv[2] );
   unicast_pkt message;
   strcpy( message.data, argv[3] );
   const char* error = NULL;

   int messageSock = SocketUtils::SendMessage( serverIP, serverPort, message, &error );

   if( error )
   {
      cerr << OUTPUT_PREFIX << error << endl;
      return PROGRAM_FAILURE;
   }

   close( messageSock );
   cout << OUTPUT_PREFIX << "sent message '" << argv[3] << "' to server" << endl;
}
