#include <iostream>
using namespace std;
struct node {
    int val;
    node* next;
    node() { next = NULL; }
    node(int val) {
        this->val = val;
        next = NULL;
    }
};
class link {
  public:
    void reverse();
    void insertAtHead(int);
    void delAtHead();
    void del(int);
    void print();
    link() {
        head = NULL;
        tail = NULL;
    }

  private:
    node* head;
    node* tail;
};
void link ::insertAtHead(int v) { // 空白有差嗎? 看來沒差
    if (!head) {
        head = tail = new node(v);
        return;
    }
    node* tmp = new node(v);
    tmp->next = head;
    head = tmp;
}
void link::delAtHead() {
    if (!head) {
        cout << "nothing!\n";
    }
    node* tmp = head->next;
    delete head;
    head = tmp;
}
void link::reverse() {
    node* pointed = NULL; //一值是head的前一個
    while (head != tail) {
        node* tmp = head->next;
        head->next = pointed;
        pointed = head;
        head = tmp;
    }
    head->next = pointed;
}
void link::print() {
    if (!head)
        return;
    node* tmp = head;
    while (tmp != NULL) {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
}
int main() {
    link mylink;
    mylink.insertAtHead(5);
    mylink.insertAtHead(4);
    mylink.insertAtHead(3);
    mylink.print();
    mylink.reverse();
    mylink.print();
    hh return 0;
}