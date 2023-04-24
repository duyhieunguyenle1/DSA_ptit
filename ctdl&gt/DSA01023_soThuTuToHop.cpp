#include<bits/stdc++.h>
using namespace std;
int n, a[10000], b[10000], k, ok,stt;

void ktao(){
    for(int i=1;i<=k;i++)a[i]=i;
}

void sinh(){
    int i=k;
    while(i>=1&&a[i]==n-k+i){
        i--;
    }
    if(i==0)ok=0;
    else {
        a[i]++;
        for(int j=i+1;j<=k;j++){
            a[j]=a[j-1]+1;
        }
    }
}

bool check(){
    for(int i=1;i<=k;i++){
        if(a[i]!=b[i])return false;
    }
    return true;
}

int main(){
    int t; cin>>t;
    while(t--){
        cin>>n>>k;
        ok=1;
        for(int i=1;i<=k;i++)cin>>b[i];
        ktao();
        stt=0;
        while(ok){
            stt++;
            if(check())cout<<stt<<endl;
            sinh();
        }
    }
    return 0;
}