#include <stdio.h>

int main(void)
{
    char str[] = "Hello World!";
    int i = 0;

    while(str[i])
    {
        fputc(str[i], stdout);
        i++;
    }
    printf("\n");
    fflush(stdout);


    FILE* pFile;
    char c;

    pFile = fopen("fputctest.txt", "w");          //파일을 w모드로 열어(없으면 생성하여서) 0 부터 9까지 씀
    if (pFile != NULL)
    {
        for (c = '0'; c <= '9'; c++)
        {
            fputc((int)c, pFile);
        }
        fclose(pFile);
    }

    return 0;
}