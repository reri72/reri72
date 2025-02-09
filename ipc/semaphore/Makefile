CC = gcc
CFLAGS = -g -O2
TARGET = posix_sema systemv_sema

all : $(TARGET)

posix_sema : posix_semaphore.c
	$(CC) $(CFLAGS) -o $@ $<

systemv_sema : systemv_semaphore.c
	$(CC) $(CFLAGS) -o $@ $<
	
clean : 
	rm -f $(TARGET)