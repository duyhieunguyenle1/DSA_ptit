// Nghich so cua mot mang
#include <bits/stdc++.h> 
typedef long long ll;
using namespace std; 
//Solution 1: submit fail
int getInvCount(ll A[], int n) { 
    ll ans = 0; 
    for (int i = 0; i < n - 1; i++) 
        for (int j = i + 1; j < n; j++) 
            if (A[i] > A[j]) 
                ans++; 
  
    return ans; 
} 
// Solution 2: su dung sap xep kieu Merge 
ll merge(ll A[], ll temp[], int L, int M, int R) { 
    int i, j, k; 
    ll inv_count = 0;   
    i = L; // i la chi so mang con ben trai
    j = M; // j la chi so mang con ben phao
    k = L; //chi so de luu ket qua hop nhat
    while ((i <= M - 1) && (j <= R)) { 
        if (A[i] <= A[j]) { 
            temp[k++] = A[i++]; 
        } 
        else { 
            temp[k++] = A[j++];   
            //dieu nay co nghia so nghich cua mang la (M-i)            
            inv_count = inv_count + (M - i); 
        } 
    }   
    //copy phan con lai cua mang
    while (i <= M - 1) 
        temp[k++] = A[i++];   
    while (j <= R) 
        temp[k++] = A[j++];   
    //chuyen vao mang ban dau
    for (i = L; i <= R; i++) 
	    A[i] = temp[i];   
    return inv_count; 
} 
// ham sap xep va tra lai so nghich cua mang
ll Partition(ll A[], ll temp[], int L, int R) { 
    int M; ll inv_count = 0; 
    if (R > L) { 
        M = (R + L) / 2; 
        inv_count += Partition(A, temp, L, M); 
        inv_count += Partition(A, temp, M + 1, R); 
        inv_count += merge(A, temp, L, M + 1, R); 
    } 
    return inv_count; 
} 

// Sap xep va tra lai so nghich the
ll mergeSort(ll A[], int n) { 
    ll temp[n]; 
    return Partition(A, temp, 0, n - 1); 
}   
// Test solution
int main() { 
    ll *A; int T, n; cin>>T;
    while(T--) {
    	cin>>n; A = new ll[n];
    	for(int i=0; i<n; i++) cin>>A[i];
    	cout<<mergeSort(A,n)<<endl;
	}
} 
