#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        ll a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        ll tmp=INT_MAX;
        for(int i=0;i<n-1;i++){
            if((a[i+1]-a[i])<tmp)tmp=a[i+1]-a[i];
        }
        cout<<tmp<<endl;
    }
}