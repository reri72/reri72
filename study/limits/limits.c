#include <limits.h>
#include <stdio.h>

int main(void){

    printf(" ---- MAX ---- \n");

    printf("CHAR_MAX : %d \n", CHAR_MAX);
    printf("SHRT_MAX : %d \n", SHRT_MAX);
    printf("INT_MAX : %d \n", INT_MAX);
    printf("LONG_MAX : %ld \n", LONG_MAX);
    printf("LLONG_MAX : %lld \n\n",LLONG_MAX);


    printf(" ---- MIN ---- \n");

    printf("CHAR_MIN : %d \n", CHAR_MIN);
    printf("SHRT_MIN : %d \n", SHRT_MIN);
    printf("INT_MIN : %d \n", INT_MIN);
    printf("LONG_MIN : %lld \n", LONG_MIN);
    printf("LLONG_MIN : %lld \n\n",LLONG_MIN);

    return 0;
}