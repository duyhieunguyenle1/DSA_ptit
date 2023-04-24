#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        ll a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        set<int>s;
        for(int i=0;i<n;i++){
            ll temp=a[i];
            while(temp>0){
                s.insert(temp%10);
                temp/=10;
            }
        }
        for(auto x:s)cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}