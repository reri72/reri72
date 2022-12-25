#include <stdio.h>
#include <errno.h>

int main(void){

   FILE *fp;

   /* exist  */
   fp = fopen( "C:/test1.txt", "r");
   printf("1 error = %d\n", errno);
   fclose(fp);
   printf("2 error = %d\n", errno);

   /* not exist   */
   fp = fopen("C:/test2.txt", "r");
   printf( "3 error = %d\n", errno);      // ENOENT
   fclose(fp);
   printf( "4 error = %d\n", errno);      // EINVAL

   return 0;
}

/*
   1 error = 0
   2 error = 0
   3 error = 2
   4 error = 22
*/