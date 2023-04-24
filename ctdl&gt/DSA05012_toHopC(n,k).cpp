#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// C(n,k)=C(n-1,k-1)+C(n-1,k) k!=n && k!=0
ll mod = 1e9+7;
ll dp[1001][1001];

void Prep(){
    for(int i=0;i<=1000;i++){
        for(int j=0;j<=i;j++){
            if(i==j||j==0)dp[i][j]=1;
            else dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            dp[i][j]%=mod;
        }
    }
}

int main(){
    int t=1;
    cin>>t;
    Prep();
    while(t--){
        ll n,k;
        cin>>n>>k;
        cout<<dp[n][k]<<endl;
    }
    return 0;
}