#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll Solution(ll a[],int n){
    // sắp xếp hàng đợi theo thứ tự tăng dần
    priority_queue<ll,vector<ll>,greater<ll>>pq;
    ll res = 0;
    for(int i=0;i<n;i++){
        pq.push(a[i]);
    }
    while(pq.size()>1){
        ll first = pq.top();
        pq.pop();
        ll second = pq.top();
        pq.pop();
        res+=first+second;
        pq.push(first+second);
    }
    return res;
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        ll a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        cout<<Solution(a,n)<<endl;
    }
}