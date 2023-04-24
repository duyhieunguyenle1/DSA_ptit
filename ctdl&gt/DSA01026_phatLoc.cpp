#include<bits/stdc++.h>
using namespace std;
int n,a[1000000],ok=1;
void sinh(){
    int i=n;
    while(i>=1&&a[i]==8){
        a[i]=6;
        i--;
    }
    if(i==0)ok=0;
    else a[i]=8;
}
void print(){
    for(int i=1;i<=n;i++){
        cout<<a[i];
    }
    cout<<endl;
}
bool check(){
    if(a[1]!=8||a[n]!=6)return false;
    int temp1=0,temp2=0;
    for(int i=1;i<=n;i++){
        if(a[i]==8&&temp1<2&&temp2<=3){
            temp1++;
            temp2=0;
        }else if(a[i]==6&&temp2<3&&temp1<2){
            temp1=0;
            temp2++;
        }
        else return false;
    }
    return true;
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++)a[i]=6;
    while(ok){
        if(check())print();
        sinh();
    }
}