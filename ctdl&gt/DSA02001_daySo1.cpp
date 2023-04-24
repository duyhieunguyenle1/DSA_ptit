#include<bits/stdc++.h>
using namespace std;
void backTrack(int a[],int n){
    if(n==0)return ;
    cout<<"[";
    for(int i=0;i<n;i++){
        if(i==n-1)cout<<a[i]<<"]";
        else cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n-1;i++){
        a[i]=a[i]+a[i+1];
    }
    backTrack(a,n-1);
}
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        backTrack(a,n);
    }
}