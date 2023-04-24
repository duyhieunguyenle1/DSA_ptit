#include<bits/stdc++.h>
using namespace std;
int n, a[10000], b[10000], k,cnt;

void ktao(){
    for(int i=1;i<=k;i++)a[i]=i;
}

void sinh(){
    int i=k;
    while(i>=1&&a[i]==n-k+i){
        i--;
    }
    if(i==0)cout<<k<<endl;
    else {
        a[i]++;
        for(int j=i+1;j<=k;j++)a[j]=a[j-1]+1;
        for(int i=1;i<=k;i++){
            for(int j=1;j<=k;j++){
                if(a[i]==b[j])cnt++;
            }
        }
        if(cnt==k)cnt=0;
        cout<<k-cnt<<endl;
    }
}

int main(){
    int t; cin>>t;
    while(t--){
        cin>>n>>k;
        cnt=0;
        for(int i=1;i<=k;i++){
            cin>>a[i];
            b[i]=a[i];
        }
        sinh();
    }
    return 0;
}