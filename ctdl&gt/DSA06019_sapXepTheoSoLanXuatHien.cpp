#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        multimap<int,int>mp;
        sort(a,a+n,greater<int>());
        for(int i=0;i<n;i++){
            int d=1;
            while(a[i]==a[i+1]){
                d++;
                i++;
            }
            mp.insert({d,a[i]});
        }
        int b[n];
        int k=0;
        for(auto &it:mp){
            for(int i=0;i<it.first;i++){
                b[k++]=it.second;
            }
        }
        reverse(b,b+n);
        for(int i=0;i<n;i++)cout<<b[i]<<" ";
        cout<<endl;
    }
    return 0;
}