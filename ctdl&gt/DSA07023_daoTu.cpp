#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    cin.ignore();
    while(t--){
        string s; getline(cin,s);
        s+=" ";
        stack<string>st;
        string temp="";
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                st.push(temp);
                temp="";
            }else {
                temp+=s[i];
            }
        }
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
        cout<<endl;
    }
}