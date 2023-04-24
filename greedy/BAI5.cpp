// Bai 5: Tim min P = A[0]*B[0] + ..+ A[n-1]*B[n-1]
#include <bits/stdc++.h> 
typedef long long ll;
using namespace std; 
ll minValue(ll A[], ll B[], int n) { 
    sort(A, A + n); //sap A[] theo thu tu tang dan
    sort(B, B + n); //sap B[] theo thu tu tang dan  
    // Tinh tong cac so min cua A[] nhan voi max cua B[]
    ll result = 0; 
    for (int i = 0; i < n; i++) 
        result += (A[i] * B[n - i - 1]); 
  
    return result; 
}   
// Test solution 
int main() { 
    ll *A, *B; int T, N; cin>>T;
    while(T--) {
    	cin>>N; A = new ll[N]; B = new ll[N];
    	for(int i=0; i<N; i++) cin>>A[i];
    	for(int i=0; i<N; i++) cin>>B[i];
    	cout<<minValue(A, B, N)<<endl;
    	delete A; delete B;
	}
} 
