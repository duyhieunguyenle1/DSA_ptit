#include <bits/stdc++.h>
using namespace std;
#define MAX 10
int A[MAX], X[MAX], n, T, S, tong=50, dem;
void  Try(int i){
	for(int j=0; j<=1; j++){
		X[i] = j;
		S = S + A[i]*X[i];		
		if(i==n-1) {
			cout<<S<<endl;
		}		
		else Try(i+1); 
		S = S - A[i]*X[i];
	}		
} 
int main(void){
	cin>>T; 
	while(T--){
		cin>>n;S=0; tong=0;dem=0;
		for(int i=0; i<n; i++) {
			cin>>A[i]; 
		}				
		Try(0);
	}	
}
//8
//479 758 315 472 730 101 460 619
//8
//479 758 315 472 730 101 460 619

