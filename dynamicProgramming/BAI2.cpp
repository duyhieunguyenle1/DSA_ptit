// tim do dai day con tang dai nhat
#include<bits/stdc++.h>  
#define MAX 1001
using namespace std;     
//DP solution   
int LIS( int A[], int n )  {  
    int L[n]; //luu do dai day con tang dai nhat   
    //Buoc co so: do dai day con tang dai nhat 1 phan tu la 1
	L[0] = 1;    
  	//Buoc xay dung bang phuong an    
    for (int i = 1; i < n; i++ )  { //duyet tren tap phan tu con lai
        L[i] = 1; //tam thoi lay L[i] it nhat la 1
        for (int j = 0; j < i; j++ ) //duyet cac phan tu tu i den j  
            if ( A[i] > A[j] && L[i] < L[j] + 1)  //neu dieu nay xay ra
                L[i] = L[j] + 1;  //tang do dai len 1
    }   
    // ket qua la max cac phan tu cua L[] 
    return *max_element(L, L+n); 
}      
// Test solution
int main()  {  
	int A[MAX], n, T; cin>>T;
	while(T--) {
		cin>>n;
		for(int i=0; i<n; i++) cin>>A[i];
		cout<<LIS(A,n)<<endl;
	}
}
