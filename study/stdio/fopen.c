#include <stdio.h>

int main(){
    FILE* opentest = fopen("C:/reri72/study/stdio/opentest.txt","w+");

    /*
     - permission -
        "r"         존재하는 파일을 읽기 모드로 엶
        "w"         파일이 있든 없든 쓰기 모드로 엶
                    기존에 내용이 담긴 파일이 존재했으면 내용은 지워짐
        "a"         덧붙이기 모드로 엶
                    파일이 존재하지 않으면 새로 생성
                    쓰는 작업은 끝부분에 데이터를 붙임

        "r+"        파일을 읽기,쓰기 모드로 엶
                    파일은 반드시 존재해야 함
        "w+"        파일을 읽기, 쓰기 모드로 엶
                    파일 없으면 새로 생성하고, 있다면 기존 내용은 다 지우고 빈 파일로 삼음
        "a+"        파일을 덧붙이기 모드로 엶
                    파일이 없다면 새로 생성하고, 쓰기 작업은 맨 끝에서 데이터를 씀
                    읽기 작업은 포인터를 원하여 움직일 수 있지만 쓰기는 언제나 맨 끝에서 작업
    */

    if(opentest == NULL)
    {
        printf("not exist\n");
    }
    else
    {
        fprintf(opentest,"good");
        if(fclose(opentest) != 0)
        {
            perror("fail\n");
        }
    }

    return 0;
}