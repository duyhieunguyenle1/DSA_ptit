#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(ll a,ll b){
    return a>b;
}

void Solution(){
    int n; cin>>n;
    ll a[n],b[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    ll res=0;
    sort(a,a+n);
    sort(b,b+n,cmp);
    for(int i=0;i<n;i++){
        res+=(a[i]*b[i]);
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