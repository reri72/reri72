#include <stdio.h>

int main(void)
{
    /* fgets test */
    char fgetstest[50];

    fgets(fgetstest, sizeof(fgetstest), stdin);
    printf("fgets : %s", fgetstest);                            //abc


    FILE* fgetstest2;
    char teststring[100];

    fgetstest2 = fopen("fgetstest.txt", "r");                   //파일내용 : reri
    if (fgetstest2 == NULL)
    {
        perror("File open fail.");                              //File open fail.: No such file or directory
    }
    else
    {
        fgets(teststring, sizeof(teststring), fgetstest2);      //문자열 변수에 파일에 있는 내용을 읽어다 씀
        puts(teststring);

        fclose(fgetstest2);
    }

    return 0;
}