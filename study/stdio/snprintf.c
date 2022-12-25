#include <stdio.h>
#include <string.h>

int main(void){

	char str1[] = "snprint test";
	char str2[50];
	
	snprintf(str2, strlen(str1) + 1, "%s \n", str1);
	printf("str1 : %s \n", str1);
	printf("str2 : %s \n\n", str2);

    snprintf(str2, 50, "", 0);
    sprintf(str2, "%s\n", str1);
	printf("str2 : %s", str2);

    return 0;
}