#include<bits/stdc++.h>
using namespace std;
void backTrack(int a[],int n,stack<string>&st){
    if(n==0)return ;
    string s="";
    s+="[";
    for(int i=0;i<n;i++){
        if(i==n-1){
            s+=to_string(a[i]);
            s+="]";
        }
        else {
            s+=to_string(a[i]);
            s+=" ";
        }
    }
    s+=" ";
    st.push(s);
    for(int i=0;i<n-1;i++){
        a[i]=a[i]+a[i+1];
    }
    backTrack(a,n-1,st);
}
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        stack<string>st;
        backTrack(a,n,st);
        while(st.size()){
            cout<<st.top();
            st.pop();
        }
        cout<<endl;
    }
}