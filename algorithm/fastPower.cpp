#include <iostream>
using namespace std;
// a^b
// calculte a^b for base a and exponent b

// 更詳細概念:https://oi-wiki.org/math/binary-exponentiation/

// a^5 = a^1 * a^4
// a^101 = a^1 * a^100

// a自己乘自己，會跑b的位數次，不管b是否bit =
// 1，每一round，a會變平方，也就是次方*2 用二進位看b，假如b = 3 =
// 011，從右至左，遇到bit = 1 就乘a
long long fastPower(int a, int b) {
    long long ans = 1;
    while (b > 0) {
        // 0 & 1  = 0
        // 1 & 1 = 1
        // &1 的作用跟 %2 相同
        if (b & 1) {
            ans = ans * a;
        }
        a = a * a;
        // >>= 1 的作用 與/2相同
        b >>= 1;
    }
    return ans;
}
int main() {
    int a = 5, b = 3;
    cout << fastPower(a, b); // 125
}