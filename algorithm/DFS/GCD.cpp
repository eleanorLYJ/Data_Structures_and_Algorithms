# include <iostream>
using namespace std;

// a is bigger than b
int GCD(int a, int b){ 
    if(b == 0) return a;
    return GCD(b, a%b);
}

int main(){
    cout << GCD(22,6) << endl;
    cout << GCD(6,29) << endl;
    return 0;
}