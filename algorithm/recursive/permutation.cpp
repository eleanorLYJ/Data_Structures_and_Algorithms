#include <iostream>
#include <string>
using namespace std;

// list all rearrangement of string n of distinct characters

void perm(string str, bool visited[], int pos, string ans) {
    if (pos <= 0) {
        cout << ans << " ";
        return;
    }
    for (int i = 0; i < str.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            perm(str, visited, pos - 1, ans + str[i]);
            visited[i] = false;
        }
    }
}

int main() {
    string str, ans = "";
    cin >> str;                           // 123
    bool* visited = new bool[str.size()]; // bool visited [str.size()];
    // initiation
    for (int i = 0; i < str.size(); i++) {
        visited[false];
    }
    perm(str, visited, str.size(), ans); // 123 132 213 231 312 321
    return 0;
}