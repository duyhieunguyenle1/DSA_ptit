#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n,x; cin>>n>>x;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            int k; cin>>k;
            mp[k]++;
        }
        if(mp.find(x)!=mp.end()){
                cout<<mp[x]<<endl;
        }else cout<<"-1\n";
    }
}