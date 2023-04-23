#include <iostream>
#include <vector>
using namespace std;

struct node {
    bool isTerminal;
    node* child[26];
    node() {
        isTerminal = false;
        for (int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};
node* root;
void addWord(string str) {
    node* cur = root;
    for (auto ch : str) {
        if (!cur->child[ch - 'a'])
            cur->child[ch - 'a'] = new node();
        cur = cur->child[ch - 'a'];
    }
    cur->isTerminal = true;
}
// str存走過的節點
void dfs(node* n, string str, vector<string>& vec) {
    if (!n)
        return; //!!
    if (n->isTerminal) {
        vec.push_back(str);
    }
    for (int i = 0; i < 26; i++) {
        if (n->child[i]) {
            char c = i + 'a';
            dfs(n->child[i], str + c, vec);
        }
    }
}

vector<string> prefix(string str) {
    vector<string> record;
    node* cur = root;
    for (int i = 0; i < str.size(); i++) {
        if (cur->child[str[i] - 'a']) {
            cur = cur->child[str[i] - 'a'];
        } else {
            cout << "your prefix not find";
            exit(1); // error code = 1
        }
    }
    dfs(cur, str, record);
    return record;
}

int main() {
    root = new node();
    addWord("sa");
    addWord("sn");
    addWord("as");
    vector<string> vec = prefix("a");
    for (auto v : vec) {
        cout << v << " ";
    }
    return 0;
}