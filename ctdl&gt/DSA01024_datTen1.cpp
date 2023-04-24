#include<bits/stdc++.h>
using namespace std;
int n,a[100],k;
vector<string>v;

void inkq(){
    for(int i=1;i<=k;i++)cout<<v[a[i]-1]<<" ";
    cout<<endl;
}

void Try(int i){
    for(int j=a[i-1]+1;j<=v.size()-k+i;j++){
        a[i]=j;
        if(i==k)inkq();
        else Try(i+1);
    }
}
int main(){
    cin>>n>>k;
    string s;
    map<string,bool>m;
    for(int i=0;i<n;i++){
        cin>>s;
        m[s]=1;
    }
    for(auto x:m)v.push_back(x.first);
    Try(1);
}