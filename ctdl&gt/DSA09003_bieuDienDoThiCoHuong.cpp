#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solution(int n,int m){
    vector<int>v[1001];
    for(int i=0;i<m;i++){
        int x,y; cin>>x>>y;
        v[x].push_back(y);
    }
    for(int i=1;i<=n;i++){
        cout<<i<<": ";
        for(auto x:v[i])cout<<x<<" ";
        cout<<endl;
    }
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        int n,m; cin>>n>>m;
        Solution(n,m);
    }
    return 0;
}