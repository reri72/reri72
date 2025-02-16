CC=gcc
CFLAGS= -Wall -g -O2
LDFLAGS= -L/usr/lib64/mysql -lmysqlclient

SRC= mysql_test.c
OBJ= $(SRC:.c=.o)

TARGET=myutils

all : $(TARGET)

$(TARGET) : $(OBJ)
	$(CC) $(OBJ) -o $(TARGET) $(LDFLAGS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -f $(TARGET) $(OBJ)	
