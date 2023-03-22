#include <iostream>
#include "node.h"
using namespace std;
class Stack{
    public:
        void insert(int);
        void pop();
        void print();
        bool isEmpty();
        Stack();
    private:
        node* top;
};
Stack::Stack(){
    top = NULL;
}
void Stack::insert(int val){
    node* tmp = new node(val);
    tmp->next = top;
    top = tmp;     
}
void Stack::pop(){
    if(isEmpty()){
        cout << "nothing can print~\n";
        return;
    }
    node* tmp = top->next;
    delete tmp;
    top = tmp;
}
void Stack::print(){
    node* ptr = top;
    while(ptr){
        cout << ptr->val;
        ptr = ptr->next;
    }
    cout << endl;
}
bool Stack::isEmpty(){
    return top == NULL;
}

int main(){
    Stack st;
    st.pop();
    st.insert(2022);
    st.insert(10);
    st.insert(27);
    st.pop();
    st.print();
    return 0;
}