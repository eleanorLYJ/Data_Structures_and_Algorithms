#include <iostream>
#include <vector>
using namespace std;

// static hash function: division method
// solve overflow function: liear probing
class hashStruct{
    public:
        bool isExsit(int); //input: key
        void push(int,int); //input: key,val
        void pop(int); // input: key
        int get(int); //input: key ,output: val
        hashStruct();
    private:
        vector<pair<int,int>>h; //note: class 裡的宣告時不可以有執行語句，so call constructer
        vector<int>vis;
        int mod = 2;
        int vec_size = 3;
        // static hash function
        int hash(int);
        //input: key ,output: the empty position, if (that output is -1) mean caanot find!
        int linear_probing_to_find_empty_pos(int);
        //input: key, output: key position, if (that output is -1) mean caanot find!
        int linear_probing_to_find_key_position(int);
};
hashStruct::hashStruct(){
    h = vector<pair<int,int>>(vec_size,pair<int,int>(0,0));
    vis = vector<int>(13,0);
}
int hashStruct::hash(int key){
    return key % mod;
}
int hashStruct::linear_probing_to_find_empty_pos(int key){
    int origin = hash(key);
    int pos = 1;
    while((origin+pos)%vec_size != origin){
        //find the empty position!
        if(!vis[(origin+pos)%vec_size]){
            return (origin+pos)%vec_size;
        }
        else{
            pos += 1;
        }
    }
    return -1; //mean : vector is full!
}
//return key position
int hashStruct::linear_probing_to_find_key_position(int key){
    int origin = hash(key);
    int pos = 1;
    int try_pos = (origin+pos)%vec_size;
    while(try_pos != origin && vis[try_pos]){
        if(h[try_pos].first == key){
            return try_pos;
        }else{
            pos += 1;
            try_pos = (origin+pos)%vec_size;
        }
    }
    cout << "i don't find it\n";
    return -1;
}


bool hashStruct::isExsit(int key){
    int origin = hash(key);
    if(h[origin].first == key){
        return true;
    }else{
        return (linear_probing_to_find_key_position(key) != -1);
    }
}
void hashStruct::push(int key, int val){
    int origin = hash(key);
    if(vis[origin]){
        cout << "overflow happen! ";
        int pos = linear_probing_to_find_empty_pos(key);
        if(pos != -1){
            h[pos].first = key;
            h[pos].second = val;
            vis[pos] = 1;
            cout << " but success push! \n";
        }else{
            cout << "fail!\n"; //because it is full!
        }
    }
    else{
        h[origin].first = key;
        h[origin].second = val;
        vis[origin] = 1;
        cout << "push success!\n";
    }        
}
void hashStruct::pop(int key){
    int origin = hash(key);
    if(h[origin].first != key){
        int pos = linear_probing_to_find_key_position(key);
        if(pos != -1){
            vis[pos] = 0;
        }
    }
    else{
        vis[origin] = 0;
    }
}
int hashStruct::get(int key){
    int origin = hash(key);
    if(h[origin].first == key){
        return h[origin].second;
    }else{
        int pos = linear_probing_to_find_key_position(key);
        if(pos != -1){
            return h[pos].second;
        }
        return pos; //mean : it is not Exist!
    }
}
int main(){
    hashStruct ha;
    ha.push(1,7);
    ha.push(2,8);
    ha.push(3,9);
    ha.push(4,10);
    cout <<"isExsit : "<< ha.isExsit(4) <<endl;
    cout <<"get : " << ha.get(3) <<endl;
    return 0;
}