#include <stdio.h>
#include <stdbool.h>

void main(void){

    bool b1 = true;     bool b2 = false;
    int b3 = 1;        int b4 = 0; 

    if(b1 == true)
        printf("b1 is true. \n");
    if(b3 == true)
        printf("b3 is true. \n");

    if(b2 == false)
        printf("b2 is false. \n");
    if(b4 == false)
        printf("b4 is false. \n");
  
    return;

}