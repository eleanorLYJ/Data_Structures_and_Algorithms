// 遍歷整張圖的節點
#include <iostream>
#include <stack>
#define N 4 // 預設: 整張圖只有4節點
using namespace std;

bool matrix[N][N]; // adjacency matrix 不帶weight
bool visited[N];
void init() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matrix[i][j] = false;
        }
    }
}
void dfs() {
    stack<int> st;
    st.push(0);
    visited[0] = true;
    while (!st.empty()) {
        int top = st.top();
        st.pop();
        cout << top << " ";
        for (int j = N - 1; j >= 0; j--) {
            if (matrix[top][j] && !visited[j]) {
                st.push(j);
                visited[j] = true;
            }
        }
    }
}
int main() {
    init();
    matrix[0][1] = matrix[0][2] = matrix[1][2] = matrix[1][3] = true;
    dfs();
    return 0;
}