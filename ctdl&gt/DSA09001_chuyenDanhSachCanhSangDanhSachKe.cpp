#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t=1;
    cin>>t;
    while(t--){
        vector<int>adj[1001];
        int n,m; cin>>n>>m;
        for(int i=0;i<m;i++){
            int x,y; cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        for(int i=1;i<=n;i++){
            cout<<i<<": ";
            for(int x:adj[i]){
                cout<<x<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}