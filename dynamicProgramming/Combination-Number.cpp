//tim C(n,k)
#include<bits/stdc++.h> 
using namespace std; 
const unsigned int p = 1000000007;  
// Returns nCr % p 
int nCrModp(int n, int r) { 
    // tam giac Pascal nCr 
    int C[r+1]; //tao mang r+1 phan tu    
    memset(C, 0, sizeof(C)); //thiet lap C[i]=0: i=0,.., r  
    C[0] = 1; //phan tu dau tien la 1  
    //xay dung tam giac Pascal tu C[0]=1
    for (int i = 1; i <= n; i++){ //ke tu C(i, r tro di)
        // dien vao gia tri
        for (int j = min(i, r); j > 0; j--)   
            // nCj = (n-1)Cj + (n-1)C(j-1); 
            C[j] = (C[j] + C[j-1])%p; 
    } 
    return C[r]; 
} 
// Driver program 
int main() { 
    int T, n, r; cin>>T;
    while(T--){
    	cin>>n>>r;
    	cout<<nCrModp(n,r)<<endl;
	}
}
