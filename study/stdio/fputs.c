#include <stdio.h>

int main(void)
{
    /*
        NULL(\0) 까지 문자열을 복사 함.
        마지막 NULL(\0)은 복사되지 않음.
    */

    char str[] = "Hello World!\n";
    fputs(str, stdout);                                             //문자열 출력
    fflush(stdout);


    FILE* pFile;
    char sentence[256];

    fgets(sentence, 255, stdin);

    pFile = fopen("fputstest.txt", "a");
    fputs(sentence, pFile);                                         //줄바꿈 됨

    fclose(pFile);

    return 0;
}