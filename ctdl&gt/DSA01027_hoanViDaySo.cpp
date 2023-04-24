#include<bits/stdc++.h>
using namespace std;
int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    do{
        for(int i=0;i<n;i++)cout<<a[i]<<" ";
        cout<<endl;
    } while (next_permutation(a,a+n));

}