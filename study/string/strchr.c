#include <stdio.h>
#include <string.h>

int main(void)
{
    /*
        첫 번째 인자에서 특정 '문자'가 나타나는 곳의 첫 포인터를 반환
        일치하는 문자가 없으면 NULL 리턴

        pos : string[4], o
        pos : string[7], o
    */

    char string[] = "Hello World!";
    char* mch = strchr(string, 'o');

    while(mch != NULL)
    {
        printf("pos : string[%d], %c \n", mch - string, *mch);
        mch = strchr(mch + 1, 'o');
    }

    return 0;
}