#include <stdio.h>

// 用quicksort的技巧
// pivot每次交換的位置 即代表 第lptr位置
int main() {
    int n = 5;
    int arr[5] = {10, 5, 6, 4, 2}; // 2 4 5 6 10
    int k = 2;                     //我要第2大
    int L = 0, R = n - 1;
    if (k > n)
        return 0;
    while (1) {
        int lptr = L;
        int pivot = R;
        for (int i = L; i < R; i++) {
            if (arr[i] < arr[pivot]) {
                // swap
                int tmp = arr[lptr];
                arr[lptr] = arr[i];
                arr[i] = tmp;

                lptr++;
            }
        }
        printf("lptr: %d\n", lptr);
        // swap
        int tmp = arr[lptr];
        arr[lptr] = arr[pivot];
        arr[pivot] = tmp;
        printf("%d %d L:%d R: %d \n", arr[pivot], pivot, L, R);

        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");

        if (lptr == k - 1) {
            printf("%d", arr[lptr]);
            break;
        } else if (lptr > k)
            R = lptr - 1;
        else
            L = lptr + 1;
    }

    return 0;
}