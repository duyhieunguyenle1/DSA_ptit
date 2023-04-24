#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int dp[105][25005];

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        int c,n; cin>>c>>n;
        int a[n+5];
        for(int i=1;i<=n;i++)cin>>a[i];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=c;j++){
                if(j<a[i])dp[i][j]=dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i]]+a[i]);
            }
        }
        cout<<dp[n][c];
    }
    return 0;
}