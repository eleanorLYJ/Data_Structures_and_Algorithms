// // 題目:
// https://sites.google.com/site/zsgititit/home/jin-jiec-cheng-shi-she-ji/a290-xin-shou-xun-lian-xi-lie-tu-lun

#include <iostream>
#include <stack>
#include <vector>
using namespace std;
bool matrix[100][100];
bool visited[100];
// 用stack模擬dfs
bool dfs(int A, int B) {
    if (A == B)
        return true;
    stack<int> st;
    st.push(A);
    visited[A] = true;
    while (!st.empty()) {
        int top = st.top();
        st.pop();
        for (int j = 0; j < 100; j++) {
            if (matrix[top][j] && !visited[j]) {
                if (B == j) {
                    return true;
                }
                st.push(j);
                visited[j] = true;
            }
        }
    }
    return false;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        int i, j;
        for (int k = 0; k < m; k++) {
            cin >> i >> j;
            matrix[i][j] = true;
        }
        int A, B;
        cin >> A >> B;
        dfs(A, B) ? cout << "yes!!!" : cout << "no!";
    }
    return 0;
}
