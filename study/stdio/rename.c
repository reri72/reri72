#include <stdio.h>

int main(void){

	int renametest;
    char beforefile[] = "C:/reri72/study/stdio/before.txt";
    char afterfile[] = "C:/reri72/study/stdio/after.txt";

    renametest = rename(beforefile, afterfile);

	if(renametest == 0 )
		printf( "rename success \n" );
	else
		printf( "rename fail \n" );

    fflush(stdout);

    return 0;
}