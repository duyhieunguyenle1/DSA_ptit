#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solution(){
    int n; cin>>n;
    map<int,int>mp;
    for(int i=0;i<n;i++){
        int x; cin>>x;
        mp[x]++;
    }
    for(auto x:mp){
        if(x.second>(n/2)){
            cout<<x.first<<endl;
            return ;
        }
    }
    cout<<"NO\n";
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        Solution();
    }
    return 0;
}