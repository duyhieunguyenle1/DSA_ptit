#include<bits/stdc++.h>
using namespace std;
int n, ok;
char a[10000];

void ktao(){
    for(int i=1;i<=n;i++){
        a[i]='A';
    }
}

void sinh(){
    int i=n;
    while(i>=1&&a[i]=='H'){
        a[i]='A';
        i--;
    }
    if(i==0)ok=0;
    else a[i]='H';
}

bool check(){
    if(a[1]!='H'||a[n]!='A')return false;
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(a[i]=='H'&&cnt<2)cnt++;
        else if(a[i]=='A'&&cnt<2)cnt=0;
        else return false;
    }
    return true;
}

void print(){
    for(int i=1;i<=n;i++)cout<<a[i];
    cout<<endl;
}

int main(){
    int t; cin>>t;
    while(t--){
        cin>>n;
        ktao();
        ok=1;
        while(ok){
            if(check())print();
            sinh();
        }
    }
}