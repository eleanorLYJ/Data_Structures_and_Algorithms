#include <iostream>
#define size 100
using namespace std;
// 從index-1開始的maxheap

    // i
//i*2    i*2+1

class Heap{
    public:
        void insert(int);
        void pop();
        int getMaxValue();
        void heapify(int *, int); // int arr[], int t (tail of arr) 
        void print(); 
        Heap();
    private:
        int h[size];
        int tail;
};

Heap::Heap(){
    tail = 0;
}

void Heap::insert(int val){
    if(tail >= size-1){
        cout << "sorry! Heap is Full! \n";
        return;
    }
    // add val to tail
    h[++tail] = val;
    int ptr = tail; // avoid changing tail
    while(ptr/2 >= 1 && h[ptr/2] < h[ptr]){
        swap(h[ptr/2],h[ptr]);
        ptr = ptr/2;
    }
    return;
}

void Heap::pop(){
    if(tail == 0){
        cout << "sorry! Heap is empty!\n";
        return;
    }
    //swap head value and tail value
    swap(h[1], h[tail]);
    tail--;
    int head = 1;
    while(head <= tail){
        int bigger = head;
        // choose the child which is bigger than val of head
        // mention : boundary!! 
        if(head*2+1 <= tail && h[head*2+1] > h[bigger]) bigger = head*2+1;
        if(head*2 <= tail && h[head*2] > h[bigger]) bigger = head*2;
        // if head val is bigger than children, break the loop  
        if(bigger == head) break;
        swap(h[head],h[bigger]);
        head = bigger;
    }
}

int Heap::getMaxValue(){
    return h[1];
}

void Heap::heapify(int* arr, int len){
    tail = len;
    for(int i = tail; i >= 1; i--){
        int ptr = i;
        while(true){
            // choose the child which is bigger than ptr
            int left = ptr*2, right = ptr*2+1, bigger = ptr;
            if(left <= tail && arr[bigger] < arr[left]) bigger = left;
            if(right <= tail && arr[bigger] < arr[right]) bigger = right;
            if(bigger == ptr) break;
            swap(arr[bigger],arr[ptr]);
            ptr = bigger;
        }
    }
    // assign to h
    for(int i = 1; i <= tail ; i++){
        h[i] = arr[i];
    }
}

void Heap::print(){ 
    for(int i = 1; i <= tail ; i++){
        cout << h[i] << " ";
    }
    cout << endl;
}

int main(){
    Heap a;
    a.insert(1);
    a.insert(2);
    a.insert(3);
    a.insert(4);
    a.print(); // 4 3 2 1
    cout << "max Value: "<< a.getMaxValue() << endl;
    a.pop();
    a.print(); // 3 1 2
    int arr [4] = {0, 4, 5, 6};
    a.heapify(arr, 3);
    a.print(); // 6 5 4
    return 0;
}