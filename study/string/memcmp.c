#include <stdio.h>
#include <string.h>

int main(void)
{
    /*
        두 메모리 블록을 n만큼 unsigned char 로 해석하여 비교
        첫 번째 인자에서 n개 문자와 두 번째 인자에서 n개 문자를 비교하여 같으면 0을 반환
        1 > 2 이면 양수 값, 1 < 2 이면 음수 값 반환
    */

    char string1[256], string2[256];
    int n;
    size_t len1, len2;

    printf("text1 : ");
    scanf("%s", string1);
    getchar();

    printf("text2 : ");
    scanf("%s", string2);
    getchar();

    len1 = strlen(string1);
    len2 = strlen(string2);
    
    n = memcmp(string1, string2, len1 > len2 ? len1 : len2);

    if (n > 0 || n < 0)
    {
        printf("%s != %s \n", string1, string2);
    }    
    else
    {
        printf("%s = %s \n", string1, string2);
    }
    
    return 0;
}