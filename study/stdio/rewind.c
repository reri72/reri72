#include <stdio.h>

int main(void)
{
    /*
        파일의 모드 변경 함수
        read <-> write
    */

    char buffer[1024];
    int i = 0;
    FILE* pFile = fopen("rewindtest.txt", "w+");

    for (int i = '0'; i <= '9'; i++)
    {
         fputc(i, pFile);               //0123456789
    }

    rewind(pFile);
    fread(buffer, 1, 10, pFile);        //start 1, end 10
    fclose(pFile);
    
    buffer[11] = '\0';
    puts(buffer);

    return 0;
}