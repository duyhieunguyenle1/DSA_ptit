//Bai toan tong day con lien tuc lon nhat
#include <bits/stdc++.h> 
#define MAX 1000000
using namespace std;
int MaxLR(int A[], int l, int m, int h) { 
    // Include elements on left of mid. 
    int sum = 0; 
    int left_sum = INT_MIN; //thiet lap tong ben trai lon nhat
    for (int i = m; i >= l; i--) { //tinh tong day con ben trai
        sum = sum + A[i]; 
        if (sum > left_sum) 
          left_sum = sum; 
    }   
    // tinh tong day con ben phai
    sum = 0; 
    int right_sum = INT_MIN; 
    for (int i = m+1; i <= h; i++) { 
        sum = sum + A[i]; 
        if (sum > right_sum) 
          right_sum = sum; 
    }   
    // tra lai tong lon nhat day con trai & phai
    return left_sum + right_sum; 
} 
  
// tong day con lon nhat A[l..h]
int maxGlobal(int A[], int l, int h) {     
   if (l == h) // neu l=h
     return A[l];   
   // tim diem o giua 
   int m = (l + h)/2;  
   /*tra lai :  
      a) Tong lon lon nhat phia ben trai 
      b) Tong lon nhat phia ben phai 
      c) tong lon nhat cua ca day */
   return max (max(maxGlobal(A, l, m), 
              maxGlobal(A, m+1, h)),MaxLR(A, l, m, h)); 
} 
  
//test solution
int main() { 
	int *A, n, T; cin>>T;
	while(T--){
		cin>>n; A = new int[n];
		for(int i=0; i<n; i++) cin>>A[i];
		cout<<maxGlobal(A,0,n-1)<<endl;		
	}   
} 
