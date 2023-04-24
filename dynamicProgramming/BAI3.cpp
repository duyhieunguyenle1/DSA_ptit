// Bai 3: Subset Sum 
#include <bits/stdc++.h> 
#define MAX 201
using namespace std;
//Solution 1: botton up (fail)
bool Solution1(int A[], int n, int S) { 
   	// Base Cases 
   	if (S == 0) 
     	return true; 
   	if (n == 0 && S != 0) 
     	return false;   
   	// neu phan tu cuoi cung lon hon S
   	if (A[n-1] > S) 
     	return Solution1(A, n-1, S); //thu tap n-1 phan tu con lai  
   	//Kiem tra S trong cac truong hop
      //(a) co phan tu cuoi cung 
      //(b) khong co phan tu cuoi cung
   	return Solution1(A,n-1,S) ||Solution1(A,n-1,S-A[n-1]); 
}    
// Solution 2: DP solution (submit OK)
bool Solution2(int A[], int n, int S) { 
    // The value of subA[i][j] will be true if there is a  
    // goi tap con cua A[0..j-1] co tong la i 
    bool T[n+1][S+1]; //bang phuong an cua bai toan   
    // Buoc co so:  
    for (int i = 0; i <= n; i++) //giai bai toan voi S=0
      	T[i][0] = true;        
    for (int i = 1; i <= S; i++) //giai bai toan voi n=0
      	T[0][i] = false;    
    // Buoc truy hoi: dien cac hang tu duoi len
    for (int i = 1; i <= n; i++) { //duyet cac hang tu 1,..,n
       	for (int j = 1; j <= S; j++) { //duyet cac cot tu 1 den S
         	if(j<A[i-1]) //neu i be hon A[i-1]
         		//gia tri cua T[i][j] duoc dien theo cong thuc nay
				T[i][j] = T[i-1][j]; 
         	if (j >= A[i-1]) //neu dieu nay xay ra
           		//dien T[i][j] theo cong thuc nay
				T[i][j] = T[i-1][j] ||T[i - 1][j-A[i-1]]; 
       	} 
    } 
	//day la gia tri cua bang phuong an        
    for (int i = 0; i <= n; i++) { 
       	for (int j = 0; j <= S; j++) 
          	cout<<T[i][j]<<" "; 
       cout<<endl; 
    }
	//Buoc truy vet:   
    return T[n][S]; //tra lai gia tri S
}    
// Test solution 
int main() { 
	int A[MAX], T, n, S; cin>>T;
	while(T--) {
		cin>>n>>S;
		for(int i=0; i<n; i++) cin>>A[i];
		if(Solution2(A,n,S)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
} 
