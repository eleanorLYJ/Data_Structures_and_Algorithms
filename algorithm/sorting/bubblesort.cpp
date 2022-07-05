#include <iostream>
#include <vector>
using namespace std;
//兩兩交換
void bubble(vector<int>&vec){
    for(int i = 0; i < vec.size(); i++){
        for(int j = 0; j < vec.size()-1; j++){
            if(vec[j] > vec[j+1])
                swap(vec[j],vec[j+1]);
        }
    }
}
int main(){
    vector<int>vec = {20, 22, 7, 5};
    bubble(vec);
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] <<" ";
    }
    return 0;
}