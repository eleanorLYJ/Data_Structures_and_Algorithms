#include <stdio.h>

// quickselect同用quicksort的技巧
// 抽象想法:
// 比pivot小的往左移動，比pivot大的往右丟，最終pivot與比pivot小中最大的位置+1(或大中最小的-1)交換
// 結果pivot每次交換的位置 即代表 第lptr位置
// 平均時間複雜度: O(n)
// 適用top k考題 (成大資管有出過)
int main() {
    int n = 5;
    int arr[5] = {10, 5, 6, 4, 2}; // 2 4 5 6 10
    int k = 2;                     //我要第2大
    int L = 0, R = n - 1;
    if (k > n)
        return 0;
    while (1) {
        int lptr = L;
        int pivot = R; // pivot選擇最右的陣列元素
        for (int i = L; i < R; i++) {
            if (arr[i] < arr[pivot]) {
                // swap
                int tmp = arr[lptr];
                arr[lptr] = arr[i];
                arr[i] = tmp;

                lptr++;
            }
        }
        // swap
        int tmp = arr[lptr];
        arr[lptr] = arr[pivot];
        arr[pivot] = tmp;

        // 看每一回合移動了哪些
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