#include<bits/stdc++.h>
using namespace std;
int solve(int a[],int n,int i){
    for(int j=1;j<n-1;j++){
        if(i==a[j])return 0;
    }
    return 1;
}
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        int temp=0;
        for(int i=a[0]+1;i<a[n-1];i++){
            if(solve(a,n,i))temp++;
        }
        cout<<temp<<endl;
    }
    return 0;
}