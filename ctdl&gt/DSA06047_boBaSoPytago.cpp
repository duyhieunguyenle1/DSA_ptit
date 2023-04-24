#include<bits/stdc++.h>
using namespace std;
int check(long long a[],int n){
    for(long long i=n-1;i>=2;i--){
        long long l=0,r=i-1;
        while(l<r){
            if(pow(a[l],2)+pow(a[r],2)==pow(a[i],2))return 1;
            else if(pow(a[l],2)+pow(a[r],2)<pow(a[i],2))l++;
            else r--;
        }
    }
    return 0;
}
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        long long a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        sort(a,a+n);
        if(check(a,n))cout<<"YES\n";
        else cout<<"NO\n";
    }
}