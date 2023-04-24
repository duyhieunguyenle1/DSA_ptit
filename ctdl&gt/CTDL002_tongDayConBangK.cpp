#include<bits/stdc++.h>
using namespace std;
int n,a[10000],b[10000],ok=1,k;
void sinh(){
    int i=n;
    while(i>=1&&a[i]==1){
        a[i]=0;
        i--;
    }
    if(i==0)ok=0;
    else a[i]=1;
}
bool gan(){
    int sum=0;
    for(int i=1;i<=n;i++){
        if(a[i]==1)sum+=b[i];
    }
    if(sum==k)return true;
    return false;
}
void print(){
    for(int i=1;i<=n;i++){
        if(a[i]==1)cout<<b[i]<<" ";
    }
    cout<<endl;
}
int main(){
    cin>>n>>k;
    for(int i=1;i<=n;i++)cin>>b[i];
    int cnt=0;
    for(int i=1;i<=n;i++)a[i]=0;
    while(ok){
        if(gan()){
            print();
            cnt++;
        }
        sinh();
    }
    cout<<cnt;
    return 0;
}