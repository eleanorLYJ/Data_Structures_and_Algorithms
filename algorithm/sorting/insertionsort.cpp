#include <iostream>
#include <vector>
using namespace std;
// 插入前方已排好的
// descend
void insertion(vector<int>& vec) {
    for (int i = 1; i < vec.size(); i++) {
        int key = vec[i];
        int j = i - 1; // 可能是key值要放的position
        while (j >= 0 && vec[j] < key) {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}
/*bad version (time complexity)*/
void bad_insertion(vector<int>& vec) {
    int n = vec.size();
    for (int i = 1; i < n; i++) {
        int pre = i - 1;
        while (pre >= 0 && vec[pre] < vec[pre + 1]) {
            swap(vec[pre], vec[pre + 1]);
            pre -= 1;
        }
    }
}

int main() {
    vector<int> vec = {20, 22, 7, 5};
    insertion(vec);
    // bad_insertion(vec);
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    return 0;
}