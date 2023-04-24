#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t=1;
    cin>>t;
    while(t--){
        int n; string s;
        cin>>n>>s;
        int dp[105][1005];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==s[j-1]&&j!=i){
                    dp[i][j]=dp[i-1][j-1]+1;
                }else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        cout<<dp[n][n]<<endl;
    }
    return 0;
}