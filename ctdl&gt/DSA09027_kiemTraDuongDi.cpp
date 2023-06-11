#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>>adj;
vector<bool>visited;
int V,E;

void BFS(int u){
    visited.clear();
    visited.resize(V+1,0);
    queue<int>q;
    q.push(u);
    visited[u]=true;

    while(!q.empty()){
        int x=q.front(); q.pop();
        for(int v:adj[x]){
            if(!visited[v]){
                q.push(v);
                visited[v]=true;
            }
        }
    }
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        cin>>V>>E;
        adj.clear();
        adj.resize(V+1);
        for(int i=0;i<E;i++){
            int x,y; cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        int Q; cin>>Q;
        while(Q--){
            int x,y; cin>>x>>y;
            BFS(x);
            cout<<(visited[y]?"YES":"NO")<<endl;
        }
    }
    return 0;
}