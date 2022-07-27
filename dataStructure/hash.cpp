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
        hashStruct();
    private:
        vector<pair<int,int>>h; //class 裡的宣告時不可以有執行語句，不可以直接寫call constructer
        vector<int>vis;
        int mod = 13;
        int vec_size = 13;
        int hash(int);
};
int hashStruct ::hash(int key){
    return key % mod;
}
hashStruct::hashStruct(){
    h = vector<pair<int,int>>(vec_size,pair<int,int>(0,0));
    vis = vector<int>(13,0);
}
bool hashStruct::isExsit(int key){
    if(h[hash(key)].first == key){
        return true;
    }else{
        int pos = key + 1;
        //(hash(key)+pos)%vec_size should be repaced XDDD 
        while((hash(key)+pos)%vec_size != hash(key) && vis[(hash(key)+pos)%vec_size]){
            if(h[(hash(key)+pos)%vec_size].first == key){
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
        while((hash(key)+pos)%vec_size != hash(key)){
            if(!vis[(hash(key)+pos)%vec_size]){
                h[(hash(key)+pos)%vec_size].first = key;
                h[(hash(key)+pos)%vec_size].second = val;
                vis[(hash(key)+pos)%vec_size] = 1;
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
        while((hash(key)+pos)%vec_size != hash(key) && vis[hash(pos)]){
            if(h[(hash(key)+pos)%vec_size].first == key){
                vis[(hash(key)+pos)%vec_size] = 0;
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
        while((hash(key)+pos)%vec_size != hash(key) && (hash(key)+pos)%vec_size){
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