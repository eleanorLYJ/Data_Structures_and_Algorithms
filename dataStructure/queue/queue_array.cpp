#include <iostream>
#define size 5 // arr size = 5
using namespace std;

class queue{
        public:
        void push(int);
        void pop();
        bool isEmpty();
        bool isFull();
        void print();
        queue();
    private:
        int head,tail;
        int arr[size];
};

queue::queue(){
    head = 0;
    tail = -1;
}
void queue::push(int val){
    if(isFull()){
        cout << "full \n";
        return;
    }
    arr[++tail] = val;
}
void queue::pop(){
    if(isEmpty()){
        cout << "empty \n";
        return;
    }
    head++;
}
void queue::print(){
    if(isEmpty()){
        cout <<"empty~ \n";
        return;
    }
    int ptr = head;
    while(ptr != tail){
        cout << arr[ptr] <<" ";
        ptr++;
    }
    cout << arr[tail];
}
bool queue::isEmpty(){
    return head == tail+1;
}
bool queue::isFull(){
    return tail == size;
}
int main(){
    queue q;
    q.push(6);
    q.pop();
    q.print();
    q.push(22);
    q.push(6);
    q.push(26);
    q.print();
    return 0;
}