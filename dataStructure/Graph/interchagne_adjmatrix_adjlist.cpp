#include <iostream>
#include <vector>
#define N 3
using namespace std;

// 互轉
// adjacency list、matrix用vector<vector<int>>去實現 (不考慮權重~)

vector<vector<int>> adj_list(N);
vector<vector<int>> adj_matrix(N, vector<int>(N)); // 類似於: int arr[N][N]

void list_to_matrix() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (adj_matrix[i][j] != 0) {
                adj_list[i].push_back(j);
            }
        }
    }
    return;
}

void print_adjlist() {
    for (int i = 0; i < N; i++) {
        cout << "index: " << i << " | ";
        for (int j = 0; j < adj_list[i].size(); j++) {
            cout << "-- " << adj_list[i][j] << " ";
        }
        cout << endl;
    }
}
void clear_matrix() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            adj_matrix[i][j] = 0;
        }
    }
}
void matrix_to_list() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < adj_list[i].size(); j++) {
            int j_pos = adj_list[i][j];
            adj_matrix[i][j_pos] = 1;
        }
    }
}

void print_matrix() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << adj_matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int main() {
    adj_matrix[0][1] = adj_matrix[0][2] = adj_matrix[1][2] = 1;
    list_to_matrix();
    print_adjlist();
    cout << " ~~~~~~~ dividing line ~~~~~~~~~~~~~\n";
    clear_matrix();
    matrix_to_list();
    print_matrix();

    return 0;
}