#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        long long dem=0;
        for(int i=0;i<n-1;i++){
            long long id=upper_bound(a,a+n,a[i]+k-1)-a;
            dem=dem+(id-i-1);
        }
        cout<<dem<<endl;
    }
    return 0;
}