#include<bits/stdc++.h>
using namespace std;
int n, a[10000],temp;

void ktao(){
    for(int i=1;i<=n;i++)a[i]=1;
}

void sinh(){
    int i=n;
    while(i>=1&&a[i]==0){
        i--;
    }
    if(i==0)ktao();
    else {
        a[i]=0;
        temp=i+1;
        while(temp<=n){
            a[temp]=1;
            temp++;
        }
    }
}

void print(){
    for(int i=1;i<=n;i++)cout<<a[i];
    cout<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        n=s.size();
        for(int i=1;i<=s.size();i++){
            a[i]=s[i-1]-'0';
        }
        sinh();
        print();
    }
}