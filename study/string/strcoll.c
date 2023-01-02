#include <stdio.h>
#include <string.h>

int main(void)
{
    /*
        locale 사용하여 비교 (LC_COLLATE)
        첫 번째 인자의 n개 문자와 두 번째 인자의 n개 문자를 비교하여 같으면 0반환
        1 > 2 이면 양수값, 1 < 2 이면 음수값 반환

        Bye
        bye
        Bye
        Bye
        Bye world!
    */

    char text[] = "Bye";
    char inputtext[80];

    do{
        puts("Bye");
        fflush(stdout);

        scanf("%s", inputtext);
        getchar();
    }while(strcoll(text, inputtext) != 0);

    puts("Bye world!\n");

    return 0;
}