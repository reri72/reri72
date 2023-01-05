#include <stdio.h>
#include <string.h>

int main(void)
{
    /*
        메모리 블록에서 '문자'를 찾음
        첫 번째 인자의 n byte중, 처음으로 두 번째 인자의 값과 '첫' 일치하는 주소를 반환
        일치하는 주소값을 찾지 못하면 NULL 리턴

        | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10|
        | H | e | l | l | o |   | W | o | r | l | d |

        mch : 6422030
        string : 6422028
        pos : 2
    */

    char string[] = "Hello World";
    char * mch = (char *)memchr(string, 'l', strlen(string));

    if (mch != NULL)
    {
        printf("mch : %d\n", mch);
        printf("string : %d\n", string);
        printf("pos : %d \n", mch - string);
    }
    else
    {
        printf("not exist \n");
    }

    return 0;
}