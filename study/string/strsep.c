#include <stdio.h>
#include <string.h>

char *strsep(char **stringp, const char *delim);

int main(void)
{

    /*
        문자열을 구분자로 분리하여 출력
        더 이상 찾을 것이 없으면 NULL을 반환

        split text : 
        split text : ~
        split text : Hello
        split text : World,
        split text : Good
        split text : Bye,
        split text : World!

    */

    char string1[1024] = " ~ Hello World, Good Bye, World!";
    char string2[1025];
    char* pstring = NULL;
    char* res = NULL;
    
    strcpy(string2, string1);
    pstring = string2;
    
    while( (res = strsep(&pstring, " ")) != NULL )
    {
        printf("split text : %s\n", res);
    }

    return 0;
}


char *strsep(char **stringp, const char *delim)
{
    char *ptr = *stringp;
    if(ptr == NULL)
    {
        return NULL;
    }

    while(**stringp)
    {
        if(strchr(delim, **stringp) != NULL)            //strchr : 문자를 검색
        {
            **stringp = 0x00;
            (*stringp)++;

            return ptr;
        }
        (*stringp)++;
    }

    *stringp = NULL;

    return ptr;
}