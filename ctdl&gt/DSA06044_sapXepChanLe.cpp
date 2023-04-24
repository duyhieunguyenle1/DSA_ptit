#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int n; cin>>n;
    vector<int>a(n);
    vector<int>odd,even;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i+=2)odd.push_back(a[i]);
    for(int i=1;i<n;i+=2)even.push_back(a[i]);
    sort(even.begin(),even.end(),cmp);
    sort(odd.begin(),odd.end());
    int m=n;
    n>>=1; // n=Math.floor(n/2);
    for(int i=0;i<n;i++)cout<<odd[i]<<" "<<even[i]<<" ";
    // bcz the last element always be odds so check if 
    // theres an element left then add on
    // if its end up with even element so n should be covering them up
    if(m&1) //m%2!=0
        cout<<odd.back()<<" ";
}