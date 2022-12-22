#include <stdio.h>

int main(void){

    /* getc test */
    /* */
    int test1;
    test1 = getc(stdin);
    printf("stream : %c \n", test1);    //terminal로 입력받은 단어 하나를 출력한다.

    FILE* test2;
    int c = 0, n = 0;
    test2 = fopen("test.txt", "r");

    if (test2 == NULL)
    {
        perror("file open fail. \n");
    }
    else
    {
        do{
            c = getc(test2);

            if (c == '0')
            {
                n++;
            }
        }while(c != EOF);

        fclose(test2);
        printf(" '0' count : %d \n", n);            //파일 내 0 이라는 단어가 몇 개 있는지 출력한다.
    }
    

    /* getchar test  */
    /*  */
    char test3, test4, test5;

    test3 = getchar();
    while (getchar() != '\n') {}    //terminal 입력

    test4 = getchar();
    while (getchar() != '\n') {}    //terminal 입력

    test5 = getchar();
    while (getchar() != '\n') {}    //terminal 입력

    printf("test3 :%c \n", test3);
    printf("test4 :%c \n", test4);
    printf("test5 :%c \n", test5);

    int test6;
    do{
        test6 = getchar();    //terminal 입력
        putchar(test6);
    }while (test6 != '\n');

    return 0;
}