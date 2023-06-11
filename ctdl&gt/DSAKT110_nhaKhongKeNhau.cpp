#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solution(int a[],int n){
    ll dp[n+5]={};
    dp[0]=a[0];
    dp[1]=max(a[1],a[0]);
    for(int i=2;i<n;i++){
        dp[i]=max(a[i]+dp[i-2],dp[i-1]);
    }
    cout<<dp[n-1]<<endl;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        Solution(a,n);
    }
    return 0;
}