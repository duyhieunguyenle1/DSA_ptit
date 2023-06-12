#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solution(){
    int s,d; cin>>s>>d;
    if(s>9*d||s==0){
        cout<<-1<<endl;
        return;
    }
    stack<int>st;
    s--;
    while(d--){
        if(s>=9){
            st.push(9);
            s-=9;
        }else if(s>0){
            st.push(s);
            s=0;
        }else st.push(0);
    }
    cout<<st.top()+1; st.pop();
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
    cout<<endl;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        Solution();
    }
    return 0;
}