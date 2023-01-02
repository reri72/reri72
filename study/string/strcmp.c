#include <stdio.h>
#include <string.h>

int main(void){

    /*
        첫 번째 인자의 문자열과 두 번째 안자의 문자열을 비교하여 같으면 0을 반환
        1 > 2 이면 양수값, 1 < 2 이면 음수값 반환

        hello
        hi
        hello
        hi
        hello
        hello
        Bye world!
    */

    char text[] = "hello";
    char inputtext[1024];

    do{
        puts("hello");
        fflush(stdout);

        scanf("%s", inputtext);
        getchar();
    }while(strcmp(text, inputtext) != 0);

    puts("Bye world!\n");

    return 0;
}