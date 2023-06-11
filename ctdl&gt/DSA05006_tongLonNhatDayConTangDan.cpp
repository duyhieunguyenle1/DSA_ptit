#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solution(){
    int n; cin>>n;
    vector<int>a(n),dp(n);
    for(int &i:a)cin>>i;
    for(int i=0;i<n;i++){
        dp[i]=a[i];
        for(int j=0;j<i;j++){
            if(a[i]>a[j])dp[i]=max(dp[i],dp[j]+a[i]);
        }
    }
    cout<<*max_element(dp.begin(),dp.end())<<endl;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        Solution();
    }
    return 0;
}