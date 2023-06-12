#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

string solve(string s){
    stack<int>st;
    for(int i=0;i<s.size();i++){
        if(s[i]=='('){
            st.push(i);
        }else if(s[i]==')'){
            if(st.top()!=0&&s[st.top()-1]=='-'){
                for(int j=st.top();j<i;j++){
                    if(s[j]=='+')s[j]='-';
                    else if(s[j]=='-')s[j]='+';
                }
            }
            st.pop();
        }
    }
    string res="";
    for(int i=0;i<s.size();i++){
        if(s[i]!='('&&s[i]!=')')res+=s[i];
    }
    return res;
}

void Solution(){
    string s,t; cin>>s>>t;
    cout<<(solve(s)==solve(t)?"YES\n":"NO\n");
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        Solution();
    }
    return 0;
}