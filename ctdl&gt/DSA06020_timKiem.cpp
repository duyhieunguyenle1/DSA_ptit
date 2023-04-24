#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n,x; cin>>n>>x;
        multiset<int>s;
        for(int i=0;i<n;i++){
            int a; cin>>a;
            s.insert(a);
        }
        if(s.count(x)!=0)cout<<"1\n";
        else cout<<"-1\n";
    }
}