#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int n,p,s;
vector<vector<int>>res;
vector<int>e(201,1);
vector<int>prime;

void sieve(){
    e[0]=e[1]=0;
    for(int i=2;i*i<=200;i++){
        if(e[i]){
            for(int j=i*i;j<=200;j+=i){
                e[j]=0;
            }
        }
    }
    for(int i=2;i<=200;i++){
        if(e[i])prime.push_back(i);
    }
}

void Try(int pos,int sum,vector<int>v){
    if(v.size()==n){
        if(sum==s)res.push_back(v);
        return;
    }
    for(int i=pos;i<prime.size();i++){
        if(sum+prime[i]<=s){
            v.push_back(prime[i]);
            Try(i+1,sum+prime[i],v);
            v.pop_back();
        }else return;
    }
}

void Solution(){
    res.clear();
    cin>>n>>p>>s;
    for(int i=0;i<prime.size();i++){
        if(prime[i]>p){
            Try(i,0,{});
            break;
        }
    }
    sort(res.begin(),res.end());
    cout<<res.size()<<endl;
    for(auto i:res){
        for(auto j:i)cout<<j<<" ";
        cout<<endl;
    }
}

int main(){
    int t=1;
    cin>>t;
    sieve();
    while(t--){
        Solution();
    }
    return 0;
}