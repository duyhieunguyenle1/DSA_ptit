// Nang x len luy thua y mod p: x, y<pow(10,10) 
#include <bits/stdc++.h>
typedef long long ll; 
#define MAX 1000000007
ll const k = 1e9 + 7;
using namespace std; 
//Phuong de qui: do phuc tap O(n); Submit : Fail
ll power1(ll x, ll y) { 	
    if (y == 0) 
        return 1; 
    else if (y % 2 == 0) 
        return ( ( (power1(x%MAX, y / 2)%MAX) * (power1(x%MAX, y / 2)%MAX )) %MAX); 
    else
        return (((x%MAX) * (( power1(x%MAX, y / 2) * power1(x%MAX, y / 2)) %MAX))%MAX); 
}   
//Phuong de qui: do phuc tap log(n);Submit : OK
ll power2(ll x, ll y) { 
    ll temp; 
    if( y == 0) 
        return 1; 
    temp = power2(x%MAX, y/2) %MAX; 
    if (y%2 == 0) 
        return (((temp%MAX) *(temp%MAX))%MAX); 
    else
        return ( (x%MAX) * (((temp%MAX)*(temp%MAX))%MAX) ) %MAX;
} 
//Phuong phap lap: do phuc tap log(n); Submit : OK
ll power3(ll x, ll y)  {  
    if(y==0) return 1;
	ll res = 1;     // Initialize result    
    x = x % k; // lay x la so nho hon MAX 	 
    if (x == 0) return 0; // trong truong ho x chia het cho p  
    while (y > 0)  {          
        if (y & 1)  //neu y la le
            res = (res*x) % k;    
        // y tro thanh chan 
        y = y>>1; // y = y/2  
        x = (x*x) % k;  
    }  
    return res;  
}  
//test solution 
int main()  {  
	ll x, y, T; cin>>T;	
	while(T--){
		cin>>x>>y; 
		//cout<<power1(x,y)<<endl;: 3phut
		//cout<<power2(x,y)<<endl;:1/10 sec
		cout<<power3(x,y)<<endl;://1/10sec
	}
}  
// x = 10000000000; y=1
//999999937
//x=9767; y = 7679 
//226121821
//x=1804289384; y = 4839824081
// 356633793

