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
#define CLIENTPORT 12345

int main(void){
    int c_sock, res;

    struct linger solinger = {1,0};
    struct sockaddr_in serv_addr = {};
    //struct sockaddr_in6 serv_addr = {};

    unsigned char msg[100];

    c_sock = socket(AF_INET, SOCK_STREAM, 0);
    if(c_sock < 0){
        printf("socket create error. \n");
        exit(0);
    }else{
        printf("client socket create. \n");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;                                                     //IPv4나 IPv6 쓴다고 정하는 것임
    serv_addr.sin_addr.s_addr = inet_addr(SERVERIP);                                    //문자열을 IPv4 주소로 변환
    serv_addr.sin_port = htons(CLIENTPORT);                                             //host byte를 network byte로 변환

/*
    serv_addr.sin6_family = AF_INET6;
    serv_addr.sin6_port = htons(CLIENTPORT);
    serv_addr.sin6_flowinfo = 0;
    serv_addr.sin6_addr = in6addr_any;
*/

    setsockopt(c_sock, SOL_SOCKET, SO_LINGER, &solinger, sizeof(struct linger));

    res = connect(c_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));             //클라이언트 서버로 연결
    if(res < 0){
        printf("connect error. \n");
        exit(0);
    }else{
        printf("connect success. \n");
    }

    res = read(c_sock, msg, sizeof(msg));                                               //서버로부터 들어오는 데이터 받기(블로킹Func)
    if(res < 0){
        printf("read error. \n");
        exit(0);
    }else{
        printf("message from server : %s \n" ,msg);
    }

    shutdown(c_sock, SHUT_RDWR);                                                        //sock의 read,write buffer 차단
    close(c_sock);                                                                      //sock close

    return 0;
}