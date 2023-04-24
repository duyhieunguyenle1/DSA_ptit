#include<bits/stdc++.h>
using namespace std;
int n, a[10000], ok;

void print(){
    for(int i=1;i<=n;i++)cout<<a[i];
    cout<<endl;
}

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
    for(int i=1;i<n;i++){
        if(abs(a[i+1]-a[i])<=1)return false;
    }
    return true;
}

int main(){
    int t; cin>>t;
    while(t--){
        cin>>n;
        ok=1;
        ktao();
        while(ok){
            if(check())print();
            sinh();
        }
        cout<<endl;
    }
    return 0;
}