#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        int l=0,r=n-1,check=1;
        while(l<=r){
            int m=(l+r)/2;
            if(a[m]==k){
                cout<<m+1<<endl;
                check=0;
                break;
            }else if(a[m]<k){
                l=m+1;
            }
            else {
                r=m-1;
            }
        }  
        if(check)cout<<"NO\n";      
    }
}