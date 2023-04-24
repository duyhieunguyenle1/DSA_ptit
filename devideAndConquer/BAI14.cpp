// Nhan hai da thuc su dung mang 
#include <bits/stdc++.h> 
#define MAX 200
using namespace std; 
int *multiply(int A[], int B[], int m, int n) { 
   //da thuc tich
   int *prod = new int[m+n-1];   
   // thiet lap tat ca he so la 0 
   for (int i = 0; i<m+n-1; i++) 
     	prod[i] = 0;   
   // nhan hai da thuc 
   for (int i=0; i<m; i++)   { 
     for (int j=0; j<n; j++) 
         prod[i+j] += A[i]*B[j]; 
   }   
   return prod; 
}   
// Dua ra da thuc tich 
void printPoly(int poly[], int n) { 
    for (int i=0; i<n; i++)  { 
       cout << poly[i]<<" "; 
    } 
    cout<<endl;
}   
// Test solution 
int main() { 
    // The following array represents polynomial 5 + 10x^2 + 6x^3 
    int A[MAX], B[MAX]; int m, n, T; cin>>T;
    while(T--) {
    	cin>>m>>n; 
		for(int i=0; i<m; i++) cin>>A[i];
		for(int i=0; i<n; i++) cin>>B[i];
		int *prod = multiply(A, B, m, n);
    	printPoly(prod, m+n-1);
	}
} 
