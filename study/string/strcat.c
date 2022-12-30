#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>

//replace to snprintf() or memcpy()
int main(void)
{
    /* strcat */
    char test1[] = "test";
    char dest1[100] = "strcat ";
 
    strcat(dest1, test1);           //dest1 에 test1을 이어 붙인다.
    printf("dest1 : %s\n", dest1);          //dest1 : strcat test

    /* strncat */
    char test2[] = "test ";
    char dest2[50] = "abcd ";
    char dest3[50] = "efg ";
 
    strncat(dest2, test2, sizeof(test2));   //dest2 에 test2를 test2의 크기만큼 이어 붙인다.
    printf("dest2 : %s\n", dest2);          //dest2 : abcd test

    strncat(dest3, dest2, sizeof(dest2));   //dest3에 dest2를 dest2의 크기만큼 이어 붙인다.
    printf("dest3 : %s\n", dest3);          //dest3 : efg abcd test

    return 0;
}