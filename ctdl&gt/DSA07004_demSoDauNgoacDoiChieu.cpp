#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve(string s){
    int open=0,close=0;
    stack<char>st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            open++;
            st.push(s[i]);
        }else{
            if(!st.empty()&&st.top()=='('){
                open--;
                st.pop();
            }else{
                close++;
                st.push(s[i]);
            }
        }
    }
    int res= open/2 +close/2; // mỗi cặp đóng mở ngoặc chỉ cần đảo ngược 1 dấu
    res+=open%2+close%2; // nếu có cặp ngoặc trái hướng, cần đảo cả 2
    cout<<res<<endl;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        string s; cin>>s;
        Solve(s);
    }
    return 0;
}