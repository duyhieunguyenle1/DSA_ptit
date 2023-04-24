#include<iostream>
using namespace std;
bool primeNumber(int n){
    if(n<=3)return n>1;
    if(n%2==0||n%3==0)return false;
    int i=5;
    while(i*i<=n){
        if(n%i==0||n%(i+2)==0)return false;
        i+=6;
    }
    return true;
}
int main(){
    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        int check=0;
        for(int i=2;i<=n;i++){
            if(primeNumber(i)&&primeNumber(n-i)){
                cout<<i<<" "<<n-i;
                check=1;
                break;
            }
        }
        if(check==0)cout<<"-1";
        cout<<endl;
    }
    return 0;
}