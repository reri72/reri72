#include <stdio.h>
#include <string.h>

int main(void)
{
    /*
        두 번째 인자의 요소를 포함하고 있는지
        첫 번째 인자의 첫 부분부터 확인하여 참 횟수 반환
        ※맨 처음부터 비교하기 때문에 처음부터 없으면 0이 반환되므로 주의
        
        n : 3

        1 존재 +1
        2 존재 +1
        H 존재 +1
        0 없음 break
    */
    
    char text1[] = "H2elo1";
    char text2[] = "12H0Hddeq";

    size_t n = strspn(text2, text1);

    printf("n : %d\n", n);
    
    return 0;
}