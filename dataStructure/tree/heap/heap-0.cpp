#include <iostream>
#define n 10
using namespace std;
// array版本的min-heap
// 從index-0開始
class Heap {
  public:
    int peek();
    void insert(int);
    void del();
    void heapify(int*, int);
    void print();
    Heap();

  private:
    int arr[n];
    int num; // heap中有的個數
};
//   0
//   1     2
// 3  4   5  6

// parent = (i-1)/2
// left child = i*2+1
// right child = i*2+2

// construction
Heap::Heap() {
    for (int i = 0; i < n; i++) {
        arr[i] = 0;
    }
    num = 0;
}

int Heap::peek() { return arr[0]; }

void Heap::insert(int val) {
    if (num >= n) {
        printf("Heap is full\n");
        return;
    }
    arr[num] = val;
    // 向上比較
    int ptr = num; //指向val當前的索引值
    while (ptr > 0 && arr[ptr] < arr[(ptr - 1) / 2]) {
        // swap
        int tmp = arr[ptr];
        arr[ptr] = arr[(ptr - 1) / 2];
        arr[(ptr - 1) / 2] = tmp;

        ptr = (ptr - 1) / 2;
    }
    num++;
}
void Heap::del() {
    if (num == 0) {
        printf("Heap is empty\n");
    }
    // 根結點與陣列最後一值交換
    arr[0] = arr[num - 1];
    // 少一個值
    num -= 1;
    // 從根結點向下比較
    int ptr = 0;
    while (true) {
        int minPtr = ptr, lptr = (ptr * 2) + 1, rptr = (ptr * 2) + 2;
        // 選最小的值 (自己值、左右小孩)
        if (lptr <= num - 1 && arr[lptr] < arr[minPtr]) { // 註記大小於!
            minPtr = lptr;
        }
        if (rptr <= num - 1 && arr[rptr] < arr[minPtr]) {
            minPtr = rptr;
        }
        if (minPtr == ptr)
            break;

        // swap
        int tmp = arr[ptr];
        arr[ptr] = arr[minPtr];
        arr[minPtr] = tmp;

        ptr = minPtr;
    }
}
void Heap::heapify(int* a, int a_size) {
    num = a_size;
    for (int i = num - 1; i >= 0; i--) {
        //向下比較 // 也就是把del()的程式碼拿來用
        int ptr = i;
        while (true) {
            int minPtr = ptr, lptr = (ptr * 2) + 1, rptr = (ptr * 2) + 2;
            // 選最小的值 (自己值、左右小孩)
            if (lptr <= num - 1 && a[lptr] < a[minPtr]) {
                minPtr = lptr;
            }
            if (rptr <= num - 1 && a[rptr] < a[minPtr]) {
                minPtr = rptr;
            }
            if (minPtr == ptr)
                break;

            // swap
            int tmp = a[ptr];
            a[ptr] = a[minPtr];
            a[minPtr] = tmp;

            ptr = minPtr;
        }
    }
    // assign進arr裡
    for (int i = 0; i < num; i++) {
        arr[i] = a[i];
    }
}
void Heap::print() {
    for (int i = 0; i < num; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    Heap a;
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.print(); // 4 3 2 1
    cout << "max Value: " << a.peek() << endl;
    a.del();
    a.print(); // 3 1 2
    int arr[4] = {5, 6, 4, 1};
    a.heapify(arr, 4);
    a.print();
    return 0;
}