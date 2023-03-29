#include <stdio.h>
// 中正109計概
// calculte b^e for input base b and exponent e in C lnguage
// 另外解請看fastPower的程式碼
int a(int b, int e) {
    int ans = 1;
    while (e--) {
        ans *= b;
    }
    return ans;
}
int main() {
    int b = 2, e = 3;
    printf("%d", a(b, e));
    return 0;
}