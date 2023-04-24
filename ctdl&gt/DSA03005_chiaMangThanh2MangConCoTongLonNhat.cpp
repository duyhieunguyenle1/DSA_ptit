#include<bits/stdc++.h>
using namespace std;

int main(){
    int t; cin>>t;
    while(t--){
        int n,k; cin>>n>>k;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        int m1=0,m2=0,res;
        for(int i=0;i<n;i++){
            if(i<k)m1+=a[i];
            else m2+=a[i];
        }
        res=abs(m2-m1);
        m1=0,m2=0;
        for(int i=0;i<n;i++){
            if(i<n-k)m1+=a[i];
            else m2+=a[i];
        }
        res=max(res,abs(m2-m1));
        cout<<res<<endl;
    }
}