#include <iostream>
#include "node.h"
using namespace std;

class queue{
    public:
        void push(int);
        void pop();
        bool isEmpty();
        void print();
        queue(){
            tail = head = NULL;
        }
    private:
        node* tail;
        node* head;
};
// queue::queue(){
//     tail = head = NULL;
// }
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
        cout <<"there is empty~";
        return;
    }
    if(head == tail){
        head = tail = NULL;
        return;
    }
    node* tmp = head;
    head = head->next;
    delete tmp;
    tmp = NULL;
}
bool queue::isEmpty(){
    return head == NULL and tail == NULL;
}
void queue::print(){
    if(isEmpty()){
        cout << "nothing can print";
        return;
    }
    else if(head == tail){ // only one node
        cout << head->val;
        return;
    }
    else{
        cout << head->val <<" ";
        node* ptr = head->next;
        while(ptr != tail){
            cout << ptr->val <<" ";
            ptr = ptr->next;
        }
        cout << tail->val;
    }

}
int main(){
    queue qu;
    qu.push(22);
    qu.pop();
    qu.push(6);
    qu.push(23);
    qu.print();
    return 0;
}