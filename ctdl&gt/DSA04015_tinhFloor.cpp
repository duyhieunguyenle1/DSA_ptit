#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t; cin>>t;
    while(t--){
        int n;
        ll k; cin>>n>>k;
        ll a[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        auto it = upper_bound(a,a+n,k);
        if(it == a)cout<<"-1\n";
        else cout<<it - a<<endl;
    }
}