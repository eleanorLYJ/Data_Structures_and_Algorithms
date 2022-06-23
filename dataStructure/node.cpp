#include <iostream>
using namespace std;
struct node{
    int val;
    node* next;
    node(){
        this->val = 0;
        this->next = NULL;
    }
    node(int val){
        this->val = val;
        this->next = NULL;
    }
    node(int val , node* next){
        this->val = val;
        this->next = next;
    }
};
