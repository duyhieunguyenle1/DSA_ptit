// Tim tong nho nhat cua hai so duoc tao ra tu tat ca cac so trong mang
// Chu y phai lam voi so lon khi n>20
#include<bits/stdc++.h> 
#define MAX 101
using namespace std;   
int minSum(int a[], int n){       
    //B1:  sap xep cac phan tu trong mang 
    sort(a,a+n); 
    //B2: chien luoc tham lam  
    int num1 = 0; //so nho nhat
    int num2 = 0; //so nho thu nhi
    for(int i = 0;i<n;i++){ 
        if(i%2==0) //neu i chan
            num1 = num1*10+a[i]; 
        else //neu i le
			num2 = num2*10+a[i]; 
    } 
    //tra lai tong so nho thu nhat va so nho thu nhi
    return num2+num1; 
} 
  
// Test solution 
int main() { 
	int A[MAX], n, T; cin>>T;
	while(T--) {
		cin>>n;
		for(int i=0; i<n; i++) cin>>A[i];
		cout<<minSum(A,n)<<endl;
	}
} 
