#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// binary search
int main(){
    int t; cin>>t;
    while(t--){
        int n;
        ll k; cin>>n>>k;
        ll a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        ll x=0,cnt=0;
        for(int i=0;i<n-1;i++){
            x=k-a[i];
            int y=lower_bound(a+i+1,a+n,x)-a;
            int z=upper_bound(a+i+1,a+n,x)-a;

            cnt=cnt+z-y;
        }
        cout<<cnt<<endl;
    }
}