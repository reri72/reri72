#include <stdio.h>

/*
    정렬된 배열에서 원하는 값을 찾는 간단한 이진 탐색 코드임
    => 반드시 오름차순 또는 내림차순으로 정렬된 배열에만 올바르게 동작

    시간 복잡도 :
        최선 O(1)           -> 첫 번째 중간값에서 바로 찾는 경우
        평균/최악 O(log n)  -> 탐색 범위를 매 단계마다 ^절반^으로 줄이기 때문

    공간 복잡도 :
        반복문 구현 O(1)    -> 고정된 변수만 사용하므로
        재귀호출로 구현할 경우 호출 스택 때문에 O(log n)

*/
int binary_search(const int arr[], int n, int target)
{
    int left = 0;
    int right = n - 1;

    while (left <= right)
    {
        int mid = left + (right-left) / 2;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            // 내림차순이면 arr[mid] > target
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }

    return -1;
}

int main(int argc, char *argv[])
{
    (void)argc;
    (void)argv;

    int arr[] = {1,3,5,7,9,11,13,15,17,19}; // 오름차순
    int n = sizeof(arr) / sizeof(arr[0]);

    int idx = binary_search(arr, n, 13);

    if (idx >= 0)
    {
        printf("%d번째 index 에서 발견\n", idx);
    }
    else
    {
        printf("index 찾지 못함");
    }

    return 0;
}
