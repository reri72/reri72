#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){

    /* 1st */ /**/
    char str[10] = "2022";

    int num = atoi(str);
    printf("std(int) : %d \n", num);

    int num2 = 22;    char str2[10];
    itoa(num2, str2, 10);
    printf("str2(char) : %s \n", str2);

    long num3 = atol("789456");
    printf("num3(long) : %ld \n", num3);

    double num4 = atof("123456");
    printf("num4(double) : %0.0lf \n", num4);


    /* 2nd */ /**/
    char *end;

    char *s1 = "0xaf10 42 0x27C 9952"; 
    int n1 = strtol(s1, &end, 16);
    int n2 = strtol(end, &end, 10);
    int n3 = strtol(end, &end, 16);
    int n4 = strtol(end, &end, 10);
    printf("n1 n2 n3 n4 : %x %d %X %d \n", n1, n2, n3, n4);
 
    char *s2 = "ff -1234567890 -7 123";
    unsigned long n5 = strtoul(s2, &end, 16);
    unsigned long n6 = strtoul(end, &end, 10);
    unsigned long n7 = strtoul(end, &end, 10);
    unsigned long n8 = strtoul(end, &end, 8);
    printf("%lu %lu %lu %lu\n", n5, n6, n7, n8);

    char *s3 ="100.01abcd";
    double n9 = strtod(s3,&end);
    printf("n9 : %.2f\n",n9);
    printf("%s\n",end);


    /* 3rd */ /**/
    srand(time(NULL));
    int ran = rand();
    printf("rad : %d \n", ran);

    return 0;
}
