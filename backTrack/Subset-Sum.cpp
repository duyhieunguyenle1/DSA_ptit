// Kiem tra day so co tong bang sum
#include <bits/stdc++.h> 
using namespace std;  
bool Solution(int A[], int n, int sum) { 
   	// Phep co so 
   	if (sum == 0) //neu sum la 0
     return true; 
   	if (n == 0 && sum != 0) //neu dieu nay xay ra
     	return false;      
   	if (A[n-1] > sum) //neu phan tu cuoi cung lon hon sum
     	return Solution(A, n-1, sum);   
	//Nguoc lai:
      //(a) Kiem tra tap co phan tu cuoi cung 
      //(b) Hoac tap khong co phan tu cuoi cung
   return Solution(A, n-1, sum) ||  
                        Solution(A, n-1, sum-A[n-1]); 
} 
  
// Test solution 
int main() { 
  	int *A, n, T; cin>>T;
  	while(T--){
  		cin>>n; A = new int[n];
		for(int i=0; i<n; i++)  		
			cin>>A[i];
		if(Solution(A,n) ) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
  	
} 
