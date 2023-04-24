// Sap xep tham lam xung quanh phan tu giua
#include <bits/stdc++.h> 
using namespace std;   
bool Solution(int A[], int n) { 
    int B[n]; //tao mang phu B[]      
    copy(A, A + n, B); //copy A vao B      
    sort(B, B + n); //sap xep B  
    //A[] = { 1, 7, 6, 4, 5, 3, 2, 8 }; 
    //B[] = {1, 2, 3, 4, 5, 6, 7, 8 };
    for (int i = 0; i < n; i++) {   
        //kiem tra hinh anh phan chieu cua A[] va B[]
        if (!(A[i] == B[i]) && !(A[n - i - 1] == B[i])) 
            return false; 
    }   
    return true; 
}   
// Test Solution
int main() { 
	int *A, T, n; cin>>T;
	while (T--){
		cin>>n; A = new int[n];
		for(int i=0; i<n; i++) cin>>A[i];
		cout<<Solution(A,n)<<endl;
		delete A;
	}
}
