#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>>adj;
bool visited[1001];
void BFS(int u){
    queue<int>st;
    st.push(u);
    visited[u]=true;

    while(!st.empty()){
        int u=st.front(); st.pop();
        cout<<u<<" ";
        for(auto v:adj[u]){
            if(!visited[v]){
                st.push(v);
                visited[v]=true;
            }
        }
    }
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        int n,m,k; cin>>n>>m>>k;
        adj.clear();
        adj.resize(n+1);
        for(int i=0;i<m;i++){
            int x,y; cin>>x>>y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }
        memset(visited,false,sizeof(visited));
        BFS(k);
        cout<<endl;
    }
    return 0;
}