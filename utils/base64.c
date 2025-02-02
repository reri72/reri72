#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

char *base64_encode(const char *src, size_t length);
char *base64_decode(const char *src, size_t length);

/*
    output length :
        4 x ( inputlen+2 / 3 )
    
    * 입력 데이터를 3bytes(24bits)씩 처리
        - 6 bytes면 3bytes 2개 묶어 처리하고
            , 5 bytes면 3bytes 1개, 2bytes는 패딩(=)처리
    * 각 3bytes는 4개의 base64 문자로 변환
        - 3bytes(24bits)를 6bits씩 4개로 나누어 각각 base64 문자로 매핑
            따라서 3bytes 입력은 4개 문자 출력 관계가 성립
    * 3bytes보다 적은 데이터는 패딩(=)을 사용해 3bytes로 맞춤
*/

static const char base64table[64] = {'A', 'B', 'C', 'D', 'E', 'F',
                                     'G', 'H', 'I', 'J', 'K', 'L',
                                     'M', 'N', 'O', 'P', 'Q', 'R',
                                     'S', 'T', 'U', 'V', 'W', 'X',
                                     'Y', 'Z', 'a', 'b', 'c', 'd',
                                     'e', 'f', 'g', 'h', 'i', 'j',
                                     'k', 'l', 'm', 'n', 'o', 'p',
                                     'q', 'r', 's', 't', 'u', 'v',
                                     'w', 'x', 'y', 'z', '0', '1',
                                     '2', '3', '4', '5', '6', '7',
                                     '8', '9', '+', '/' };

int main(int argc, char **argv)
{
    const char *text = "hello world";
    char *encode = NULL;
    char *decode = NULL;
    
    encode = base64_encode(text, strlen(text));

    if (encode == NULL)
        return 1;
    printf("encode : %s (%zd) \n", encode, strlen(encode));

    decode = base64_decode((const char *)encode, strlen(encode));
    if (decode == NULL)
        return 1;
    printf("decode : %s (%zd) \n", decode, strlen(decode));

    free(encode);
    free(decode);

    return 0;
}

char *base64_encode(const char *src, size_t length)
{
    char *encode = NULL;
    size_t outputlen = 4 * ((length+2) / 3);
    
    encode = (char *)malloc(outputlen+1);
    if (encode == NULL)
    {
        return NULL;
    }

    size_t input = 0, output = 0;
    unsigned char tbytes[3] = {0,};
    unsigned char fbytes[4] = {0,};

    while (length--)
    {
        tbytes[input++] = *(src++);
        if (input == 3)
        {
            // ex) 0x123456 (0001 0010    0011 0100    0101 0110)
            fbytes[0] = (tbytes[0] >> 2) & 0x3F;    // (0001 0010 >> 2) = 0100
                                                    // 0100 & 0011 1111 = 000100

            // 0x03 = 0011, 0x0F = 1111, 0x3F = 111111
            fbytes[1] = ((tbytes[0] & 0x03) << 4) | (tbytes[1] >> 4);
            fbytes[2] = ((tbytes[1] & 0x0F) << 2) | (tbytes[2] >> 6);
            fbytes[3] = tbytes[2] & 0x3F;

            size_t k = 0;
            for (k = 0; k < 4; k++)
            {
                encode[output++] = base64table[fbytes[k]];
            }
            input = 0;
        }
    }

    if (input)
    {
        size_t i = 0;
        for (i = input; i < 3; i++)
        {
            tbytes[i] = '\0';
        }

        fbytes[0] = (tbytes[0] >> 2) & 0x3F;
        fbytes[1] = ((tbytes[0] & 0x03) << 4) | (tbytes[1] >> 4);
        fbytes[2] = ((tbytes[1] & 0x0F) << 2) | (tbytes[2] >> 6);
        fbytes[3] = tbytes[2] & 0x3F;

        for (i = 0; i < input + 1; i++)
        {
            encode[output++] = base64table[fbytes[i]];
        }

        while (input++ < 3)
        {
            encode[output++] = '=';
        }
    }    

    encode[output] = '\0';   // null

    return encode;
}

char *base64_decode(const char *src, size_t length)
{
    // base64 encode 데이터는 4의 배수의 길이를 갖는다.
    if (src == NULL || length % 4 != 0)
    {
        return NULL;
    }

    char *decode = NULL;
    size_t i = 0;
    size_t output_len = (length / 4) * 3;

    // equal check
    if (src[length - 1] == '=') output_len--;
    if (src[length - 2] == '=') output_len--;

    decode = (char *)malloc(output_len+1);
    if (decode == NULL)
    {
        return NULL;
    }

    unsigned char fbytes[4] = {0,};
    unsigned char tbytes[3] = {0,};
    size_t input = 0, output = 0;
    for (i = 0; i < length; i++)
    {
        if (src[i] == '=')
        {
            fbytes[input++] = 0;
        }
        else
        {
            // 테이블에서 해당 문자 찾기
            const char *pos = strchr(base64table, src[i]);
            if (pos == NULL)
            {
                free(decode);
                return NULL;
            }
            fbytes[input++] = (unsigned char)(pos - base64table);

            // ex) aGVs (26 6 21 44)
            //      0001 1010/0000 0110/0001 0101/0010 1100
        }

        if (input == 4)
        {
            tbytes[0] = (fbytes[0] << 2) | (fbytes[1] >> 4);    // 1101000 | 0000 = 1101000
            tbytes[1] = ((fbytes[1] & 0x0F) << 4) | (fbytes[2] >> 2);
            tbytes[2] = ((fbytes[2] & 0x03) << 6) | fbytes[3];

            size_t k = 0;
            for (k = 0; k < 3 && output < output_len; k++)
            {
                decode[output++] = tbytes[k];
            }
            input = 0;
        }
    }

    decode[output_len] = '\0';  // null

    return decode;
}