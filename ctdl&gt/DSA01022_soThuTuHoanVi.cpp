#include<bits/stdc++.h>
using namespace std;
int n, a[10000], b[10000], ok,stt;

void ktao(){
    for(int i=1;i<=n;i++)a[i]=i;
}

void sinh(){
    int i=n-1;
    while(i>=1&&a[i]>a[i+1]){
        i--;
    }
    if(i==0)ok=0;
    else {
        int j=n;
        while(a[i]>a[j])j--;
        swap(a[i],a[j]);
        int l=i+1,r=n;
        while(l<r){
            swap(a[l],a[r]);
            l++; r--;
        }
    }
}

bool check(){
    for(int i=1;i<=n;i++){
        if(a[i]!=b[i])return false;
    }
    return true;
}

int main(){
    int t; cin>>t;
    while(t--){
        cin>>n;
        ok=1;
        for(int i=1;i<=n;i++)cin>>b[i];
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