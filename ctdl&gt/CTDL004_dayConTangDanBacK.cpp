#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k,res=0;
int a[105]={};
vector<int>tmp;

void Try(int i){
    for(int j=i+1;j<=n;j++){
        if(a[j]>a[i]){
            tmp.push_back(a[j]);
            if(tmp.size()==k)res++;
            Try(j);
            tmp.pop_back();
        }
    }
}

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)cin>>a[i];
        Try(0);
        cout<<res;
    }
    return 0;
}