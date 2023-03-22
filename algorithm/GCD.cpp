#include <iostream>
using namespace std;

int gcd(int r1, int r2){
	if(r2 == 0)return r1;
	return gcd(r2, r1%r2);
}
int main(){
    cout << 37674315591%3;
    return 0;
}