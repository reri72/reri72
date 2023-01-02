#include <stdio.h>

#define COL 5
#define ROW 7
#define ZERO 0

int main(void)
{
    int array[ROW][COL];
    int row, element, total;
    int row_conut, col_count;

    row = sizeof(array[ZERO]);                      //4byte * 5 = 20byte
    element = sizeof(array[ZERO][ZERO]);            //4byte
    total = sizeof(array);                          //4byte * 5 * 7 = 140byte

    printf("row : %d \n", row);
    printf("element : %d \n", element);
    printf("total : %d \n\n", total);

    row_conut = total / row;                        //행 개수 = 배열의 총 크기 / 행 크기
    col_count = row / element;                      //열 개수 = 행 크기 / 요소 크기

    printf("row count : %d\n", row_conut);
    printf("col count : %d\n", col_count);

    return 0;
}