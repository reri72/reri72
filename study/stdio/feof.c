#include <stdio.h>

int main(void)
{
    FILE* pFile;
    long n = 0;

    pFile = fopen("feoftest.txt", "r");      //내용 : $$aabbcc
    
    if (pFile == NULL)
    {
        perror("Error opening file ");      //Error opening file : No such file or directory
    }
    else
    {
        while (!feof(pFile))
        {
            fgetc(pFile);
            n++;
        }

        fclose(pFile);
        printf("char count: %d\n", n - 1);
        /*
            char count: 8

            -1를 한 이유는 EOF의 수를 빼기 위함이다.
        */
    }

    return 0;
}