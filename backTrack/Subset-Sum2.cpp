#include <bits/stdc++.h>
using namespace std;
#define MAX 10
int A[MAX], X[MAX], n, K, dem, S;
void Init(void){
	cin>>n>>K;
	for(int i=0; i<n; i++) cin>>A[i];
	dem =0 ; S = 0;
}
void Try(int i){
	for(int j=0; j<=1; j++){
		X[i] = j;
		S = S + A[i]*X[i];		
		if(i==n-1) {
			if(S==K) dem++;			
		}		
		else Try(i+1); 
		S = S - A[i]*X[i];
	}		
} 
int main(void){
	int T; cin>>T; Init();
	while(T--){
		Try(0); cout<<dem<<endl;	
	}	
}
