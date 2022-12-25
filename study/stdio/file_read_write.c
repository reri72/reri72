#include <stdio.h>
#include <string.h>

int main(){
    FILE* fw = fopen("C:/reri72/study/stdio/readwritetest.txt","a+");
    char readtest[100]={0,};

    if(fw == NULL){
        printf("not exist\n");
    }
    else
    {
        fread(readtest, sizeof(readtest), 1, fw);
        printf("context : %s \n", readtest);

        fwrite("\nBye!", strlen("\nBye!"), 1, fw);

        if(fclose(fw) != 0)
        {
            perror("fail\n");
        }
    }

    return 0;
}