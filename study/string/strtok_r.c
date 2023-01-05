#include <stdio.h>
#include <string.h>

int main(void)
{
    /*
        strtok 함수와 동일한 기능을 함

        추출해낸 문자열 : Hello     다음추출 문자열 : World! Goodbye~
        추출해낸 문자열 : World!     다음추출 문자열 : Goodbye~
        추출해낸 문자열 : Goodbye~     다음추출 문자열 :

    */

    char string[] = "  Hello World! Goodbye~ ";
    char* text = NULL;
    char* tok = strtok_r(string," ", &text);

    while(tok != NULL)
    {
        printf("추출해낸 문자열 : %s     다음추출 문자열 : %s \n", tok, text);
        tok = strtok_r(NULL, " ", &text);
    }

    return 0;
}