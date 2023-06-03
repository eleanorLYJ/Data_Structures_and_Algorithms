#include <iostream>
#include <vector>
#define number 6
using namespace std;

// 遞迴轉移式: f(i, j, k) = min( f(i, k, k-1) + f(k, j, k-1), f(i, j, k-1) )
// DP轉移是:　d[i,j] = min(d[i,j], d[i,k] + d[k,j]) (k = 1,2,...,n)　可把k省略

// adjacency matrix
vector<vector<int>> matrix(number, vector<int>(number, 1e8));

void init() {
    for (int i = 0; i < number; i++) {
        matrix[i][i] = 0;
    }
}
void floydWarchall() {

    for (int k = 0; k < matrix.size(); k++)
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix.size(); j++)
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]);
}

void printAllPath() {
    for (int i = 0; i < number; i++) {
        for (int j = 0; j < number; j++) {
            if (matrix[i][j] != 1e8)
                printf("%2d ", matrix[i][j]);
            else {
                printf("%2s ", "X");
            }
        }
        cout << endl;
    }
}

int main() {
    init();
    // origin:
    matrix[0][1] = matrix[1][0] = 1;
    matrix[0][2] = matrix[2][0] = 5;
    matrix[1][2] = matrix[2][1] = 7;
    matrix[1][3] = matrix[3][1] = 4;
    matrix[2][4] = matrix[4][2] = 2;
    matrix[3][5] = matrix[5][3] = 5;
    printf("origin: \n");
    printAllPath();

    floydWarchall();

    printf("result \n");
    printAllPath();
    // origin:
    //  0  1  5  X  X  X
    //  1  0  7  4  X  X
    //  5  7  0  X  2  X
    //  X  4  X  0  X  5
    //  X  X  2  X  0  X
    //  X  X  X  5  X  0
    // result
    //  0  1  5  5  7 10
    //  1  0  6  4  8  9
    //  5  6  0 10  2 15
    //  5  4 10  0 12  5
    //  7  8  2 12  0 17
    // 10  9 15  5 17  0
    return 0;
}