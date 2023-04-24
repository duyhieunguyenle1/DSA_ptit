//Bai 1: Tam giac tong
#include<bits/stdc++.h>
#define MAX 10
using namespace std;
// In ket qua cua tam giac tong
void Result(int A[], int n){
	cout<<"[";//dua ra dau "["
	//dua noi dung mang A[]
	for(int i=0; i<n; i++) { 
		cout<<A[i]<<" ";
	}
	cout<<"]";//dua ra dau "["
}
void Triangle(int A[] , int n) {    
    if (n < 1) // dieu kien giai
        return;        
    int temp[n - 1];//tao mang phu temp
    for (int i = 0; i < n - 1; i++){ //tao mang tong
        int x = A[i] + A[i + 1];
        temp[i] = x;
    } 
    Triangle(temp , n-1);//lam nhu vay voi temp
    Result(A,n);//dua ra mang ket qua
} 
void Triangle1(int A[] , int n){
	if(n<1) return;
	else {		
		Result(A,n); int temp[n-1];
		for(int i=0; i<n-1; i++){
			int x = A[i]+A[i+1];
			temp[i]=x;
		}
		Triangle1(temp , n-1);		
	}
} 
int main(){ 
	int T, A[MAX], n; cin>>T;
	while(T--) {
		cin>>n; 
		for(int i=0; i<n; i++) cin>>A[i];
		Triangle1(A,n); 
		cout<<endl;//ket thuc moi test
	}
}
     
