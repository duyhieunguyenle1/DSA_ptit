#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t; cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        multiset<ll>s;
        for(int i=0;i<n;i++){
            ll x; cin>>x;
            s.insert(x);
        }
        for(int i=0;i<m;i++){
            ll x; cin>>x;
            s.insert(x);
        }
        for(auto x:s)cout<<x<<" ";
        cout<<endl;
    }
}