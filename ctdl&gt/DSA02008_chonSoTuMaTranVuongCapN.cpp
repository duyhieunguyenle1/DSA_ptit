#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k;
vector<vector<int>>a,res;
vector<int>b;
vector<bool>used;

void solve(){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i][b[i]];
    }
    if(sum==k)res.push_back(b);
}

void Try(int i){
    for(int j=0;j<n;j++){
        if(!used[j]){
            b[i]=j;
            used[j]=true;
            if(i==n-1)solve();
            else Try(i+1);
            used[j]=false;
        }
    }
}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        cin>>n>>k;
        a.resize(n,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)cin>>a[i][j];
        }
        b.clear(); b.resize(n);
        used.clear(); used.resize(n, 0);
        res.clear();

        Try(0);
        cout<<res.size()<<endl;
        for(auto i:res){
            for(int j:i)cout<<j+1<<" ";
            cout<<endl;
        }
    }
    return 0;
}