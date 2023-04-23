#include <iostream>
#include <stack>
using namespace std;
// 題目: https://sites.google.com/site/zsgititit/home/jin-jiec-cheng-shi-she-ji/d016-hou-xu-yun-suan-fa
//運算子包含 + - * / % 等五個
int main(){
    string str;
    stack<int>st;
    getline(cin,str);

    //to handle >9 number
    bool pre_is_num = false;
    for(int i = 0; i < str.size(); i++){
        if(str[i] == ' '){
            if(pre_is_num){
                pre_is_num = false;
            }
        }
        else if(str[i] >= '0' && str[i] <= '9'){
            int num;
            if(pre_is_num){
                num = st.top();
                st.pop();
                num = num * 10 + (str[i] - '0');
            }else{ //pre is not num
                num = str[i] - '0';
            }
            st.push(num);
            pre_is_num = true;
        }

        else if(str[i] == '+'){
            int top = st.top(); st.pop();
            int top2 = st.top(); st.pop();
            st.push(top2 + top);
        }
        else if(str[i] == '-'){
            int top = st.top(); st.pop();
            int top2 = st.top(); st.pop();
            st.push(top2 - top);
        }
        else if(str[i] == '*'){
            int top = st.top(); st.pop();
            int top2 = st.top(); st.pop();
            st.push(top2 * top);
        }
        else if(str[i] == '/'){
            int top = st.top(); st.pop();
            int top2 = st.top(); st.pop();
            st.push(top2 / top);
        }
        else{
            int top = st.top(); st.pop();
            int top2 = st.top(); st.pop();
            st.push(top2 % top);
        }
    }
    
    cout << st.top();
    return 0;
}