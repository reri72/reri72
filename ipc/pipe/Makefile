CC = gcc
CFLAGS = -g -O2
TARGET = named_write named_read anonymous_pipe

all : $(TARGET)

named_write : named_write.c
	$(CC) $(CFLAGS) -o $@ $<

named_read : named_read.c
	$(CC) $(CFLAGS) -o $@ $<

anonymous_pipe : anonymous_pipe.c
	$(CC) $(CFLAGS) -o $@ $<
	
clean : 
	rm -f $(TARGET)