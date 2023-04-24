#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool check(ll a[],int n,ll k){
    for(int i=0;i<n;i++){
        int l=i+1,r=n-1;
        while(l<r){
            if(a[i]+a[l]+a[r]==k)return 1;
            if(a[i]+a[l]+a[r]>k)r--;
            else l++;
        }
    }
    return 0;
}
int main(){
    int t; cin>>t;
    while(t--){
        int n; ll k;
        cin>>n>>k;
        ll a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        if(check(a,n,k))cout<<"YES\n";
        else cout<<"NO\n";
    }
}