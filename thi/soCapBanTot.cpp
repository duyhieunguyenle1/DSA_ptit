#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int nmax = 300005;
    int n,k,a[nmax],dp[nmax][25];
    cin>>n>>k;
    string s;
    for(int i=1;i<=n;i++){
        cin>>s;
        a[i]=s.size();
    }
    for(int i=1;i<=n;i++)dp[i][0]=0;
    for(int i=1;i<=20;i++)dp[0][i]=0;
    for(int j=1;j<=20;j++){
        for(int i=1;i<=n;i++){
            if(a[i]==j)
                dp[i][j]=dp[i-1][j]+1;
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    ll res=0;
    int tmp;
    for(int i=1;i<=n;i++){
        tmp=0;
        tmp=max(i-k-1,tmp);
        res+=(dp[i][a[i]]-dp[tmp][a[i]]-1);
    }
    cout<<res;
}