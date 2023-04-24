#include<bits/stdc++.h>
using namespace std;
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int currency[]={1,2,5,10,20,50,100,200,500,1000};
        int i=9,res=0,tmp;
        while(n>0){
            if(n>=currency[i]){
                tmp=n/currency[i];
                n=n%(tmp*currency[i]);
                res+=tmp;
            }
            i--;
        }
        cout<<res<<endl;
    }
    return 0;
}