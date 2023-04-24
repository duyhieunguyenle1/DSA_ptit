//Tim so fibonacci thu n
//So Fibonacci thu n
#include<bits/stdc++.h> 
#define MAX 1000000007
typedef long long ll;
using namespace std; 
//Solution1: submit fail 
ll Fib1(int n) { 
    if (n <= 1) 
        return n; 
    return (Fib1(n-1) + Fib1(n-2))%MAX; 
} 
//Solution 2: qui hoach dong. Submit OK.
int Fib2(int n) {   
  	int f[n+2];//mang luu cac so Fibinacci  
  	f[0] = 0;  f[1] = 1; //hai so Fibonacci dau tien  
  	for (int i = 2; i <= n; i++) { 
      	f[i] = (f[i-1] + f[i-2])%MAX; 
  	}   
  	return f[n]; 
} 
//Toi uu Solution 2. Submit OK.
int Fib_2(int n) {   
  	int Fn_2=0, Fn_1=1,Fn;//khoi dau fn-1, fn-2, f   	
  	for (int i = 2; i <= n; i++) { 
      	Fn = (Fn_2 + Fn_1)%MAX; 
      	Fn_2 = Fn_1; Fn_1 = Fn;
  	}   
  	return Fn_1; 
}
//Solution 3: luy thua ma tran. Submid OK
//ham nhan hai ma tran  
void multiply(int F[2][2], int M[2][2]) { 
  	int x = (F[0][0]*M[0][0] + F[0][1]*M[1][0])%MAX;
	int y = (F[0][0]*M[0][1] + F[0][1]*M[1][1])%MAX;  
  	int z = (F[1][0]*M[0][0] + F[1][1]*M[1][0])%MAX; 
  	int w =  (F[1][0]*M[0][1] + F[1][1]*M[1][1])%MAX; 	    
  	F[0][0] = x;  F[0][1] = y;  F[1][0] = z;  F[1][1] = w; 
} 
//lay luy thua n ma tran F[][] 
void power(int F[2][2], int n) {   
  	int M[2][2] = {{1,1},{1,0}};   
  	// nhan n - 1 lan ma tran {{1,0},{0,1}} 
  	for (int i = 2; i <= n; i++) 
    	multiply(F, M); 
} 
//tim so fibonacci thu n
int Fib3(int n) { 
  	int F[2][2] = {{1,1},{1,0}}; 
  	if (n == 0) 
      	return 0; 
  	power(F, n-1);   
  	return F[0][0]; 
} 
//Solution 4: luy thua ma tran. Submid OK. Time: O(log(n))
//lay luy thua n ma tran F[][] 
void power1(int F[2][2], int n) { 
  	if( n == 0 || n == 1) 
      	return; 
  	int M[2][2] = {{1,1},{1,0}};   
  	power1(F, n/2); 
  	multiply(F, F);   
  	if (n%2 != 0) 
     	multiply(F, M); 
} 
// tim so fibonacci thu n
int Fib4(int n) { 
  	int F[2][2] = {{1,1},{1,0}}; 
  	if (n == 0) 
    	return 0; 
  	power1(F, n-1); 
  	return F[0][0]; 
} 
int main (void) { 
	int T, n;cin>>T;
	while(T--){
		cin>>n; cout<<Fib3(n)<<endl;
	}
}  
//5
//50: 586268941
//60: 8745084
//70: 489376391
//100: 687995182
//1000: 517691607
//1000000000
