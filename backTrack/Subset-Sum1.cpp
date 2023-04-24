// Kiem tra day so co tong bang sum
#include <bits/stdc++.h> 
using namespace std;  
bool Test(int A[], int n, int sum) { 
   	// Phep co so 
   	if (sum == 0) //neu sum la 0
     return true; 
   	if (n == 0 && sum != 0) //neu dieu nay xay ra
     	return false;      
   	if (A[n-1] > sum) //neu phan tu cuoi cung lon hon sum
     	return Test(A, n-1, sum);   
	//Nguoc lai:
      //(a) Kiem tra tap co phan tu cuoi cung 
      //(b) Hoac tap khong co phan tu cuoi cung
   return Test(A, n-1, sum) ||  
                        Test(A, n-1, sum-A[n-1]); 
} 
void Solution(int A[], int n)  {
	int S =0;
	for(int i=0; i<n; i++) S = S+ A[i];
	if(S%2) return false
	if(Test(A, n-1, S/2)) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
// Test solution 
int main() { 
  	int *A, n, T, S=0; cin>>T;
  	while(T--){
  		cin>>n; A = new int[n];
		for(int i=0; i<n; i++) {
			cin>>A[i]; S = S+A[i];
		} 					
		Solution(A, n, S); delete A;
	}  	
} 

//8
//479 758 315 472 730 101 460 619
//758+ 479+ 472 + 101
//730 + 619 + 460 + 315

