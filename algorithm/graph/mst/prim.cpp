#include <iostream>
#define n 5
using namespace std;

int matrix[n][n];
int d[n]; // distance
int parent[n];
bool isVisited[n];

void prim(int root) {
    d[root] = 0;
    parent[root] = root;

    while (true) {
        // mincost 紀錄當前選擇的最短路徑
        // minpos 紀錄當前決定的節點
        int mincost = 1e8, minpos = -1;
        // select the node closest to tree
        for (int i = 0; i < n; i++) {
            if (!isVisited[i] && mincost > d[i]) {
                minpos = i;
                mincost = d[i];
            }
        }
        // select no node!
        if (minpos == -1)
            break;
        // else:
        isVisited[minpos] = true;

        for (int i = 0; i < n; i++) {
            if (!isVisited[i] && matrix[minpos][i] < d[i]) {
                d[i] = matrix[minpos][i];
                parent[i] = minpos;
            }
        }
    }
}
int main() {
    // init
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            matrix[i][j] = 1e8;
    for (int i = 0; i < n; i++)
        d[i] = 1e8;
    for (int i = 0; i < n; i++)
        isVisited[i] = false;

    matrix[0][1] = matrix[1][0] = 1;
    matrix[0][2] = matrix[2][0] = 5;
    matrix[1][2] = matrix[2][1] = 7;
    matrix[1][3] = matrix[3][1] = 4;
    int root = 1;
    prim(root);
    int destination = 2;
    // 從destination 的parent，反著找回root。可以塞進stack後，再pop
    while (true) {
        cout << destination << endl;
        if (destination == root) {
            break;
        }
        destination = parent[destination];
    }
    return 0;
}