#include <iostream>
#include <vector>
#define size 13
using namespace std;


class hashStruct{
    public:
        bool isExsit(int); //key
        void push(int,int);
        void pop(int); // key
        int find(int);
    private:
        vector<pair<int,int>>h = vector<pair<int,int>>(13,pair<int,int>(0,0));//class 裡的宣告時不可以有執行語句，不可以直接寫call constructer
        vector<int>vis = vector<int>(13,0);
        int mod = 13;
        int hash(int key){
            return key % mod;
        }
};
bool hashStruct::isExsit(int key){
    if(h[hash(key)].first == key){
        return true;
    }else{
        int pos = key + 1;
        while(hash(pos) != hash(key) && vis[hash(pos)]){
            if(h[hash(pos)].first == key){
                return true;
            }
            pos += 1;
        }
        cout << "i cannot find!\n";
        return false;
    }
}
void hashStruct::push(int key, int val){
    if(vis[hash(key)]){
        cout << "overflow happen!\n";
        int pos = key + 1;
        while(hash(pos) != hash(key)){
            if(!vis[hash(pos)]){
                h[hash(pos)].first = key;
                h[hash(pos)].second = val;
                vis[hash(pos)] = 1;
                return;
            }
            pos += 1;
        }
        cout << "all is full \n";
    }
    else{
        h[hash(key)].first = key;
        h[hash(key)].second = val;
        vis[hash(key)] = 1;
        cout << "push success!\n";
    }        
}
void hashStruct::pop(int key){
    if(h[hash(key)].first != key){
        int pos = key + 1;
        // linear probing
        while(hash(pos) != hash(key) && vis[hash(pos)]){
            if(h[hash(pos)].first == key){
                vis[hash(pos)] = 0;
                return;
            }
            pos += 1;
        }
        cout << "i don't find it\n";
    }
    else{
        vis[hash(key)] = 0;
    }
}
int hashStruct::find(int key){
    if(h[hash(key)].first == key){
        return h[hash(key)].second;
    }else{
        int pos = key + 1;
        while(hash(pos) != hash(key) && vis[hash(pos)]){
            if(h[hash(pos)].first == key){
                return h[hash(pos)].second;
            }
            pos += 1;
        }
        cout << "i cannot find!\n";
        return 0;
    }
}
int main(){
    hashStruct ha;
    ha.push(12,5);
    ha.push(25,3);
    cout << ha.isExsit(2) <<" ";
    cout << ha.find(12);
    return 0;
}