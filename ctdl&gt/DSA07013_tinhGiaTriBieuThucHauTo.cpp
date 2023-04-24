#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll calc(ll y,ll x, char z){
    switch (z){
    case '+':
        return x+y;
    case '-':
        return x-y;
    case '*':
        return x*y;
    case '/':
        return x/y;
    }
}

void Solve(string s){
    stack<ll>st;
    for(int i=0;i<s.size();i++){
        if(s[i]!='+'&&s[i]!='/'&&s[i]!='*'&&s[i]!='-')st.push(s[i]-'0');
        else {
            ll x=st.top(); st.pop();
            ll y=st.top(); st.pop();
            st.push(calc(x,y,s[i]));
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