#ifndef _COMMON_H_
#define _COMMON_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <poll.h>
#include <unistd.h>

#include <arpa/inet.h>
#include <netinet/in.h>

#include <sys/select.h>
#include <sys/socket.h>

#define PORT 702

#define BUF_SIZE 100
#define FDNUM 100
#define TIMEOUT 2000

void client_process();
void server_process();

#endif  //_COMMON_H_