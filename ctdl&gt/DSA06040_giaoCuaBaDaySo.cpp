#include <bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n1,n2,n3; cin>>n1>>n2>>n3;
        long long a[n1],b[n2],c[n3];
        vector<int>v;
        for(int i=0;i<n1;i++){
            cin>>a[i];
        }
        for(int i=0;i<n2;i++) {
            cin>>b[i];
        }
        for(int i=0;i<n3;i++){
            cin>>c[i];
        }
        int i=0,j=0,l=0;
        while(i<n1&&j<n2&&l<n3){
            if(a[i]==b[j]&&b[j]==c[l]){
                v.push_back(a[i]);
                i++; j++; l++;
            }
            else if(a[i]<b[j]||a[i]<c[l])i++;
            else if(b[j]<a[i]||b[j]<c[l])j++;
            else l++;
        }
        if(v.size()==0)cout<<"-1\n";
        else {
            for(auto x:v)cout<<x<<" ";
            cout<<endl;
        }
    }
    return 0;
}