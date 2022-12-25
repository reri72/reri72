#include <stdio.h>
#include <string.h>

int main(void){

    const char* test1 = "Hello World!";
    char test2[20] = "Hi World!";
    char test3[20] = "Bye\n World \0!";

    int a = strlen(test1);
    int b = strlen(test2);
    int c = strlen(test3);

    printf("a strlen : %d \n", a);
    printf("b strlen : %d \n", b);
    printf("c strlen : %d \n", c);

    fflush(stdout);

    return 0;
}
