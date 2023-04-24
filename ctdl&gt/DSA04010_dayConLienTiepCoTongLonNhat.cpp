#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        int temp=0,res=0;
        for(int i=0;i<n;i++){
            temp+=a[i];
            if(temp>res)res=temp;
            if(temp<0)temp=0;
        }
        cout<<res<<endl;
    }
}