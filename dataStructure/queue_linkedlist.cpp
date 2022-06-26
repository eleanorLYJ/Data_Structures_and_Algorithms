#include <iostream>
#include "node.h"
using namespace std;

class queue{
    public:
        void push(int);
        void pop();
        bool isEmpty();
        void print();
        queue();
    private:
        node* tail;
        node* head;
};
queue::queue(){
    tail = head = NULL;
}
void queue::push(int v){
    if(isEmpty()){
        tail = head = new node(v);
        return;
    }
    node* tmp = new node(v);
    tail->next = tmp;
    tail = tmp;
}
void queue::pop(){
    if(isEmpty()){
        cout <<"there is empty~\n";
    }
    else if(head == tail){
        head = tail = NULL;
    }else{
        node* tmp = head;
        head = head->next;
        delete tmp;
    }
}
bool queue::isEmpty(){
    return head == NULL and tail == NULL;
}
void queue::print(){
    if(isEmpty()){
        cout << "nothing can print\n";
        return;
    }
    node* ptr = head;
    while(ptr){
        cout << ptr->val <<" ";
        ptr = ptr->next;
    }
    cout << endl;
}
int main(){
    queue qu;
    qu.push(22);
    qu.push(6);
    qu.push(23);
    qu.pop();
    qu.print();
    return 0;
}