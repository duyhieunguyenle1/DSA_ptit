#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    string a,b; cin>>a>>b;
    ll a1=0,b1=0;
    for(int i=0;i<a.size();i++){
        if(a[i]=='5')a1=a1*10+6;
        else a1=a1*10+(a[i]-'0');
    }
    for(int i=0;i<b.size();i++){
        if(b[i]=='5')b1=b1*10+6;
        else b1=b1*10+(b[i]-'0');
    }
    ll max=a1+b1;
    
    a1=0,b1=0;
    for(int i=0;i<a.size();i++){
        if(a[i]=='6')a1=a1*10+5;
        else a1=a1*10+(a[i]-'0');
    }
    for(int i=0;i<b.size();i++){
        if(b[i]=='6')b1=b1*10+5;
        else b1=b1*10+(b[i]-'0');
    }
    ll min=a1+b1;
    cout<<min<<" "<<max;
}