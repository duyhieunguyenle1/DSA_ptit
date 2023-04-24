#include <bits/stdc++.h> 
#define MAX 1000001  
typedef long long ll;
using namespace std;   

ll minCost(ll arr[], ll n) { 
    //B1: tao hang doi uu tien theo thu tu tang dan
	priority_queue<ll, vector<ll>, greater<ll> > pq(arr, arr + n);   
    //B2: Thiet lap ket qua ban dau la 0
    ll res = 0;   
    // lap neu hang doi uu tien con nhieu hon mot soi day
    while (pq.size() > 1) { 
        // dua ra hai soi ngan nhat
        ll first = pq.top(); //lay do dai soi thu nhat
        pq.pop(); //loai soi day ra khoi hang doi
        ll second = pq.top(); //lay do dai soi day thu 2
        pq.pop(); //loai soi day ra khoi hang doi  
        res += first + second; //lay hai soi noi voi nhau
        pq.push(first + second); //dua vao theo thu tu uu tien
    }   
    return res; 
}   
int main(void){
	ll T, n, *A; cin>>T;
	while(T--){
		cin>>n;A = new ll[n];
		for(int i=0; i<n; i++){
			cin>>A[i];
		}
		cout<<minCost(A,n)<<endl;
	}
}
