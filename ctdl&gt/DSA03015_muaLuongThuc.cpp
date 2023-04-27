#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solution(int n,int s, int m){
    if(n<m||(n-m)*6<m)cout<<"-1\n";
    else cout<<ceil((float)m*s/n)<<endl;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        int n,s,m; cin>>n>>s>>m;
        Solution(n,s,m);
    }
    return 0;
}