#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int MOD = 1e9+7;

void Solution(){
    int n; cin>>n;
    priority_queue<ll,vector<ll>,greater<ll>>pq;
    ll res=0;
    for(int i=0;i<n;i++){
        ll x; cin>>x;
        pq.push(x);
    }
    while(pq.size()!=1){
        ll first=pq.top(); pq.pop();
        ll second=pq.top(); pq.pop();
        ll z=(first+second)%MOD;
        res=(res+z)%MOD;
        pq.push(z);
    }
    cout<<res<<endl;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        Solution();
    }
    return 0;
}