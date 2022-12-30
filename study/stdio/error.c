#include <stdio.h>

int main(void)
{
    FILE* pFile;
    pFile = fopen("errortest.txt", "r");  //읽기전용으로 파일을 연다
    
    if (pFile == NULL)
    {
        perror("File open error ");                         //File open error : No such file or directory
    }
    else
    {
        fputc('x', pFile);                                  //읽기전용으로 연 파일에 x 라는 단어를 쓸 것이다.

        if(ferror(pFile))
        {
            printf("ferror1 event!!\n");                    //ferror1 event!!
            clearerr(pFile);                                //오류 표시자를 재설정 한다.
        }

        fputc('x', pFile); 
        if(ferror(pFile))
        {
            perror("ferror2 event!!");                      //ferror2 event!!: Bad file descriptor
            clearerr(pFile);
        }

        fclose(pFile);
    }

    return 0;
}