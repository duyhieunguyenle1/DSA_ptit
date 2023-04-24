#include<bits/stdc++.h>
using namespace std;
// binary search
int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        int x=0,cnt=0;
        for(int i=0;i<n-1;i++){
            x=k-a[i];
            int y=lower_bound(a+i+1,a+n,x)-a;
            int z=upper_bound(a+i+1,a+n,x)-a;

            cnt=cnt+z-y;
        }
        cout<<cnt<<endl;
    }
}