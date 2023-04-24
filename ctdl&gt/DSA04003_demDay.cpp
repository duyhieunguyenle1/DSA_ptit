#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// S(n) = S(1) + S(2) +... +S(n-2) + S(n-1) 
// = [ S(1) + S(2) +... +S(n-2) ] + S(n-1) 
// = S(n-1) + S(n-1) = 2[S(n-1)] => S(n) = 2[2*S(n-2)]. 
// Quy luật : với S(n) thì ra được: 2^1 lần S(n-1), 2^2 lần S(n-2), ...., 2^(n-1) 
// lần S(n-(n -1)) = S(1) = 1 ( Với 1 là bài toán con: n = 1 có 1 dãy) 
// => S(n) = 2^(n-1)

int MOD = 123456789;

ll powf(ll a, ll b){
    if (b == 0)return 1;
    ll res = powf(a,b>>1); //b>>1 <=> b/=2
    res=(res*res)%MOD;
    if(b%2!=0)res=(res*a)%MOD;
    return res;
}

int main(){
    int t; cin>>t;
    while(t--){
        ll n; cin>>n;
        cout<<powf(2,n-1)<<endl;
    }
}