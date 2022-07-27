#include <iostream>
#include <vector>
#define size 13
using namespace std;


class hashStruct{
    public:
        bool isExsit(int); //key
        void push(int,int);
        void pop(int); // key
        void find(int);
        hashStruct();
    private:
        vector<pair<int,int>>h;
    // protect:? 
};
hashStruct::hashStruct(){
    for(int i =0; i <13; i++){
        pair<int,int>tmp(0,0);
        h.push_back(tmp);
    }
}
bool hashStruct::isExsit(int key){
    for(int i = 0; i < size; i++){
        if(h[i].first == key){
            cout << key <<" exsit\n";
            return true;
        }
    }
    cout << "no exsit\n";
    return false;
}
void hashStruct::push(int key, int val){
    if(h[key%size].second != 0){
        cout << "overflow happen!\n";
        int pos = key + 1;
        while(pos%size != key%size){
            if(h[pos%size].second == 0){
                h[pos%size].first = key;
                h[pos%size].second = val;
                return;
            }
            pos += 1;
        }
        cout << "all is full \n";
    }
    else{
        h[key%size].first = key;
        h[key%size].second = val; 
        cout << "push success!\n";
    }        
}
void hashStruct::pop(int key){
    if(h[key%size].first != key){
        int pos = key + 1;
        while(pos%size != key%size){
            if(h[pos%size].first == key){
                h[pos%size].first = 0;
                h[pos%size].second = 0;
                return;
            }
            pos += 1;
        }
        cout << "i don't find it\n";
    }
    else{
        h[key%size].first = 0;
        h[key%size].second = 0;
    }
}
void hashStruct::find(int key){
    if(h[key%size].first == key){
        cout << h[key%size].second;
        return;
    }else{
        int pos = key + 1;
        while(pos%size != key%size){
            if(h[pos%size].first == key){
                cout << h[pos%size].second <<endl;
                return;
            }
            pos += 1;
        }
        cout << "i cannot find!\n";
    }
}
int main(){
    hashStruct ha;
    ha.push(12,5);
    ha.push(25,3);
    ha.isExsit(25);
    ha.find(25);
    return 0;
}