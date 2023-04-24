#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// -7 1 5 2 -4 3 0 -> sumLeft: -7 -6 -1 1 -3 0 0
// -7 1 5 2 -4 3 0 -> sumRight: 0  7  6 1 -1 3 0
// 2 điểm bằng nhau là điểm cân bằng 
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        ll a[n];
        for(int i=1;i<=n;i++)cin>>a[i];
        ll sumLeft[n]={0},sumRight[n]={0};
        for(int i=1;i<=n;i++){
            sumLeft[i]=a[i]+sumLeft[i-1];
        }
        for(int i=n;i>=1;i--){
            sumRight[n-i+1]=a[i]+sumRight[n-i];
        }
        int check=1;
        for(int i=1;i<=n;i++){
            if(sumLeft[i]==sumRight[n-i+1]){
                cout<<i<<endl;
                check=0;
                break;
            }
        }
        if(check)cout<<"-1\n";
    }
    return 0;
}