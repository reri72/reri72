CC=gcc
CGLAGS= -Wall -g -O2
SRCS=$(wildcard *.c)
BINS = $(SRCS:.c=)
all: $(BINS)
LDFLAGS= -lcrypto

%: %.c
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@

clean:
	rm -f $(BINS)

.PHONY: all clean