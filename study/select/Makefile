CC=gcc
CFLAGS= -g -O2
TARGET = server client

all : $(TARGET)

server : server.c
		$(CC) $(CFLAGS) -o $@ $<

client : client.c
		$(CC) $(CFLAGS) -o $@ $<

clean :
	rm -f $(TARGET)