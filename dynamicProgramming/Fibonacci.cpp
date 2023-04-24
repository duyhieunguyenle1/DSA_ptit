//So Fibonacci thu n
#include<bits/stdc++.h> 
#define MAX 1000000007
typedef long long ll;
using namespace std; 
  
ll fib(int n) { 
    if (n <= 1) 
        return n; 
    return fib(n-1) + fib(n-2); 
} 
ll fib1(int n) {   
  ll f[n+2];   // mang luu cac so Fib  
  f[0] = 0;  f[1] = 1; //so fib thu nhat va thu 2  
  for (int i = 2; i <= n; i++)  {       
      f[i] = (f[i-1] + f[i-2])%MAX; 
  }   
  return f[n]; 
} 
  
int main () { 
    int T, n; cin>>T;
    while(T--){
    	cin>>n; cout << fib1(n)<<endl;
	}     
}  
