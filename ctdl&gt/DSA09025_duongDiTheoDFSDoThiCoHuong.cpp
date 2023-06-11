#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,m,s,k;
vector<vector<int>>adj;
bool visited[1001];
int parent[1001]={};

void DFS(int u){
    visited[u]=true;
    for(auto v:adj[u]){
        if(!visited[v]){
            parent[v]=u;
            DFS(v);
        }
    }
}

void Path(){
    memset(visited,false,sizeof(visited));
    memset(parent,0,sizeof(parent));
    DFS(s);
    if(!visited[k])cout<<"-1\n";
    else {
        vector<int>path;
        // bắt đầu từ đỉnh t
        while(k!=s){
            path.push_back(k);
            // lật ngược lại
            k=parent[k];
        }
        path.push_back(s);
        reverse(path.begin(),path.end());
        for(int x:path)cout<<x<<" ";
        cout<<endl;
    }
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        cin>>n>>m>>s>>k;
        adj.clear(); adj.resize(n+1);
        for(int i=0;i<m;i++){
            int x,y; cin>>x>>y;
            adj[x].push_back(y);
        }
        Path();
    }
    return 0;
}