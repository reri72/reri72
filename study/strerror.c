#include <errno.h>
#include <string.h>
#include <stdio.h>

int main(void){

    FILE* filetest;
    filetest = fopen("D:\\study/TEST.txt", "r");

    if (filetest == NULL)
        printf("not exist >> %s (%d) \n", strerror(errno), errno);
    else
        pclose(filetest);

    return 0;
}
