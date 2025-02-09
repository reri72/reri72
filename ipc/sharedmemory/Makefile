CC = gcc
CFLAGS = -g -O2
TARGET = swrite sread

all : $(TARGET)

swrite : sharedmem_write.c
	$(CC) $(CFLAGS) -o $@ $<

sread : sharedmem_read.c
	$(CC) $(CFLAGS) -o $@ $<
	
clean : 
	rm -f $(TARGET)