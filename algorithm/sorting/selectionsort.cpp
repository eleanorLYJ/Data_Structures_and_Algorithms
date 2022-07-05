#include <iostream>
#include <vector>
using namespace std;
//挑第i大
// descend
void selection(vector<int>&vec){
    for(int i = 0; i < vec.size(); i++){
        int max_val_pos = i;
        for(int j = i + 1; j < vec.size(); j++){
            if(vec[max_val_pos] < vec[j]){
                max_val_pos = j;
            }
        }
        swap(vec[max_val_pos],vec[i]);
    }
}
int main(){
    vector<int>vec = {20, 22, 7, 5};
    selection(vec);
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i] <<" ";
    }
    return 0;
}