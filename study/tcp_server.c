#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>

#define SERVERPORT 12345

int main(void){
    int s_sock, c_sock;
    int res;
    unsigned int size;

    struct linger solinger = {1,0};
    int option = TRUE;

    struct sockaddr_in serv_addr = {}, clie_addr = {};
    //struct sockaddr_in6 serv_addr = {}, clie_addr = {};

    s_sock = socket(AF_INET, SOCK_STREAM, 0);
    if(s_sock < 0){
        printf("socket create error. \n");
        exit(0);
    }else{
        printf("socket create. \n");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SERVERPORT);
    serv_addr.sin_addr.s_addr =  htonl(INADDR_ANY);                                      //INADDR_ANY : 랜카드의 IP주소 사용하라는 뜻

/*
    serv_addr.sin6_family = AF_INET6;
    serv_addr.sin6_port = htons(CLIENTPORT);
    serv_addr.sin6_flowinfo = 0;
    serv_addr.sin6_addr = in6addr_any;
*/

    setsockopt(s_sock, SOL_SOCKET, SO_LINGER, &solinger, sizeof(struct linger));
    setsockopt(s_sock, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));                      //time-wait 상태인 소켓의 포트 번호도 새로운 소켓에 할당할 수 있게 해줌(TIME_WAIT에 빠진 주소를 재사용)

    res = bind(s_sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr));                //설정한 serv_addr(socket)을 사용하겠다고 등록
    if(res < 0){
        printf("bind error. \n");
        exit(0);
    }else{
        printf("bind success. \n");
    }

    res = listen(s_sock, 5);                                                            //서버소켓은 클라이언트로소켓의 연결 요청을 기다림
    if(res < 0){
        printf("listen error. \n");
        exit(0);
    }else{
        printf("listen success. \n");
    }

    size = sizeof(clie_addr);
    c_sock = accept(s_sock,(struct sockaddr*)&clie_addr, &size);                        //클라이언트 소켓의 연결 요청을 허용하도록 함
    if(c_sock < 0){
        printf("client socket : accept error. \n");
    }else{
        printf("client socket accept success. \n");
    }

    printf("server socket = [%d] \n", s_sock);
    printf("client socket = [%d] \n\n", c_sock);

    char msg[] = "hello world! \n";
    res = write(c_sock, msg, sizeof(msg));  //클라이언트한테 데이터 보냄
    if(res < 0){
        printf("write error. \n");
        exit(0);
    }else{
        printf("write success. \n");
    }

    shutdown(c_sock, SHUT_RDWR);
    close(c_sock);

    shutdown(s_sock, SHUT_RDWR);
    close(s_sock);

    return 0;
}