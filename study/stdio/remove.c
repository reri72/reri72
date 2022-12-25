#include <stdio.h>

int main(void){

    int removetest;
    removetest = remove("C:/reri72/study/stdio/removetxt.txt");

	if( removetest == 0 )
		printf("remove success \n");
	else
		printf("remove fail \n"); //perror 사용 가능
    
    fflush(stdout);
    
    return 0;
}