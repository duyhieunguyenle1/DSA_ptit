#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod =  1e9+7;

ll powf(ll a, ll b){
    if (b == 0)return 1;
    ll res = powf(a,b>>1); //b>>1 <=> b/=2
    res=(res*res)%mod;
    if(b%2!=0)res=(res*a)%mod;
    return res;
}
int main(){
    while(true){
        ll a,b; cin>>a>>b;
        if(a==0&&b==0)return 0;
        cout<<powf(a,b)<<endl;
    }
    return 0;
}