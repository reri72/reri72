#include <stdio.h>
#include <string.h>

int main(void)
{
    /*
        문자열을 지정 규칙 문자로 분리
        더 이상 찾을 것이 없으면 NULL 포인터 반환

        hello
        its
        me
    */

    char string[] = ",..hello, its me- ";
    char* test = strtok(string, " ,.-");

    while(test != NULL)
    {
        printf("%s \n", test);
        test = strtok(NULL, " ,.-");
    }

   return 0;
}