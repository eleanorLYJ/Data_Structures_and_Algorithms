#include <iostream>
using namespace std;

// n-1 disks move to mid tower
// the biggest disk moves to the target tower

void hanoi(int n, char from, char mid, char to ){
    if(n == 1){
        cout << from << " move to " << to << endl;
        return;
    }
    hanoi(n-1,from, to, mid);
    cout << from << " move to " << to << endl;
    hanoi(n-1,mid, from, to);
}
int main(){
    int n = 3;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}