#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    int t=1;
    // cin>>t;
    while(t--){
        int n; cin>>n;
        vector<vector<int>>v(n+5);
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int x; cin>>x;
                if(x){
                    v[i].push_back(j);
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int x:v[i])cout<<x<<" ";
            cout<<endl;
        }   
    }
    return 0;
}   