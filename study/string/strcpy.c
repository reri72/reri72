#include <stdio.h>
#include <string.h>

int main()
{
    /* strcpy test */
    char text1[10] = "hi world";
    char test1[10];

    strcpy(test1, text1);
    printf("test1 : %s \n", test1);
    /*
        test1 : hi world

        text1의 문자열을 test1에 null byte까지 포함하여 붙여넣는다.
        단, 크기가 'test1 >= text1' 의 조건이 성립하여야 한다. 
    */



   /* strncpy test */
    char text2[10] = "bye world";
    char test2[10];

    strncpy(test2, text2, sizeof(text2));
    printf("test2 : %s\n", test2);
    /*
        test2 : bye world

        text2에 있는 문자열을 test2에 붙여넣는다.
    */



    char text3[10] = "good";
    char test3[10];

    strncpy(test3, text3, 2);
    printf("test3 : %s\n", test3);
    /*
        test3 : go

        text2에 있는 문자열의 첫 번째 부터 2개만 test3에 붙여넣는다.
    */


    return 0;
}