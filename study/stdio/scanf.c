#include <stdio.h>

int main(void){

    /* scanf test */
    /**/
    char scanftest[50];
    int a, b;
    scanf("%s %d %d", scanftest, &a, &b);
    printf("%s, %d, %d \n", scanftest, a, b);
    

    /* sscanf test */
    /**/
    const char* scanftest2 =  "korea 1 2";
    char msg[50];
    int num1, num2;

    sscanf(scanftest2, "%s %d %d", msg, &num1, &num2);
    printf("%s %d %d\n", msg, num1, num2);
    

    /*fscanf test */
    /**/
    char id[30];
    int password;

    FILE *file;
    file = fopen("C:/reri72/study/stdio/scanftest.txt", "r");
    //context : hello 123456789

    while( fscanf(file, "%s %d", id, &password) > 0 )
    {
        printf("id : %s  password : %d\n", id, password);
    }
        
    return 0;
}