#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool isSign(char c){
    return (c=='+'||c=='-'||c=='*'||c=='/');
}

void Solution(){
    string s; cin>>s;
    stack<string>st;
    for(char i:s){
        string z="";
        if(isSign(i)){
            string x=st.top(); st.pop();
            string y=st.top(); st.pop();
            z=y+i+x;
        }else z+=i;
        st.push(z);
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