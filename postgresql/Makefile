CC=gcc
CFLAGS = -g -O2 -I/usr/pgsql-12/include
LDFLAGS = -L/usr/lib64 -lpq
SRC = postgresql_test.c
OBJ = $(SRC:.c=.o)

TARGET = postgresql_test

all : $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -f $(TARGET) $(OBJ)