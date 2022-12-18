#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>

#define SERVERIP "192.168.56.100"
#define PORT 12345

int main(int argc, char* argv[]){
    int c_sock, addr_len, buff_len;
    struct sockaddr_in serv_addr;

    char buff[100];
   
    c_sock = socket(AF_INET, SOCK_DGRAM, 0);
    if(c_sock < 0){
        printf("socket create fail. \n");
        exit(0);        
    }else{
        printf("socket create. \n");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERVERIP);
    serv_addr.sin_port = htons(PORT);
   
    sendto(c_sock, "1234", 4, 0, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

    shutdown(c_sock, SHUT_RDWR);
    close(c_sock);

    return 0;
}
