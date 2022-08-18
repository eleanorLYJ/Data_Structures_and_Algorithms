#include <iostream>
#include <vector>
using namespace std;

//閉區間
void quicksort(int L, int R, vector<int>&vec){
    if(L >= R)return;
    int pivot = vec[R];
    int ptr = L; //the position of the value (smaller then pivot) 
    for(int i = L; i < R; i++){
        if(vec[i] <= pivot){
            swap(vec[ptr++], vec[i]);
        }
    }
    swap(vec[ptr], vec[R]);
    quicksort(L, ptr-1, vec);
    quicksort(ptr+1, R, vec);
}

int main(){
    vector<int>vec = {3,7,8,5,2,1,9,5,4};  
    quicksort(0, vec.size()-1, vec);
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] << " ";
    }
    return 0;
}