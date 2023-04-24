#include<bits/stdc++.h>
using namespace std;
int n, ok, k;
char a[100];

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

bool check(){
    int cnt=0,ans=0;
    for(int i=1;i<=n;i++){
        if(a[i]=='A'){
            cnt++;
            if(cnt==k)ans++;
            else if(cnt>k)return false;
        }else {
            cnt=0;
        }
    }
    if(ans==1)return true;
    return false;
}

int main(){
    cin>>n>>k;
    vector<string>v;
    ok=1;
    ktao();
    while(ok){
        if(check()){
            string tmp="";
            for(int i=1;i<=n;i++)tmp+=a[i];
            v.push_back(tmp);
        }
        sinh();
    }
    cout<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<endl;
    }
    return 0;
}