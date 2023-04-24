#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t; cin>>t;
    while(t--){
        ll n,k; cin>>n>>k;
        ll res=1;
        while(k%2==0){
            k/=2;
            res++;
        }
        cout<<res<<endl;
    }
}
