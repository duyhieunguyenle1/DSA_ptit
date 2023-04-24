#include<bits/stdc++.h>
using namespace std;
int n, a[10000],b[10000], k, ok;

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

int main(){
    int t; cin>>t;
    while(t--){
        cin>>n>>k;
        ok=1;
        for(int i=1;i<=k;i++){
            cin>>a[i];
            b[i]=a[i];
        }
        sinh();
        if(!ok)cout<<k<<endl;
        else {
            int cnt=0;
            for(int i=1;i<=k;i++){
                for(int j=1;j<=k;j++)
                    if(a[i]==b[j])cnt++;
            }
            cout<<k-cnt<<endl;
        }
    }
}