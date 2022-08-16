#include <iostream>
#define size 100
using namespace std;
    // i
//i*2    i*2+1

// maxheap
// maxheap[0] has nothing.
class Heap{
    public:
        void insert(int);
        void pop();
        int getMaxValue();
        bool isFull();
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
    // swap head value and tail value

    swap(h[1],h[tail]);
    tail--;
    int bigger, head = 1;
    while(head > tail){
        // compare left child and right child 
        if(h[head*2] > h[head*2+1] ) bigger = head*2;
        else bigger = head*2+1;
        // if head val is bigger than children, break the loop  
        if(h[head] > h[bigger]) break;
        else{
            swap(h[head],h[bigger]);
            head = bigger;
        }
    }
}

int Heap::getMaxValue(){
    return h[1];
}

void Heap::heapify(int* arr, int len){
    tail = len;
    for(int i = tail; i >= 1; i--){
        while(true){
            int left = ptr*2, right = ptr*2+1, int cur = i;
            if(right <= tail && arr[ptr] < max(arr[left],arr[right])){
                if(arr[left] > arr[right]){
                    swap(arr[ptr], arr[left]);
                    ptr = left;
                }
                else{
                    swap(arr[ptr], arr[right]);
                    ptr = right;
                }
            }
            else if(left == tail && arr[ptr] < arr[left]){
                swap(arr[left], arr[ptr]);
                break;
            }
            else{
                break;
            }
        }
    }
    // assign to h
    for(int i = 1; i <= tail; i++){
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
    cout << "max Value: "<< a.getMaxValue() << endl;
    a.pop();
    a.print(); // 2 1
    int arr [4] = {0,4,5,6};
    a.heapify(arr, 3);
    a.print(); // 6 5 4
    return 0;
}