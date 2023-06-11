#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solution(){
    string s; cin>>s;
    stack<string>st;
    for(int i=0;i<s.size();i++){
        string z=string(1,s[i]);
        if(z=="+"||z=="*"||z=="-"||z=="/"){
            string x=st.top(); st.pop();
            string y=st.top(); st.pop();
            st.push("("+y+z+x+")");
        }else st.push(z);
    }
    cout<<st.top()<<endl;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        Solution();
    }
    return 0;
}