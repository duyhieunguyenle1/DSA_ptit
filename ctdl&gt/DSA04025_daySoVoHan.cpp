#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// nhân ma trận
// f[n]   f[n-1] =  (1  1) ^ n-1
// f[n-1] f[n-2]    (1  0)
// cách tính mũ nhanh chẵn a^n = a^n/2 * a^n/2 *a
// lẻ a^n = a^n/2 * a^n/2* a

int MOD = 1e9+7;
ll f[2][2],d[2][2];

void Mul(ll a[2][2], ll b[2][2]) {
    ll x = (a[0][0] * b[0][0] % MOD + a[0][1] * b[1][0] % MOD) % MOD;
    ll y = (a[0][0] * b[0][1] % MOD + a[0][1] * b[1][1] % MOD) % MOD;
    ll z = (a[1][0] * b[0][0] % MOD + a[1][1] * b[1][0] % MOD) % MOD;
    ll t = (a[1][0] * b[0][1] % MOD + a[1][1] * b[1][1] % MOD) % MOD;
    f[0][0] = x, f[0][1] = y, f[1][0] = z, f[1][1] = t;
}

void Pow(ll f[2][2], int n) {
    if (n <= 1) return;
    Pow(f, n / 2);
    Mul(f, f);
    if (n % 2 == 1) {
        Mul(f, d);
    }
}

void Solution(int n){
    f[0][0]=f[0][1]=f[1][0]=1; f[1][1]=0;
    d[0][0]=d[0][1]=d[1][0]=1; d[1][1]=0;
    Pow(f,n-1);
    cout<<f[0][0]<<endl;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        int n; cin>>n;
        Solution(n);
    }
    return 0;
}