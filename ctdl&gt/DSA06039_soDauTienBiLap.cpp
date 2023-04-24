#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        ll a[n];
        map<ll,int>mp;
        for(int i=0;i<n;i++){
            cin>>a[i];
            mp[a[i]]++;
        }
        int check=0;
        for(int i=0;i<n;i++){
            if(mp[a[i]]>1){
                check=1;
                cout<<a[i]<<endl;
                break;
            }
        }
        if(check==0)cout<<"NO\n";
    }
    return 0;
}