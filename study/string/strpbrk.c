#include <stdio.h>
#include <string.h>

int main(void)
{
    /*
        두 번째 인자에서 첫 번째 인자의 문자 요소들 중
        첫 번째로 일치하는 문자를 가리킴
        
        첫 번째 인자의 NULL 이전까지 탐색하고, 일치하는 것이 없으면 NULL 반환

        e, 61fe0c
        o, 61fe0f
        i, 61fe11
        e, 61fe16
    */

    char text[] = "hello its me";
    char val[] = "aeiou";
    char* pchar;

    pchar = strpbrk(text, val);

    while(pchar != NULL)
    {
        printf("%c, %x \n", *pchar, pchar);
        pchar = strpbrk(pchar + 1, val);
    }

    return 0;
}