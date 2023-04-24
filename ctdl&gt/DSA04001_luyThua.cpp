#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int MAX=1e9+7;

ll sqr(ll x) {
    return x*x;
}
 
ll pow(ll a, ll b) {
    if (b == 0) return 1;
    else
        if (b % 2 == 0)
            return sqr(pow(a, b/2))%MAX;
        else
            return a * (sqr(pow(a, b/2))%MAX)%MAX;
}

int main(){
    int t; cin>>t;
    while(t--){
        ll n,k;
        cin>>n>>k;
        cout<<pow(n,k)<<endl;
    }
}