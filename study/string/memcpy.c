#include <stdio.h>
#include <string.h>

int main(void)
{
    /* memcpy char ex */
    char srcchar[32] = "srcchar";
    char destination1[32] = "destination";

    memcpy(destination1, srcchar, sizeof(srcchar));
    printf("%s \n", destination1);
    /*
        srcchar

        destination1에 srcchar를 srcchar크기만큼 복사해 넣는다.
        destination1에 있던 문자열은 사라진다.
        만약 문자열에 \0 이 있다면 크기에 +1 을 해주어야 한다.
        
        메모리 블록과 메모리 블록이 겹쳐져 있는 곳에서는 쓸 수 없다.
    */



    /* memcpy int ex */
    int srcint[3] = {10,20,30};
    int destination2[3];
 
    memcpy(destination2, srcint, sizeof(srcint));
    for (int i = 0; i < 3; ++i)
    {
        printf("%d \n", destination2[i]);
    }
    /*
        10
        20
        30

        destination2에 srcint배열을 srcint의 크기만큼 복사해 넣는다.
        크기는 sizeof(int) * 3 로 하여도 동일하다.
    */



    /* memccpy str ex */
    char stringvar[50] = "Hello World! Bye generate! Good bye~";

    memccpy(stringvar + 14, "hi hello",'l', sizeof("hi hello"));
    printf("%s \n", stringvar);
    /*
        Hello World! Bhi helerate! Good bye~

        stringvar의 14번째(y)부터
        hi hello라는 문자열의 처음부터 l이 나오는 순간까지
        "hi hello" 의 크기만큼 복사하여 넣는다.
    */



    /* memmove str ex */
    char target[32] = "target";
    char copymem[32] = "copymem";

    printf("before memmove copymem : %s\n", copymem);
    memmove(copymem, target, sizeof(target));
    printf("after memmove copymem : %s\n", copymem);
    /*
        before memmove copymem : copymem
        after memmove copymem : target

        copymem에 target을 target의 크기만큼 복사(이동)한다.
        memcpy와 같이 복사를 해주는 기능이라고 보면 된다.
        동일한 메모리 공간에 덮어씌워야 한다면 사용한다.
    */



    return 0;
}