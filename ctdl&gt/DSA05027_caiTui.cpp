#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t=1;
    cin>>t;
    while(t--){
        int v,n; cin>>n>>v;
        int c[n+5],a[n+5];
        for(int i=1;i<=n;i++)cin>>a[i];
        for(int i=1;i<=n;i++)cin>>c[i];
        int dp[n+1][v+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=v;j++){
                if(j<a[i])dp[i][j]=dp[i-1][j];
                else dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i]]+c[i]);
            }
        }
        cout<<dp[n][v]<<endl;
    }
    return 0;
}