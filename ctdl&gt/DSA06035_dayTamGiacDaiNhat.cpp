#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// Cách làm: dùng mảng để đếm số các số tăng/giảm dần
//      12 4 78 90 45 23
// tăng 1  1 2  3  1  1
// giảm 2  1 1  3  2  1

void Solution(int n){
    int a[n+5],l[n+5]={},r[n+5]={};
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        if(a[i]>a[i-1])l[i]=l[i-1]+1;
        else l[i]=1;
    }
    for(int i=n;i>=1;i--){
        if(a[i]>a[i+1])r[i]=r[i+1]+1;
        else r[i]=1;
    }
    int MAX=0;
    for(int i=1;i<=n;i++){
        MAX=max(MAX,l[i]+r[i]-1);
    }
    cout<<MAX<<endl;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        int n; cin>>n;
        Solution(n);
    }
    return 0;
}