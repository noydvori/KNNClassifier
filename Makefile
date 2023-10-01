CC=g++ -pthread
CFLAGS=-c -Wall -I.

OBJS=TCPServer.o TCPClient.o Command.o Command1.o Command2.o Command3.o Command4.o Command5.o StandardIO.o DefaultIO.o SocketIO.o fileHandler.o CLI.o distanceAndClassification.o distances.o fileDatabase.o inputValidity.o numbers.o

all: Server Client

server: server.o $(OBJS)
	$(CC) server.o $(OBJS) -o server.out

client: client.o $(OBJS)
	$(CC) client.o $(OBJS) -o client.out

server.o: Server/server.cpp
	$(CC) $(CFLAGS) Server/server.cpp

client.o: Client/client.cpp
	$(CC) $(CFLAGS) Client/client.cpp

TCPServer.o: Server/TCPServer.cpp Server
	$(CC) $(CFLAGS) Server/TCPServer.cpp

TCPClient.o: Client/TCPClient.cpp Client
	$(CC) $(CFLAGS) Client/TCPClient.cpp

Command.o: Commands/Command.cpp Commands
	$(CC) $(CFLAGS) Commands/Command.cpp

Command1.o: Commands/Command1.cpp Commands
	$(CC) $(CFLAGS) Commands/Command1.cpp

Command2.o: Commands/Command2.cpp Commands
	$(CC) $(CFLAGS) Commands/Command2.cpp

Command3.o: Commands/Command3.cpp Commands
	$(CC) $(CFLAGS) Commands/Command3.

Command4.o: Commands/Command4.cpp Commands
	$(CC) $(CFLAGS) Commands/Command4.cpp
Command5.o: Commands/Command5.cpp Commands
	$(CC) $(CFLAGS) Commands/Command5.cpp

numbers.o: KNN/numbers.cpp KNN
	$(CC) $(CFLAGS) KNN/numbers.cpp

distanceAndClassification.o: KNN/distanceAndClassification.cpp KNN
	$(CC) $(CFLAGS) KNN/distanceAndClassification.cpp

distances.o: KNN/distances.cpp KNN
	$(CC) $(CFLAGS) KNN/distances.cpp

fileDatabase.o: CSV/fileDatabase.cpp CSV
	$(CC) $(CFLAGS) CSV/fileDatabase.cpp

fileHandler.o: CSV/fileHandler.cpp CSV
	$(CC) $(CFLAGS) CSV/fileHandler.cpp

CLI.o: CLI.cpp CLI.h
	$(CC) $(CFLAGS) CLI.cpp

inputValidity.o: inputValidity.cpp inputValidity.h
	$(CC) $(CFLAGS) inputValidity.cpp

DefaultIO.o: DefaultIO.cpp DefaultIO.h
	$(CC) $(CFLAGS) DefaultIO.cpp

SocketIO.o: SocketIO.cpp SocketIO.h
	$(CC) $(CFLAGS) SocketIO.cpp

StandardIO.o: StandardIO.cpp StandardIO.h
	$(CC) $(CFLAGS) StandardIO.cpp

clean:
	rm -rf *o server.out client.out