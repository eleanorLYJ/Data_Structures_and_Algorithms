#include <iostream>
#define size 10
using namespace std;
class disjoin{
    public:
        void join(int, int);
        int find(int);
        void print();
        disjoin(){
            //自己是自己的祖先
            for(int i = 0; i < size; i++){
                arr[i] = i;
            }
        }
    private:
        int arr [size];
};

void disjoin::join(int a, int b){
    if(find(arr[a]) != find(arr[b])){
        // b的祖先變a的祖先
        arr[find(arr[b])] = find(arr[a]);
    }else{
        cout << "already in the same component\n";
    }
}

int disjoin::find(int n){
    while(arr[n] != n){
        n = arr[n];
    }
    return n;
    // 遞迴寫法
    // x == group[x] ? x : (p[x] = find(p[x]));
}
void disjoin::print(){
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    disjoin d;
    d.join(5,4);
    d.join(5,3);
    d.join(3,4);
    d.print();
    return 0;
}