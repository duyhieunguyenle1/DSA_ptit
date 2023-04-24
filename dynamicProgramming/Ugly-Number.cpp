// Tim so ugly thu n 
# include<bits/stdc++.h> 
typedef long long ll;
using namespace std;   
//ham tra lai so nguyen a khong chia het cho luy thua cua b  
ll maxDivide(ll a, ll b) { 
  	while (a%b == 0) 
   		a = a/b;  
  	return a; 
}       
// ham kiem tra mot so co la ugly hay khong
bool isUgly(ll n) { 
  	n = maxDivide(n, 2); //so khong chia het co luy thua 2
  	n = maxDivide(n, 3); //so khong chia het co luy thua 3
  	n = maxDivide(n, 5); //so khong chia het co luy thua 5    
  	return (n == 1); //neu con lai 1 se dung la ugly
}     
  
// ham nhan so ugly thu n: submit fail
ll Solution(ll n) { 
  	ll i = 1, count = 1; //so ugly dau tien la 1  	
  	while (count < n )  { 
    	i++;       
    	if (isUgly(i)) 
      		count++;  
 	} 
  	return i; 
}   
// Phuong phap qui hoach dong: submit OK
ll DP_Solution(ll n) { 
    ll ugly[n]; // To store ugly numbers 
    ll i2 = 0, i3 = 0, i5 = 0; 
    ll next_2 = 2; //day cac so xuat phat tu 2
    ll next_3 = 3; //day cac so xuat phat tu 3
    ll next_5 = 5; //day cac so xuat phat tu 5
    ll next = 1; //so dau tien la 1  
    ugly[0] = 1; //ghi nhan so dau tien la 1
    for (ll i=1; i<n; i++)  { 
       	//lay so nho nhat trong cac so xuat phat tu day 2, 3, 5
		next = min(next_2, min(next_3,next_5)); 
       	ugly[i] = next; //so ugly thu i la next
       	if (next == next_2) { //neu next==next_2
           	i2 = i2+1; //tang i2  len 1
           	next_2 = ugly[i2]*2; //next_2 tiep theo
       	} 
       	if (next == next_3) { //neu next==next_3
           	i3 = i3+1; //tang i3 len 1
           	next_3 = ugly[i3]*3; //next_3 tiep theo 
       	} 
       	if (next == next_5) { //neu next==next_5
           	i5 = i5+1; //tang i5 len 1
           	next_5 = ugly[i5]*5;//next_5 tiep theo 
       	}        	
    } 
    return next; 
} 
//test solution
int main() { 
    ll T, n; cin>>T;
    while(T--) {
    	cin>>n; 
		//cout<<Solution(n)<<endl;//submit fail
		cout<<DP_Solution(n)<<endl;//submit OK
	}
} 
