// Nang x len luy thua y mod p 
#include <bits/stdc++.h>
typedef long long ll; 
#define MAX 1000000007
ll const k = 1e9 + 7;
using namespace std; 
  
//Phuong phap lap: power(x,y)%MAX
ll power(ll x, unsigned int y)  {  
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
ll reverse(int x) {
	ll p=0;
	while(x!=0) {
		p = p*10 + x%10;
		x = x/10;
	}
	return p;
}
//test solution 
int main()  {  
	ll x, y, T; cin>>T;	
	while(T--){
		cin>>x; y =reverse(x);
		cout<<power(x,y)<<endl;
	}
}  
// x = 10000000000
//Its Correct output is:999999937

