#include<bits/stdc++.h>
using namespace std;

// số phần tử - số xâu con tăng dần dài nhất(có thể bằng)

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n],b[n];
        for(int i=0;i<n;i++)b[i]=1;
        for(int i=0;i<n;i++)cin>>a[i];
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[j]<=a[i]){
                    b[i]=max(b[j]+1,b[i]);
                }
            }
        }
        cout<<n-*max_element(b,b+n)<<endl;
    }
}