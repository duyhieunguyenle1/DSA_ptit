#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

bool cmp(pair<int,int>a, pair<int,int> b){
    if(a.second!=b.second)return a.second<b.second;
    return a.first<b.first;
}

void Solution(vector<pair<int,int>>vp,int n){
    int j=0;
    int res=1;
    for(int i=1;i<n;i++){
        if(vp[i].first>=vp[j].second){
            res++;
            j=i;
        }
    }
    cout<<res<<endl;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        int n; cin>>n;
        vector<pair<int,int>>vp;
        for(int i=0;i<n;i++){
            int x,y; cin>>x>>y;
            vp.push_back({x,y});
        }
        sort(vp.begin(),vp.end(),cmp);
        Solution(vp,n);
    }   
    return 0;
}