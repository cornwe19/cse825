all: socket_utils server client

socket_utils: socket_utils.cpp socket_utils.h
	@mkdir -p "$(@D)/bin"
	g++ -c socket_utils.cpp -o bin/socket_utils.o

server: vuln_server.cpp socket_utils.o
	g++ -Wall -ggdb -fno-stack-protector -U_FORTIFY_SOURCE vuln_server.cpp bin/socket_utils.o -o bin/server
	execstack -s bin/server

client: client.cpp socket_utils.o
	g++ -Wall client.cpp bin/socket_utils.o -o bin/client

clean:
	rm -f bin/*

