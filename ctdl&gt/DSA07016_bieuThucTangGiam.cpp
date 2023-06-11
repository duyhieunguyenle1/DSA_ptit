#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solution(){
    string s; cin>>s;
    stack<string>st;
    st.push("1");
    int cnt=2;
    for(int i=0;i<s.size();i++){
        string temp=to_string(cnt);
        if(s[i]=='I'){
            // cout<<<<" ";
            st.push(temp);
        }
        else if(s[i]=='D'){
            string x=st.top(); st.pop();
            st.push(temp+x);
        }
        cnt++;
    }
    while(st.size()!=1){
        string x=st.top(); st.pop();
        string y=st.top(); st.pop();
        st.push(y+x);
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