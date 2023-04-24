// Tim gia tri lon nhat cua tong i*arr[i]
#include<bits/stdc++.h> 
#define MAX 1000000007
typedef long long int ll;
using namespace std;   
ll maxSum(ll arr[], int n) {   
  	//B1: sap theo thu tu tang dan 
  	sort(arr, arr + n);   
  	//B2: tim  tong arr[i]*i 
  	ll sum = 0; 
  	for (int i = 0; i < n; i++) {
  		sum += (arr[i]*i);
  		sum = sum%MAX;
  	}
  	//B3: Tra lai ket qua
   	return sum; 
}   
// Test Solution 
int main() { 
	int T, n; ll *A; cin>>T;
	while(T--){
		cin>>n; A = new ll[n];
		for(int i=0; i<n; i++) cin>>A[i];
		cout<<maxSum(A,n)<<endl;
		delete A;
	}
}  
