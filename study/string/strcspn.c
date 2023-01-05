#include <stdio.h>
#include <string.h>

int main(void)
{
    /*
        두 번재에 있는 값 요소들 중에서 첫 번째에 있는 값들과 같은게 있다면
        첫 번째에 있는 값의 위치를 반환한다.

        First pos : 1
        즉, test1[1] 에 test2의 요소들 중 하나가 위치하고 있다는 것
    */

    char test1[] = "abcdefg";
    char test2[] = "hijklmnmb";

    size_t n = strcspn(test1, test2);

    printf("First pos : %d\n", n);

    return 0;
}