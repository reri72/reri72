#include <stdio.h>
#include <string.h>

int main(void)
{
    /*
        locale 사용하여 비교
        NULL 은 세지 않음
        첫 번째 인자가 NULL이면, 두 번째 인자의 문자열 길이를 세서 반환한다.
        strxfrm(string1, string2, n) 을 하면 string2의 앞에서 n개의 문자를 string1의 앞에서 n개의 문자에 갖다 붙인다.
    */
 
    char text1[20] = "Hello World!";
    int cv1 = strxfrm(NULL, text1, 0);
    printf("text1 length : %d \n", cv1);                //text1 length : 12

    char text2[20] = "Bye World!";
    int cv2 = strxfrm(text1, text2, 3);
    printf("%s : %d \n",text1, cv2);                    //Byelo World! : 10

    return 0;
}