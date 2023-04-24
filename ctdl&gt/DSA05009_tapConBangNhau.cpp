#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t=1;
    cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n+5];
        int sum=0;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            sum+=a[i];
        }
        if(sum%2!=0)cout<<"NO\n";
        else{
            int dp[10001];
            sum/=2;
            memset(dp,0,sizeof(dp));
            dp[0]=1;
            for(int i=1;i<=n;i++){
                for(int j=sum;j>=a[i];j--){
                    if(dp[j-a[i]])dp[j]=1;
                }
            }
            if(dp[sum])cout<<"YES\n";
            else cout<<"NO\n";
        }
    }
    return 0;
}