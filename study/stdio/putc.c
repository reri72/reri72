#include <stdio.h>
#include <string.h>

int main(void){

    /* putc ex */
    /* */
    char ch = 'p';
    putc(ch, stdout);   // terminal : p
    printf("\n");

    FILE* pFile;
    char c;

    pFile = fopen("test.txt", "wt");         //rt wt at, rb wb ab 도 있음 (텍스트, 바이너리)
    for (c = '0'; c <= '9'; c++)                //숫자 0부터 9까지 파일에 씀 (실행 파일 위치 기준)
    {
        putc(c, pFile);
    }
    fclose(pFile);


    /* putchar ex */
    /* */   
    char ch = 'p';
    putchar(ch);    // terminal : p
    printf("\n");

    char c;
    for (c = 'a'; c <= 'z'; c++)    //terminal : abcdefghijklmnopqrstuvwxyz
    {
        putchar(c);
    }
    printf("\n");

    return 0;
}