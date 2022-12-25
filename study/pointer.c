#include <stdio.h>

int main(void)
{
    /* single pointer */
    int a = 1234;
    int* pa = &a;
                    /*
                        - same -  
                        int * pa;
                        int *pa;
                    */

    printf("pa 주소 : %#x \n", pa);
    printf("pa에 저장된 값 : %d \n", *pa);


    /* double pointer */
    int b = 100;
    int* bp = &b;
    int **bpp = &bp;
    printf("b : %d \n", b);
    printf("*bp : %d \n", *bp);
    printf("*bpp : %d \n", **bpp);

    *bp = 200;
    printf("b : %d \n", b);
    printf("*bp : %d \n", *bp);
    printf("*bpp : %d \n", **bpp);

    **bpp = 300;
    printf("b : %d \n", b);
    printf("*bp : %d \n", *bp);
    printf("*bpp : %d \n", **bpp);

}