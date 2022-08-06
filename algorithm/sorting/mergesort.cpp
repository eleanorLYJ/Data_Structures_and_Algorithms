#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>&arr, int l, int r){
    // split to smallest piece
    if(l >= r)
        return;
    int mid = l+(r-l)/2; // avoid a + b > INT_MAX
    merge(arr, l, mid);
    merge(arr,mid+1,r);

    // reform the numbers between arr[l] and arr[r]
    vector<int>tmp;
    int ptrL = l, ptrR = mid+1;
    
    while(ptrL <= mid && ptrR <=r){
        if(arr[ptrL] > arr[ptrR]) tmp.push_back(arr[ptrR++]);
        else tmp.push_back(arr[ptrL++]); 
    }
    while(ptrL <= mid){
        tmp.push_back(arr[ptrL++]);
    }
    while(ptrR <= r){
        tmp.push_back(arr[ptrR++]);
    }
    for(int i = 0; i < tmp.size(); i++){
        arr[l+i] = tmp[i];
    }
}
int main(){
    vector<int>vec = {20,22,8,2};
    merge(vec, 0, vec.size()-1);
    for(int v: vec){
        cout << v <<" ";
    }
    return 0;
}