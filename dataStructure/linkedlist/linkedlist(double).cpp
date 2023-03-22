#include <iostream>
using namespace std;
struct doubleNode{
    int v;
    doubleNode* pre;
    doubleNode* next;
    doubleNode(int v){
        this->pre = this->next = NULL;
        this->v = v;
    }
};
class linkedlist{
    public:
        void insertHead(int);
        void insertTail(int);
        void delHead();
        void delTail();
        void print();// from head to tail;
        linkedlist();
    private:
        doubleNode* head;
        doubleNode* tail; 
};
linkedlist::linkedlist(){
    head = tail = NULL;
};
void linkedlist::insertHead(int val){
    if(!head){
        head = tail = new doubleNode(val);
        return;
    }
    doubleNode* node = new doubleNode(val);
    node->next = head;
    node->pre = tail;
    head->pre = node;
    tail->next = node;
    head = node;
}
void linkedlist::insertTail(int val){
    if(!tail){
        head = tail = new doubleNode(val);
        return;
    }
    doubleNode* node = new doubleNode(val);
    node->next = head;
    node->pre = tail;
    head->pre = node;
    tail->next = node;
    tail = node;
}
void linkedlist::delHead(){
    if(!head){
        cout << "nothing~ \n";
    }else if(head == tail){
        doubleNode* tmp = head;
        head = tail = NULL;
        delete tmp;
    }else{
        doubleNode* tmp = head->next;
        tail->next = tmp;
        tmp->pre = tail;
        delete head;
        head = tmp;
    }
}
void linkedlist::delTail(){
    if(!tail){
        cout << "nothing~ \n";
    }else if(head == tail){
        doubleNode* tmp = tail;
        head = tail = NULL;
        delete tmp;
    }else{
        doubleNode* tmp = tail->pre;
        head->pre = tmp;
        tmp->next = head;
        delete tail;
        tail = tmp;
    }
}
void linkedlist::print(){
    if(!head){
        cout << "nothing!";
        return;
    }
    doubleNode* tmp = head;
    while(tmp != tail){
        cout << tmp->v <<" ";
        tmp = tmp->next;
    }
    cout << tail->v;
    cout << endl;
}

int main(){
    linkedlist li;
    li.insertHead(6);
    li.insertHead(22);
    li.insertTail(29);
    li.print();
    li.delHead();
    li.print();
    return 0;
}