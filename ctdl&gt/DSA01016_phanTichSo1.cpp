#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Try(int limit,int remain,vector<int>a){
    if(remain==0){
        cout<<"(";
        for(int i=0;i<a.size()-1;i++)cout<<a[i]<<" ";
        cout<<a.back()<<") ";
    }

    for(int i=limit;i>=1;i--){
        if(remain>=i){
            a.push_back(i);
            Try(i,remain-i,a);
            a.pop_back();
        }
    }
}

void Solution(){
    int n; cin>>n;
    Try(n,n,{});
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        Solution();
        cout<<endl;
    }
    return 0;
}