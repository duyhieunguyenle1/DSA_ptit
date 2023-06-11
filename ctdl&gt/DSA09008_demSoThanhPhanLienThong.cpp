// https://code.ptit.edu.vn/student/question/DSA09008
// ĐẾM SỐ THÀNH PHẦN LIÊN THÔNG

#include <bits/stdc++.h>
using namespace std;

int V, E, u, v, lthong;
vector<vector<int>> G;
vector<bool> vs;

void dfs(int u){
    vs[u]=true;
    for(int x:G[u]){
        if(!vs[x])dfs(x);
    }
}

void testCase() {
    lthong = 0;
    cin >> V >> E;
    G.clear(); G.resize(V + 10);
    vs.clear(); vs.resize(V + 10, 0);
    while (E--) {
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for (int i = 1; i <= V; ++i) {
        if (!vs[i]) {
            dfs(i);
            lthong++;
        }
    }
    cout << lthong;
}

int main() {
    int T = 1; cin >> T;
    while (T--) {
        testCase();
        cout << "\n";
    }
    return 0;
}