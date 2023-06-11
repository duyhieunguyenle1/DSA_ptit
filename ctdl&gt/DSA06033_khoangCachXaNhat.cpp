#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// tạo 1 mảng lưu giá trị max của 2 phần tử
// từ đầu đến cuối
// so sánh 2 mảng nếu a[i]<MAX[j] thì tăng j
// nếu ko thì tăng i
// a[i]=MAX[j] thì 2 mảng như nhau -> ko có

void Solution(int n,int a[]){
    int l=0,r=n-1;
    int MAX[n],ans=-1;
    MAX[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--)MAX[i]=max(MAX[i+1],a[i]);
    int i=0,j=0;
    while(i<n and j<n){
        if(MAX[j]>a[i]){
            ans=max(ans,j-i);
            j++;
        }
        else i++;
    }
    if(!ans)ans=1;
    cout<<ans<<endl;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        Solution(n,a);
    }
    return 0;
}