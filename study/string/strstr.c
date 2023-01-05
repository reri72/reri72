#include <stdio.h>
#include <string.h>

int main(void)
{
    /*
        첫 번째 인자에서 두 번째 인자가 있는지 확인하고
        처음 찾은 '위치'를 반환
        
        없으면 NULL 반환

        pos : string[6], text : World!
        Hello Humen!
    */

    char string[] = "Hello World!";
    char* mch;

    mch = strstr(string, "World!");
    printf("pos : string[%d], text : %s \n", mch - string, mch);
    
    strncpy(mch, "Humen!", 6);
    printf("%s \n", string);

    return 0;
}