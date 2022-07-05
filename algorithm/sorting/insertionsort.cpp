#include <iostream>
#include <vector>
using namespace std;
// 插入前方已排好的
// descend 
void insertion(vector<int>&vec){
    for(int i = 1; i < vec.size(); i++){
        int key = vec[i];
        int j = i-1; // 可能是key值要放的position
        while(j >= 0 && vec[j] < key){
            vec[j+1] = vec[j];
            j--;
        }
        vec[j+1] = key;
    }

}

int main(){
    vector<int>vec = {20, 22, 7, 5};
    insertion(vec);
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] <<" ";
    }
    return 0;
}