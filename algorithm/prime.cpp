#include <iostream>
#define n 20000
using namespace std;
// create a prime table which size is 20000
bool table[n];

int main() {
    for (int i = 2; i < n; i++) {
        table[i] = true;
    }
    table[0] = false;
    table[1] = false;
    for (int i = 2; i < n; i++) {
        if (table[i]) {
            for (int j = i * i; j < n;
                 j++) { // 唯一要注意的是可能 i*i 會超過int整數的
                if (j % i == 0) {
                    table[j] = false;
                }
            }
            // 寫法二:
            // 開根號的方式避免超過整數的最大限制，並且
            // +0.5後無條件捨去，避免浮點數的誤差 for(int i = 2; i <=
            // floor(sqrt(n) +0.5); i++){
            //     if(j%i == 0){
            //         table[j] = false;
            //     }
            // }
        }
    }
    cout << table[7] << endl;
    cout << table[30] << endl;

    return 0;
}