#include <stdio.h>

int main(void)
{
    char temp[L_tmpnam];

    printf("tmp1 : %s \n", tmpnam(NULL));       //인자가 NULL이면 시스템 버퍼를 이용하여 생성
    printf("tmp2 : %s \n", tmpnam(temp));

    return 0;
}