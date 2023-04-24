#include<bits/stdc++.h>
using namespace std;
int a[100],n,check[100]={0};

void print(){
    for(int i=1;i<=n;i++)cout<<char(a[i]+64);
    cout<<" ";
}
void Try(int k){
    for(int i=1;i<=n;i++){
        if(!check[i]){
            a[k]=i;
            check[i]=1;
            if(k==n)print();
            else {
                Try(k+1);
            }
            check[i]=0;
        }
    }
}
int main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        n=s.size();
        Try(1);
        cout<<endl;
    }
}