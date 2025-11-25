CC=gcc
CFLAGS= -g -O2
TARGET= server client

all : $(TARGET)

server : server.c common.h
		$(CC) $(CFLAGS) $< -o $@

client : client.c common.h
		$(CC) $(CFLAGS) $< -o $@

clean : 
	rm -f $(TARGET)