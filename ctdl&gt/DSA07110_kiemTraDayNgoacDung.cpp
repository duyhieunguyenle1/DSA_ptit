#include<bits/stdc++.h>
using namespace std;

string Solution(string &s){
    stack<char> st;
    for(char &i : s){
        if(i == '(' or i == '[' or i == '{') st.push(i);
        else
        {
            if(i == ')')
            {
                if(st.size() and st.top() == '(') st.pop();
                else return "NO";
            }
            else if(i == ']')
            {
                if(st.size() and st.top() == '[') st.pop();
                else return "NO";
            }
            else
            {
                if(st.size() and st.top() == '{') st.pop();
                else return "NO";
            }
        }
    }
    if(st.size()) return "NO";
    return "YES";
}

int main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        cout<<Solution(s)<<endl;
    }
}