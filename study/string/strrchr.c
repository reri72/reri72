#include <stdio.h>
#include <string.h>

int main(void)
{
    /*
        문자를 검색하여 '마지막'으로 나타난 위치를 포인터로 반환
        일치하는 문자가 없으면 NULL 리턴

        pos : string[6], W
    */

    char string[] = "Hello World!";
    char* mch;

    mch = strrchr(string, 'W');
    printf("pos : string[%d], %c \n", mch - string, *mch);

    return 0;
}