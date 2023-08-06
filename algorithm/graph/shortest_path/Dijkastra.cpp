#include <iostream>
using namespace std;
#define number 6

int matrix[number][number]; // weight
int parent[number];
int visited[number];
int dist[number]; //與source的距離

void dijkstra(int source) {
    dist[source] = 0;
    while (true) {
        int vertex = -1; //當前節點
        int near = 1e8;  //找目前最短距離
        //挑選
        for (int i = 0; i < number; i++) {
            if (!visited[i] && dist[i] < near) {
                vertex = i;
                near = dist[i];
            }
        }
        if (vertex == -1) { //找不到節點 搜尋完畢
            break;
        }
        visited[vertex] = true;
        //把 vertex 附近 且未曾走過的edge做 relaxtion
        for (int i = 0; i < number; i++) {
            if (!visited[i] && dist[i] > dist[vertex] + matrix[vertex][i]) {
                dist[i] = dist[vertex] + matrix[vertex][i];
                parent[i] = vertex;
            }
        }
    }
}
void init() {
    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++)
            matrix[i][j] = 1e8;
    }
    for (int i = 0; i < number; i++) {
        parent[i] = i; //自己是parent
    }
    for (int i = 0; i < number; i++) {
        dist[i] = 1e8;
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
    int source = 0;
    dijkstra(source);
    //看5到0的最短路徑
    int vertex = 5;
    cout << "reversed path: ";
    while (true) {
        if (vertex == source) {
            break;
        } else if (vertex == parent[vertex]) {
            cout << "cannot reach!";
            break;
        } else {
            vertex = parent[vertex];
            cout << vertex << " ";
        }
    }
    // output: 3 1 0
    return 0;
}