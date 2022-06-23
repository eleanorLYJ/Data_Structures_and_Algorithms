#include "node.h"
node::node(){
    this->val = 0;
    this->next = NULL;
}
node::node(int val){
    this->val = val;
    this->next = NULL;
}
node::node(int val , node* next){
    this->val = val;
    this->next = next;
}