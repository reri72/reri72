#include <stdio.h>
#include <stdlib.h>

//optimizing compiler
//reference compiler.h

#ifndef likely
# define likely(x)          __builtin_expect(!!(x), 1)
#endif

#ifndef unlikely
# define unlikely(x)        __builtin_expect(!!(x), 0)
#endif

int main(){
    int a = 1;
    
    if( likely(a == 1 ) )
    {

    }
    else
    {

    }

    if( unlikely(a == 0 ) )
    {

    }
    else
    {

    }
    
    return 0;

}