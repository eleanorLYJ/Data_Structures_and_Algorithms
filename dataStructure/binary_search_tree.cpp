#include <iostream>
using namespace std;

// 寫了 insert跟 delete 各寫了iterative版 與recursive版的

struct node{
    int val;
    node* left;
    node* right;
    node(int n){
        this->val = n;
        this->left = NULL;
        this->right = NULL; 
    }
};
class bst{
    public:
        void insert(int);
        void r_insert(int n) { recursive_insert(n, root); }
        void del(int);
        void r_del(int n){ root = r_delete(n,root);}
        void r_traversal(){ recursive_traversal(root);}
        bst();
    private:
        node* root;  
        node* recursive_insert(int, node*);
        void recursive_traversal(node*);
        node* r_delete(int, node*);
};

bst::bst(){
    root = NULL;
}
void bst::insert(int n){
    if(!root){
        root = new node(n);
        return;
    }
    node* ptr = root;
    node* pre_ptr = root;
    
    while(true){
        if(ptr->val < n){
            pre_ptr = ptr;
            ptr = ptr-> right;
            if(!ptr){
                ptr = new node(n);
                pre_ptr-> right = ptr;
                break;
            }
        }
        else{
            pre_ptr = ptr;
            ptr = ptr-> left;
            if(!ptr){
                ptr = new node(n);
                pre_ptr-> left = ptr;
                break;
            }
        }
    }
}
node* bst::recursive_insert(int n, node* ptr){
    if(!ptr){
        ptr = new node(n);
        return ptr;
    }
    if(ptr->val > n) ptr->left = recursive_insert(n, ptr->left);
    else ptr->right = recursive_insert(n, ptr->right);
    return ptr;
}
void bst::del(int n){
    if(!root){
        cout << "bst is empty\n";
        return;
    }
    if(!root->left && !root->right){
        delete root;
        root = NULL;
    }
    // find
    node* ptr = root;
    node* pre_ptr = root;
    bool found = false;
    // search
    while(ptr){
        if(ptr->val == n){
            found = true;
            break;
        }
        pre_ptr = ptr;
        if(ptr-> val > n){
            ptr = ptr->left;
        }
        else{
            ptr = ptr->right;
        }
    }
    if(!found) return;
    // 無小孩
    if(!ptr->left && !ptr->right){
        ptr = NULL;
        delete ptr;
        pre_ptr->val > n? pre_ptr->left = NULL: pre_ptr->right = NULL;
        
    }
    //有右小孩
    else if(!ptr->left && ptr->right){
        pre_ptr->val > n? pre_ptr->left = ptr->right: pre_ptr->right = ptr->right;
        delete ptr;
    }
    // 有左小孩
    else if(ptr->left && !ptr->right){
        pre_ptr->val > n? pre_ptr->left = ptr->left: pre_ptr->right = ptr->left;
        delete ptr; 
    }
    else{ // 有左右小孩
        // find the successor
        node* s = ptr->right;
        node* pre_s = ptr; // =.=
        while(s->left){
            pre_s = s;
            s = s->left;
        }
        //換掉val而已，因為原本的左右小孩不能被換掉
        ptr->val = s->val;
        // sucessor若有右小孩
        if(s->right){
            pre_s->val > s->val ? pre_s->left = s->right:   pre_s->right = s->right;
        } 
        delete s;
    }
}
node* bst::r_delete(int n, node* root){
    if(!root){
        return root;
    }
    if(root->val == n){
        // 無小孩
        if(!root->left && !root->right){
            delete root;
            root = NULL;
        }
        // 有左小孩
        else if(!root->right){
            node* tmp = root;
            root = root->left;
            delete tmp;
        }
        // 有右小孩
        else if(!root->left){
            node* tmp = root;
            root = root->right;
            delete tmp;
            //為麼錯??? 因為root的前一個沒將指向root的pointer設成NULL?-
        }
        else{
            //find sucessor(s)
            node* s = root->right;
            while(s->left){
                s = s->left;
            }
            //change the val
            root-> val = s->val;
            // delete the leftest node in the right tree
            root->right = r_delete(s->val, root->right);
        }
        
    }
    else if(root->val > n){
        root->right = r_delete(n, root->right);
    }
    else{
        root->left = r_delete(n, root->left);
    }
    return root;
}
void bst::recursive_traversal(node* root){
    node* ptr = root;
    if (!ptr){
        return;
    }
    if(ptr->left) recursive_traversal(ptr->left);
    cout << ptr->val << " ";
    if(ptr->right) recursive_traversal(ptr->right);
}

int main(){
    bst a;
    a.insert(5);
    a.r_insert(10);
    a.insert(3);
    a.r_insert(15);
    cout << "before delete:"; 
    a.r_traversal();
    cout << endl;
    cout << "after delete: ";
    a.r_del(5); // or a.del(5)
    a.r_traversal();
    cout << endl;
    return 0;
}