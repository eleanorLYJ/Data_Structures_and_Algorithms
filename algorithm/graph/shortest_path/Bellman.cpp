#include <iostream>
#include <stack>
#define number 6
using namespace std;

// 遞迴轉移式: d[i,j] = min(d[i,j], d[i-1,k] + w[k,j])  (k = 1,2,...,n)

int matrix[number][number]; // adjacency matrix
int dist[number];   // Record the shortest path length from the starting node to
                    // each node
int parent[number]; // Record who is the parent of each node on the shortest
                    // path tree
bool negative = false; // having negative weight cycle
void init() {
    for (int i = 0; i < number; i++) {
        dist[i] = 1e8;
    }
    for (int i = 0; i < number; i++) {
        parent[i] = i;
    }
    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {
            matrix[i][j] = 1e8;
        }
    }
}
void bellman_ford(int source) {
    dist[source] = 0; // Set the shortest path length for the origin
    // parent[source] = source; // the parent is itself

    for (int i = 0; i < number - 1; i++) // Repeat iterate V-1 times
        for (int a = 0; a < number; a++) // 全部的邊都當作捷徑
            for (int b = 0; b < number; b++)
                if (dist[a] != 1e8 && matrix[a][b] != 1e8 &&
                    dist[a] + matrix[a][b] < dist[b]) { // a是加進樹裡，b還沒
                    dist[b] = dist[a] + matrix[a][b];
                    parent[b] = a;
                }

    // chack the negative weight cycle
    // 也就是全部掃過，如果比當前結果更好，便代表有負環
    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {
            if (matrix[i][j] != 1e8 && dist[i] != 1e8 &&
                dist[j] > dist[i] + matrix[i][j]) {
                cout << "negative weight cycle!" << endl;
                negative = true;
                break;
            }
        }
        // 跳出雙層迴圈
        if (negative)
            break;
    }
    return;
}
void printPath(int source, int target) {
    if (negative)
        return;
    stack<int> path;
    int now = target;
    bool flag = true; // check whether the valid path
    while (true) {
        path.push(now);
        if (now == source)
            break;
        if (now == parent[now]) {
            flag = false;
            cout << "cannot reach! \n";
            break;
        }
        now = parent[now];
    }
    cout << "path: ";
    while (flag && !path.empty()) {
        cout << path.top() << " ";
        path.pop();
    }
}
int main() {
    init();
    matrix[0][1] = matrix[1][0] = 1;
    matrix[0][2] = matrix[2][0] = 5;
    matrix[1][2] = matrix[2][1] = 7;
    matrix[1][3] = matrix[3][1] = 4;
    matrix[2][4] = matrix[4][2] = 2;
    matrix[3][5] = matrix[5][3] = 5;

    bellman_ford(0); // source node is 0
    printPath(0, 5);
    return 0;
}
