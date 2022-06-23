#ifndef NODE_H
#define NODE_H
#include <iostream>
using namespace std;
struct node{
    int val;
    node* next;
    node();
    node(int);
    node(int, node*);
};
#endif