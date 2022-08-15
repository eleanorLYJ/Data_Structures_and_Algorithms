#include <iostream>
#define n 20000
using namespace std;
// create a prime table which size is 20000 
bool table[n];

int main(){
    for(int i = 2; i < n; i++){
        table[i] = true;
    }
    table[0] = false;
    table[1] = false;
    for(int i = 2; i < n; i++){
        if(table[i]){
            for(int j = i*i; j < n; j++){
                if(j%i == 0){
                    table[j] = false;
                }
            }
        }
    }
    cout << table[7] <<endl; 
    cout << table[30] << endl;

        
    return 0;
}