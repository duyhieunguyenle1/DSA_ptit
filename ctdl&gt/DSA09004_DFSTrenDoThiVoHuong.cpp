#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<vector<int>>adj;
bool visited[1001];
void DFS(int u){
    stack<int>st;
    st.push(u);

    while(!st.empty()){
        int u=st.top(); st.pop();
        if(!visited[u]){
            cout<<u<<" ";
            visited[u]=true;
        }
        for(auto v:adj[u]){
            if(!visited[v]){
                st.push(u);
                st.push(v);
                break;
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
        DFS(k);
        cout<<endl;
    }
    return 0;
}