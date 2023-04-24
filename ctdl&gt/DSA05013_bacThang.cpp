#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int MOD = 1e9+7;

// k=2 thì đây là dãy Fibonacci mà :V
// k=3 thì là Tribonacci :V
// k > 3 thì chắc là k-bonacci :V định nghĩa

// F(0,k) = 0
// F(1,k) = 1
// F(n,k) = F(n-1,k) + F(n-2,k) + … + F(1,k) + F(0,k) với n < k
// F(n,k) = F(n-1,k) + F(n-2,k) + … + F(n-k+1,k) + F(n-k,k) với n >= k

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        vector<ll>f(1e5+1,0);
        ll temp=0;
        for(int i=1;i<=k;i++){
            f[i]=(temp+1)%MOD;
            temp=(temp+f[i])%MOD;
        }
        for(int i=k+1;i<=n;i++){
            for(int j=1;j<=k;j++){
                f[i]=(f[i]+f[i-j])%MOD;
            }
        }
        cout<<f[n]<<endl;
    }
}