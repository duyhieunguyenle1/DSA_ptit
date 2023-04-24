// Tim hieu lon nhat cua mang co do dai K va N-K phan tu 
#include <bits/stdc++.h> 
#define MAX 100
using namespace std;   
int maxDiff(int A[], int N, int K) { 
    int M, S = 0, S1 = 0, max_diff = 0;   
    //B1: tinh tong cac phan tu
    for (int i = 0; i < N; i++) 
        S += A[i]; 
  	//B2: Sap xep theo thu tu giam    
    sort(A, A + N, greater<int>()); 
    //B3: tham lam
    M = max(K, N - K); //lay M la max hai so K va N-K
    for (int i = 0; i < M; i++) //tim tong M so lon nhat
        S1 += A[i];   
    //B4: tinh hieu nho nhat 
    max_diff = S1 - (S - S1); 
    return max_diff; 
}   
// Test solution 
int main() { 
    int A[MAX], N,K, T; cin>>T;       
	while(T--){
		cin>>N>>K;
		for(int i=0; i<N; i++) cin>>A[i];
		cout<<maxDiff(A, N, K)<<endl;
	}
} 
