#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>

noreturn void exiterr(void){
    puts("exit 1");
    exit(1);
}

_Noreturn void end_func(void){
    puts("end");
    exiterr();
}

int main(void){
    end_func();
    puttest();

    return 0;
}

void puttest(void){
    puts("puttest");
}