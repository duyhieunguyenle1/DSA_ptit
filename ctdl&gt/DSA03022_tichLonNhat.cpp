#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    ll res1,res2,res;
    ll max1=a[n-1]*a[n-2],max2=a[n-1]*a[n-2]*a[n-3],
    max3=a[0]*a[1]*a[n-1],max4=a[0]*a[1];
    res1=max1>max2?max1:max2;
    res2=max3>max4?max3:max4;
    res=res1>res2?res1:res2;
    cout<<res;
}