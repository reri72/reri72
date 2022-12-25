#include <stdio.h>
#include <string.h>

int main(void){

    // char test1[] = "memset test";
    // memset(test1, 'a', 3 * sizeof(char));
    // printf("test1 : %s\n",test1);
    //test1 : aaaset test


    int test2[10];
    memset(test2, 1, sizeof(test2));    //이렇게 쓰면 안된다.
    /*
        memset 함수는 1 byte로 단위로 값을 초기화 한다.
        1 byte 단위로 1를 만들었기 때문에 4 byte로 표현된 1은 제대로된 숫자로 표현될 수 없다.
        문자열이랑 0으로 초기화할 때 사용한다.
    */
   
    for (int i = 0; i < 5; ++i)
        printf("%d \n", *(test2 + i));

    return 0;
}