CC = gcc
CFLAGS = -g -O2
TARGET = send receive

all : $(TARGET)

send : send.c
	$(CC) $(CFLAGS) -o $@ $<

receive : receive.c
	$(CC) $(CFLAGS) -o $@ $<
	
clean : 
	rm -f $(TARGET)