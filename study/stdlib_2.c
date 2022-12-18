#include <stdio.h>
#include <stdlib.h>

int main(void){

  /* 1st */ /**/
  int *p1; 
  int *p2;

  p1 = (int *)malloc(sizeof(int) * 3);
  printf("malloc : %d %d %d \n", p1[0], p1[1], p1[2]);
  
  p2 = (int *)calloc(3, sizeof(int));
  printf("calloc : %d %d %d \n", p2[0], p2[1], p2[2]);

  free(p1);
  free(p2);


  /* 2nd */ /**/
  int i;
  int *pi = (int *)malloc(sizeof(int) * 3);

  printf("\n\n - malloc - ");
  for (i = 0; i < 3; i++)
  {
      pi[i] = i;
      printf("pi[%d] : memory %d %d\n", i, &pi[i], pi[i]);
  }
  
  printf("\n\n - realloc - \n");
  pi = (int *)realloc(pi,sizeof(int) * 5);
  for (i = 3; i < 5; i++)
  {
      pi[i] = i;
  }

  for (i = 0; i < 5; i++)
  {
      printf("pi[%d] : memory %d %d\n", i, &pi[i], pi[i]);
  }    
  
  free(pi);

  return 0;
}