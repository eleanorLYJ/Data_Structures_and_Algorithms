#include <iostream>
#include <list>
using namespace std;

struct Node {
    int val;
    Node *Lptr, *Rptr;
    Node(int v) {
        this->val = v;
        this->Lptr = NULL;
        this->Rptr = NULL;
    }
};

void levelOrder(Node* root) {
    if (!root)
        return;
    list<Node*> li = {root};
    while (li.size() > 0) {
        Node* tmp = li.front();
        li.pop_front();

        cout << tmp->val << " "; // 把pop出的值 印出來，

        if (tmp->Lptr) // not NULL
            li.push_back(tmp->Lptr);
        if (tmp->Rptr)
            li.push_back(tmp->Rptr);
    }
    return;
}
// 除了levelorder的順序外，還區分出第i層level有哪些值
// 跟levelOrder() 只差有while loop裡還有一個while loop
void print_Level_nodes_levelOrder(Node* root) {
    if (!root)
        return;
    list<Node*> li = {root};
    int level = 1; // level of root = 1
    while (li.size() > 0) {
        int s = li.size(); // 要做紀錄，因為下面push後 size會更動
        // 印第幾層中 有哪些值
        cout << "level" << level++ << ": ";
        while (s--) {
            Node* tmp = li.front();
            li.pop_front();
            cout << tmp->val << " "; // 把pop出的值 印出來，
            if (tmp->Lptr)           // not NULL
                li.push_back(tmp->Lptr);
            if (tmp->Rptr)
                li.push_back(tmp->Rptr);
        }
        cout << endl;
    }
    return;
}

int main() {
    // build a tree
    //     5
    // 2      3
    //       1
    Node* root = new Node(5);
    root->Lptr = new Node(2);
    root->Rptr = new Node(3);
    root->Rptr->Lptr = new Node(1);
    levelOrder(root);

    cout << "\n~~~~~~~~~~~dividing line~~~~~~~~~\n";
    print_L_levelOrder(root);
    return 0;
}