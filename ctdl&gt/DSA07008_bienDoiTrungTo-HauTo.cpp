#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int prior(char c){
    if(c=='^')return 4;
    if(c=='*'||c=='/')return 3;
    if(c=='+'||c=='-')return 2;
    return 1;
}

void Solution(){
    string s; cin>>s;
    stack<char>st;
    string res="";
    for(int i=0;i<s.size();i++){
        if(s[i]=='(')st.push(s[i]);
        else if(s[i]==')'){
            while(st.top()!='('){
                res+=st.top();
                st.pop();
            }
            st.pop();
        }else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^'){
            while(!st.empty()&&prior(st.top())>=prior(s[i])){
                res+=st.top();
                st.pop();
            }
            st.push(s[i]);
        }else res+=s[i];
    }
    while(!st.empty()){
        if(st.top()!='(')res+=st.top();
        st.pop();
    }
    cout<<res<<endl;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        Solution();
    }
    return 0;
}