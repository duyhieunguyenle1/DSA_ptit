#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int V,E,u,v;
vector<vector<int>>G;

void Solution(){
    cin>>V>>E;
    G.clear(); G.resize(V+1);
    while(E--){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int odd=0;
    for(int i=1;i<=V;i++){
        odd+=(G[i].size()%2==1);
    }
    if(!odd)cout<<2<<endl;
    else if(odd==2)cout<<1<<endl;
    else cout<<0<<endl;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        Solution();
    }
    return 0;
}   