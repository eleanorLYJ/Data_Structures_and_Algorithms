#include <iostream>
using namespace std;
struct node {
    int val;
    node* left;
    node* right;
    node(int n) {
        this->val = n;
        this->left = NULL;
        this->right = NULL;
    }
};
// r開頭是用遞迴方式(recursive)實現方法
// i開頭是用迭代方式(iterative)實現方法
class bst {
  public:
    void i_insert(int n);
    void r_insert(int n) { recursive_insert(n, root); };
    void i_delete(int n);
    void r_delete(int n) { root = recursive_delete(n, root); }
    void inorder() { recursive_inorder(root); }
    void find_s(int n) {
        node* ans = fs(n, root);
        cout << ans->val;
    }
    bst() { root = NULL; }

  public:
    node* root;
    node* fs(int, node*);
    node* recursive_insert(int, node*);
    node* recursive_delete(int, node*);
    void recursive_inorder(node*); // return void is ok ?
};

void bst::i_insert(int n) {
    if (root == NULL) {
        root = new node(n);
        return;
    }
    node* ptr = root;
    node* pre_ptr = root;
    // find
    while (ptr != NULL) {
        pre_ptr = ptr;
        if (ptr->val > n) {
            ptr = ptr->left;
        } else { // ptr->val < n
            ptr = ptr->right;
        }
    }
    ptr = new node(n);
    // pre_ptr該往左指還是右指
    pre_ptr->val > n ? pre_ptr->left = ptr : pre_ptr->right = ptr;
}

node* bst::recursive_insert(int n, node* ptr) {
    if (!ptr) {
        return new node(n);
    }
    if (ptr->val > n) {
        ptr->left = recursive_insert(n, ptr->left);
    } else {
        ptr->right = recursive_insert(n, ptr->right);
    }
    return ptr;
}

void bst::i_delete(int n) {
    if (!root) {
        cout << "bst is empty\n";
        return;
    }
    // 如果要刪除的是根節點
    if (root->val == n) {
        // find successor
        node* s = root->right;
        node* pre_s = root;
        while (s && s->left) {
            pre_s = s;
            s = s->left;
        }
        // 根節點存在右子樹
        if (s) {
            root->val = s->val;
            // successor 有右子樹
            if (s->right)
                (pre_s->val > s->val) ? (pre_s->left = s->right)
                                      : (pre_s->right = s->right);
            else
                (pre_s->val > s->val) ? (pre_s->left = NULL)
                                      : (pre_s->right = NULL);
            delete s;
        }
        // if 根節點沒有右子樹 有左子樹
        else if (root->left) {
            node* tmp = root;
            root = root->left;
            delete tmp;
        } else { //沒有左右子樹
            delete root;
            root = NULL;
        }
        return;
    }

    node* ptr = root;
    node* pre_ptr = NULL;

    // find
    while (ptr != NULL && ptr->val != n) { // && !!!
        pre_ptr = ptr;
        if (ptr->val > n)
            ptr = ptr->left;
        else
            ptr = ptr->right;
    }
    if (!ptr) {
        cout << "not found!\n";
        return;
    }
    // check pre_ptr是該往左指還是往右
    // 0 is left ; 1 is right
    bool l_r = pre_ptr->val > n ? 0 : 1;
    // 沒有小孩
    if (!ptr->left && !ptr->right) {
        if (l_r)
            pre_ptr->right = NULL;
        else
            pre_ptr->left = NULL;
        delete ptr;
    }
    // 左小孩
    else if (!ptr->right) {
        if (l_r)
            pre_ptr->right = ptr->left;
        else
            pre_ptr->left = ptr->left;
    }
    //右小孩
    else if (!ptr->left) {
        if (l_r)
            pre_ptr->right = ptr->right;
        else
            pre_ptr->left = ptr->right;
    }
    // 有左右小孩
    else {
        // find sucessor
        node* s = ptr->right;
        node* pre_s = ptr;
        while (s->left) {
            pre_s = s;
            s = s->left;
        }
        ptr->val = s->val;

        // sucessor 有右小孩
        if (s->right) {
            if (pre_s->val > s->val)
                pre_s->left = s->right;
            else
                pre_s->right = s->right;
        }
        // sucessor 沒有右小孩
        else {
            if (pre_s->val > s->val)
                pre_s->left = NULL;
            else
                pre_s->right = NULL;
        }

        delete s;
    }
}
node* bst::recursive_delete(int n, node* ptr) {
    if (!ptr)
        return NULL;
    if (ptr->val > n)
        ptr->left = recursive_delete(n, ptr->left);
    else if (ptr->val < n)
        ptr->right = recursive_delete(n, ptr->right);
    // ptr->val == n
    else {
        // 沒有小孩
        if (!ptr->left && !ptr->right) {
            delete ptr;
            ptr = NULL;
        }
        // 右小孩
        else if (!ptr->left) {
            node* tmp = ptr;
            ptr = ptr->right;
            delete tmp;
        }
        // 左小孩
        else if (!ptr->right) {
            node* tmp = ptr;
            ptr = ptr->left; // =.=
            delete tmp;
        }
        // 有左右小孩
        else {
            // find successor
            node* s = ptr->right;
            while (s->left) {
                s = s->left;
            }
            ptr->val = s->val;
            ptr->right = recursive_delete(s->val, ptr->right);
        }
    }
    return ptr;
}
void bst::recursive_inorder(node* p) {
    if (!p)
        return;
    recursive_inorder(p->left);
    cout << p->val << " ";
    recursive_inorder(p->right);
}
int main() {
    bst a;
    a.i_insert(5);
    a.i_insert(2);
    a.r_insert(6);
    a.i_insert(10);
    a.r_insert(8);
    a.r_delete(5); // delete root with rchild and lchiild
    a.inorder();   // 2 6 8 10
    cout << "\n----\n";
    a.r_delete(10); // delete node with lchild
    a.inorder();    // 2 6 8
    cout << "\n----\n";
    a.i_insert(1);
    a.i_insert(3);
    a.r_delete(2); // delete the node with rchild and lchiild
    a.inorder();   // 1 3 6 8
    cout << "\n----\n";
    a.i_insert(7);
    a.find_s(6);
    return 0;
}