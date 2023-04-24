#include<bits/stdc++.h>
using namespace std;
int main(){
    stack<int>st;
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        int n;
        if(s=="PUSH"){
            cin>>n;
            st.push(n);
        }
        if(s=="POP"){
            if(!st.empty()){
                st.pop();
            }
        }
        if(s=="PRINT"){
            if(!st.empty()){
                cout<<st.top()<<endl;
            }else{
                cout<<"NONE\n";
            }
        }
    }
}