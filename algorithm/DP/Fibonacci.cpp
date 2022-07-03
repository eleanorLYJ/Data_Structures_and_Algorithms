#include <iostream>
#define maxsize 100
using namespace std;

int arr[maxsize];
void f(int val){
    
    arr[0] = 0;
    arr[1] = 1;
    for(int i = 2 ; i <= val ; i++){ //也可以計算到maxsize
        arr[i] = arr[i-1] + arr[i-2];
    }
    cout << arr[val] <<" ";

}


int main(){
    f(7);
    f(3);
    return 0;
}