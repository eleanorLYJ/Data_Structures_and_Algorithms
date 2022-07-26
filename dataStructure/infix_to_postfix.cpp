#include <iostream>
#include <stack>
using namespace std;
//https://sites.google.com/site/zsgititit/home/jin-jiec-cheng-shi-she-ji/d016-hou-xu-yun-suan-fa
//運算子包含 + - * / % 等五個
int main(){
    string str;
    stack<int>st;
    getline(cin,str);
    for(int i = 0; i < str.size(); i++){
        int ans = 0;
        if (str[i] == ' ') continue;
        else if(str[i] >= '0' && str[i] <= '9'){
            st.push(str[i]-'0');
        }
        else if(str[i] == '+'){
            int top = st.top(); st.pop();
            int top2 = st.top(); st.pop();
            ans = top2 + top;
            st.push(ans);
        }
        else if(str[i] == '-'){
            int top = st.top(); st.pop();
            int top2 = st.top(); st.pop();
            ans = top2 - top;
            st.push(ans);
        }
        else if(str[i] == '*'){
            int top = st.top(); st.pop();
            int top2 = st.top(); st.pop();
            ans = top2 * top;
            st.push(ans);
        }
        else if(str[i] == '/'){
            int top = st.top(); st.pop();
            int top2 = st.top(); st.pop();
            ans = top2 / top;
            st.push(ans);
        }
        else{
            int top = st.top(); st.pop();
            int top2 = st.top(); st.pop();
            ans = top2 % top;
            st.push(ans);
        }
    }
    
    cout << st.top();
    return 0;
}