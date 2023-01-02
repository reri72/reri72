#include <stdio.h>
#include <string.h>

int main(void)
{
    /*
        첫 번째 인자의 n개 문자와 두 번째 인자의 n 개 문자를 비교하여 같으면 0 반환
        1 > 2 이면 양수값, 1 < 2 이면 음수값 반환
        
        Korea Hello
        Korea Bye
    */

    char text[][1024] = {"Hello world", "Korea Hello", "Korea Bye"};
    int i;

    for (i = 0; i < 3; i++)
    {
        if(strncmp(text[i], "Korea", 5) == 0)
        {
            printf("%s \n", text[i]);
        }
    }

    return 0;
}