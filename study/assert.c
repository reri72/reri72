#include <stdio.h>
#include <assert.h>

int test_assert(int x);

int main (void){
  int i;
  for (i = 0; i <= 9; i++)
  {
    test_assert( i );
    printf("i = %d \n", i);
  }

  return 0;
}

int test_assert (int x){
   assert( x <= 5 );
   return x;
}

/*
[Result]

i = 0
i = 1
i = 2
i = 3
i = 4
i = 5
Assertion failed!

..

Expression: x <= 5

*/