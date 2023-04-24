#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n,x; cin>>n>>x;
        int a[n];
        int res;
        for(int i=1;i<=n;i++){
            cin>>a[i];
            if(a[i]==x)res=i;
        }
        cout<<res<<endl;
    }
}