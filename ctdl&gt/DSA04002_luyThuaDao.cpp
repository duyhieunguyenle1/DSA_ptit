#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MOD =1e9+7;

ll poww(ll n, ll k){
    if(k==0)return 1;
    ll x = poww(n,k/2);
    if(k%2==0)return (x*x)%MOD;
    return (n*((x*x)%MOD))%MOD;
}

ll rev(ll n){
    ll res=0;
    while(n>0){
        res = res*10+n%10;
        n/=10;
    }
    return res;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        ll n; cin>>n;
        ll r = rev(n);
        cout<< poww(n,r)<<endl;
    }
    return 0;
}