#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        int n; cin>>n;
        cin.ignore();
        vector<pair<int,int>>vp;
        for(int i=1;i<=n;i++){
            string s,num; getline(cin,s);
            stringstream ss(s);
            while(ss>>num){
                if(stoi(num)>i){
                    vp.push_back({i,stoi(num)});
                }
            }
        }
        for(auto x:vp){
            cout<<x.first<<" "<<x.second<<endl;
        }
    }
    return 0;
}