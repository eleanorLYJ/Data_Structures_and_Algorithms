#include <iostream>
#include "node.h"
using namespace std;
class stack{
    public:
        void push(int);
        void pop();
        bool isEmpty();
        void print();
        stack(){
            top = NULL;
        }
    private:
        node* top;
};
void stack::push(int val){
    // node* tmp = new node(val);
    // tmp->next = top;
    node* tmp = new node(val,top);
    top = tmp;
}
void stack::pop(){
    if(isEmpty()){
        cout << "stack is empty. you cannot pop!";
        return;
    }
    node* tmp = top;
    top = top->next;
    delete tmp;
    tmp = NULL;
}
bool stack::isEmpty(){
    return (top == NULL);
}
void stack::print(){
    node* tmp = top;
    while(tmp){
        cout << tmp->val <<" ";
        tmp = tmp->next;
    }
}
int main(){
    stack st;
    st.push(14);
    st.push(5);
    st.push(23);
    st.pop();
    st.print();
    return 0;
}