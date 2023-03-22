#include <iostream>
#include <string>
using namespace std;

bool isPalidrome(string str) {
    int len = str.size();
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            return false;
        }
    }
    return true;
}
int main() {
    cout << isPalidrome("ABA") << endl;  // 1
    cout << isPalidrome("BABB") << endl; // 0
    cout << isPalidrome("BAAB") << endl; // 1
    return 0;
}