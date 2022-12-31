#include <stdio.h>

int main(void)
{
    /* fgetc test */
    int i = fgetc(stdin);                       //a
    
    printf("first value : %c \n", i);
    while(getchar() != '\n'){}


    FILE* pFile;
    int c;
    int n = 0;

    pFile = fopen("fgetctest.txt", "r");        //파일내용 : 1a2b3daaabbbccc
    if (pFile == NULL)
    {
        perror("File open fail.");              //File open fail.: No such file or directory
    }
    else
    {
        while((c = fgetc(pFile)) != EOF) { 
	        putchar(c);
        }
        fclose(pFile);
    }
    
    return 0;
}