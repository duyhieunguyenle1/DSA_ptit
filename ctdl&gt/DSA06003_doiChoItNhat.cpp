#include<bits/stdc++.h>
using namespace std;
// selection sort
int main(){
    int t; cin>>t;
    while(t--){
        int n;cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        int cnt=0;
        for(int i=0;i<n;i++){
            int min=a[i],m=0;
            for(int j=i+1;j<n;j++){
                if(min>a[j]){
                    min=a[j];
                    m=j;
                }
            }
            if (a[i] > min){
                swap(a[m], a[i]);
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}