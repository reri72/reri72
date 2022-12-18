#include <stdio.h>

inline int gop(int val1){ return val1 * val1; }
inline void printtest(char *val2){ printf("%s \n", val2); }

int main(void) {

  printf("%d \n", gop(5));
  
  printtest("Hello World!");

  return 0;
}

/*
    test in linux
*/