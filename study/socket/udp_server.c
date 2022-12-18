#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>

#define PORT 12345

int main(int argc, char* argv[]){
    int s_sock, c_len, buff_len, res;
    struct sockaddr_in serv_addr, clnt_addr;
    char buff[100];

    s_sock = socket(AF_INET, SOCK_DGRAM,0);
    if(s_sock < 0){
        printf("socket create fail. \n");
        exit(0);
    }else{
        printf("socket create. \n");
    }

    memset(&serv_addr,0,sizeof(serv_addr));
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(PORT);

    res = bind(s_sock,(struct sockaddr*)&serv_addr,sizeof(serv_addr));
    if(res < 0){
        printf("bind fail. \n");
        exit(0);
    }else{
        printf("bind success. \n");
    }

    c_len = sizeof(clnt_addr);
    buff_len = recvfrom(s_sock, buff, 100, 0, (struct sockaddr*)&clnt_addr, &c_len);
    buff[buff_len] = '\0';

    printf("recv : %s \n", buff);

    shutdown(s_sock, SHUT_RDWR);
    close(s_sock);

    return 0;
}
