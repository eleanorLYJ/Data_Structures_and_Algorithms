// 遍歷整張圖的節點
#include <iostream>
#include <queue>
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
void bfs() {
    queue<int> qu;
    qu.push(0);
    visited[0] = true;
    while (!qu.empty()) {
        int top = qu.front();
        qu.pop();
        cout << top << " ";
        for (int j = 0; j < N; j++) {
            if (matrix[top][j] && !visited[j]) {
                qu.push(j);
                visited[j] = true;
            }
        }
    }
}
int main() {
    init();
    matrix[0][1] = matrix[0][2] = matrix[1][2] = matrix[1][3] = true;
    bfs(); // 0 1 2 3
    return 0;
}