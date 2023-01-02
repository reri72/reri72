#include <stdio.h>

int main(void)
{
    /*
        파일의 읽기·쓰기 위치 이동

        SEEK_SET : 파일의 시작
        SEEK_CUR : 지금 파일 포인터 위치
        SEEK_END : 파일 끝
    */

    FILE* fseektest = fopen("fseektest.txt", "w");
    
    fputs("Hello   Bye", fseektest);
    fseek(fseektest, 5, SEEK_SET);

    fputs("Hi!", fseektest);
    fclose(fseektest);

    //result : HelloHi!Bye

    return 0;
}