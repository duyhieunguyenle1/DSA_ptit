#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
vector<int>a,b;
set<vector<int>>ss;

void Try(int i,int s){
    for(int j=i;j<n;j++){
        b.push_back(a[j]);
        s+=a[j];
        if(s%2==1){
            // push vector b into set but inverse value
            vector<int>z(b.rbegin(),b.rend());
            ss.insert(z);
        }
        if(j+1<n)Try(j+1,s);
        b.pop_back();
        s-=a[j];
    }
}

void Solution(){
    a.clear(); b.clear(); ss.clear();
    cin>>n;
    a.resize(n);
    for(int &i:a)cin>>i;
    sort(a.begin(),a.end());
    Try(0,0);
    for(auto i:ss){
        for(auto j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        Solution();
    }
    return 0;
}