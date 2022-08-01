#include <iostream>
using namespace std;

bool binary_search(int arr [], int target,  int l, int r){
    if(l >= r)
        return false;
    
    int mid = l +(r-l)/2 ; // avoid a+b > INT_MAX
    if(arr[mid] == target){
        return true;
    }
    else if(arr[mid] > target){
        return binary_search(arr, target, l, mid-1);    
    }else{
        return binary_search(arr, target, mid+1, r);
    }
}
int main(){
    int arr[5] = {20, 22, 8, 1, 2006};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << binary_search(arr, 200, 0, size);
    return 0;
}