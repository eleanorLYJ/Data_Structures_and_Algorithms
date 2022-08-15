#include <iostream>
#include <algorithm>
using namespace std;

bool binary_search(int arr [], int target,  int len){
    int L = 0, R = len -1;
    bool flag = false; //record wheather find the target
    while(L <= R){
        int mid = (L + R) / 2;
        if(arr[mid] == target){
            flag = true;
            break;
        }
        else if(arr[mid] > target){
            R = mid - 1;
        }
        else{
            L = mid + 1;
        }
    }
    return flag;
}
int main(){
    int arr[5] = {20, 22, 8, 1, 2006};
    int size = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+5);
    cout << binary_search(arr, 1, size) << endl; // true;
    cout << binary_search(arr, 2, size) << endl; // false;
    return 0;
}