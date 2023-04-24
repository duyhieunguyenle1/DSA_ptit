#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t; cin>>t;
    while(t--){
        int n,MAX=1e9+7; cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        ll res=0;
        sort(a,a+n);
        for(int i=0;i<n;i++){
            res+=1LL*a[i]*i;
            res%=MAX;
        }
        cout<<res<<endl;
    }
}