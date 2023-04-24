#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
/* Trên ma trận có n hàng m cột , để di chuyển từ ô (0,0) đến vị trí 
(n-1,m-1) ta bắt buộc phải di chuyển n - 1 xuống dưới ,
m - 1 bước sang phải . 
Tổng số bước di chuyển là (n + m - 2 )bước , 
trong đó có đúng n - 1 bước xuống dưới. 
Hay nói cách khác trong (n+m-2) bước cần phải chọn ra đúng 
n-1 bước xuống dưới. 
--> Số cách di chuyển là C(n-1, n+m-2) */
ll giaiThua(int x){
    ll res=1;
    for(int i=1;i<=x;i++)res*=i;
    return res;
}
int main(){
    int t; cin>>t;
    while(t--){
        int m,n; cin>>m>>n;
        int a[m][n];
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)cin>>a[i][j];
        }
        ll mau = (giaiThua(n-1)*giaiThua(m-1));
        cout<<giaiThua(n+m-2)/mau<<endl;
    }
}