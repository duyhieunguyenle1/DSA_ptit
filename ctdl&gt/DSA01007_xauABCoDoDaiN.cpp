#include<bits/stdc++.h>
using namespace std;
int n, ok;
char a[100];

void print(){
    for(int i=1;i<=n;i++)cout<<a[i];
    cout<<" ";
}

void ktao(){
    for(int i=1;i<=n;i++){
        a[i]='A';
    }
}

void sinh(){
    int i=n;
    while(i>=1&&a[i]=='B'){
        a[i]='A';
        i--;
    }
    if(i==0)ok=0;
    else a[i]='B';
}

int main(){
    int t; cin>>t;
    while(t--){
        cin>>n;
        ok=1;
        ktao();
        while(ok){
            print();
            sinh();
        }
    
    }
    return 0;
}