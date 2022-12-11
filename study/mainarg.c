#include <stdio.h>

int main(int argc, char* argv[]){

    int i;
    for(i = 0; i < argc; i++){
        printf("argv[%d] : %s \n", i, argv[i]);
    }

    printf("argc : %d \n", argc);

    return 0;
}

/*

]# gcc ./argtest.c -o argtest.out

]# ./argtest.out
argv[0] : ./argtest.out 
argc : 1 

]# ./argtest.out hi
argv[0] : ./argtest.out 
argv[1] : hi 
argc : 2 
 
]# ./argtest.out hi " hello " bye " bye "
argv[0] : ./argtest.out
argv[1] : hi
argv[2] :  hello 
argv[3] : bye
argv[4] :  bye
argc : 5

*/