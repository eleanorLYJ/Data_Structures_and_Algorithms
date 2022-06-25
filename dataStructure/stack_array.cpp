#include <iostream>
#define size 5
using namespace std;
class stack{
    public:
        void push(int);
        void pop();
        bool isEmpty();
        void print();
        stack();
    private:
        int top;
        int st[size]; // max size = 5
};

stack::stack(void){
    top = -1;
} 

void stack::push(int val){
    if(top >= size){
        cout << "there is full!\n";
        return;
    }
    st[++top] = val;
}

void stack::pop(){
    if(isEmpty()){
        cout << "there is empty!\n";
        return;
    }
    top--;
}
bool stack::isEmpty(){
    return top == -1;
}
void stack::print(){
    for(int i = top ; i >=0 ; i--){
        cout << st[i] <<" ";
    }
}

int main(){
    stack s;
    s.push(6);
    s.push(25);
    s.pop();
    cout << s.isEmpty()<<" ";
    s.print();
    return 0;
}