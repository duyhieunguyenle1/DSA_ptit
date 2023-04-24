#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f[100];
void prepare(){
    f[1]=f[2]=1;
    for(int i=3;i<=100;i++)f[i]=f[i-1]+f[i-2];
}

int main(){
    prepare();
    int t; cin>>t;
    while(t--){
        ll n,k; cin>>n>>k;
        while(true){
            if(n==1||n==2){
                if(n==1)cout<<"0\n";
                else cout<<"1\n";
                break;
            }
            if(k>f[n-2]){
                k-=f[n-2];
                n--;
            }
            else n-=2;
        }
    }
}