#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int V,E,u,v;
vector<pair<int,int>>G;

// phải trong cùng 1 đồ thị liên thông
// kiểm tra bán bậc vào có bằng bán bậc ra ko
// nếu ko thì ko có chu trình và ngược lại
void Solution(){
    cin>>V>>E;
    G.clear(); G.resize(V+1);
    for(int i=1;i<=E;i++){
        cin>>u>>v;
        G[u].first++;
        G[v].second++;
    }
    for(int i=1;i<=V;i++){
        if(G[i].first!=G[i].second){
            cout<<0<<endl;
            return;
        }
    }
    cout<<1<<endl;
    return;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        Solution();
    }
    return 0;
}