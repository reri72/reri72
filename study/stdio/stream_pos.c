#include <stdio.h>

int main(void)
{

    FILE* pFile;
    fpos_t pos;

    pFile = fopen("postest.txt", "w");
    if (pFile == NULL)
    {
        perror("File open fail.");                  //File open fail.: No such file or directory
        return 0;
    }
    
    fgetpos(pFile, &pos);                           //스트림 위치 지정자의 현재 위치를 확인
    printf("First pos (fpos_t) : %lld \n", pos);
    
    fputs("aaaa bbbb cccc dddd", pFile);

    long cp = ftell(pFile);                         //파일의 처음부터 끝까지의 byte수를 계산
    printf("cur pos(ftell) : %ld \n", cp);

    fsetpos(pFile, &pos);                           //스트림 위치 지정자의 현재 위치를 지정
    fputs("zzzz", pFile);

    fclose(pFile);

    //result : zzzz bbbb cccc dddd

    return 0;
}