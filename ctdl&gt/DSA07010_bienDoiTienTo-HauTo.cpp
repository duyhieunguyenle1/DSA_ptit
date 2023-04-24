#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solve(string s){
    stack<string>st;
    for(int i=s.size()-1;i>=0;i--){
        string tmp = string(1,s[i]);
        if(s[i]!='-'&&s[i]!='+'&&s[i]!='*'&&s[i]!='/')st.push(tmp);
        else {
            string x=st.top(); st.pop();
            string y=st.top(); st.pop();
            string z=x+y+tmp;
            st.push(z);
        }
    }
    cout<<st.top()<<endl;
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