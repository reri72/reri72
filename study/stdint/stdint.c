#include <stdio.h>
#include <stdint.h>

int main(void){

    int8_t int8m = -128;            int16_t int16m = -32768;
    int32_t int32ma = 2147483647;   int64_t int64ma = 9223372036854775807;

    uint8_t uint8ma = 255;          uint64_t uint64ma = 18446744073709551615;

    printf("INT8_MIN : %d, %d \n",INT8_MIN, int8m);
    printf("INT16_MIN : %d, %d \n",INT16_MIN, int16m);
    printf("INT32_MIN : %d \n",INT32_MIN);
    printf("INT64_MIN : %lld \n",INT64_MIN);

    printf("INT8_MAX :%d \n", INT8_MAX);
    printf("INT16_MAX :%d \n", INT16_MAX);
    printf("INT32_MAX :%d %d \n", INT32_MAX, int32ma);
    printf("INT64_MAX :%lld %lld \n", INT64_MAX, int64ma);

    printf("UINT8_MAX : %u %u \n", UINT8_MAX, uint8ma);
    printf("UINT16_MAX : %u \n", UINT16_MAX);
    printf("UINT32_MAX : %u \n", UINT32_MAX);
    printf("UINT64_MAX : %llu %llu \n", UINT64_MAX, uint64ma);

    return 0;
}