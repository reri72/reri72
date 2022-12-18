#include <stdio.h>

#define TESTMACRO(x) x*x

#define GOP(X) printf(""#X" * "#X" =  %d\n", ((X)*(X)))  

#define TESTSHOP(n) x ## n
#define PRTSHOP(n) printf("x" #n " : %d \n", x ## n)  

int main(void){

    printf("%d \n", TESTMACRO(2+2));
                    //  2+2 * 2+2
                    //  2+(2*2)+2 = 8

    printf("%d \n", TESTMACRO(TESTMACRO(2)));
                    //  (2*2) * (2*2)

    GOP(2);
    // 2*2

    int TESTSHOP(1) = 10;
    PRTSHOP(1);

    int TESTSHOP(2) = 20;
    PRTSHOP(2);
    
    return 0;
}