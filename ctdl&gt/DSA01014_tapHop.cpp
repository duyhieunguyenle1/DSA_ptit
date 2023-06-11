#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,k,s,res=0;
int X[15]={};

bool Check(){
    int sum=0;
    for(int i=1;i<=k;i++)sum+=X[i];
    if(sum==s)return true;
    return false;
}

void Try(int i){
    for(int j=X[i-1]+1;j<=n-k+i;j++){
        X[i]=j;
        if(i==k){
            if(Check())res++;
        }else{
            Try(i+1);
        }
    }

}

int main(){
    int t=1;
    // cin>>t;
    while(true){
        cin>>n>>k>>s;
        if(n==0&&k==0&&s==0)return 0;
        res=0;
        Try(1);
        cout<<res<<endl;
    }
    return 0;
}