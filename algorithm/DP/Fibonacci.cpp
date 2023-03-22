#include <iostream>
#include <vector>
#define maxsize 100
using namespace std;

vector<int> arr(maxsize, 0);

// recursive
int f(int val) {
    if (val == 0 || val == 1)
        return val;
    return f(val - 1) + f(val - 2);
}

// top-down (memoization)
int td_f(int val) {
    if (arr[val] != 0)
        return arr[val];
    if (val == 0 || val == 1)
        return val;
    return arr[val] = f(val - 1) + f(val - 2);
}

// bottom up
int bu_f(int val) {
    arr[0] = 0;
    arr[1] = 1;
    for (int i = 2; i <= val; i++) { //也可以計算到maxsize
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    return arr[val];
}

int main() {
    cout << f(7) << endl;    // 13
    cout << td_f(7) << endl; // 13
    cout << bu_f(7) << endl; // 13
    return 0;
}