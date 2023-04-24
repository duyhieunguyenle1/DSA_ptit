#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        ll a[n],b[n];
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=0;i<n-1;i++)cin>>b[i];
        int check=1;
        for(int i=0;i<n-1;i++){
            if(a[i]!=b[i]){
                check=0;
                cout<<i+1<<endl;
                break;
            }
        }
        if(check)cout<<n<<endl;
    }
}