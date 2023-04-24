// Bai 6: Longest Palidromic Subsequence
#include<bits/stdc++.h> 
#define MAX 5000
using namespace std;   
// Solution 1: de qui (fail)
int lps(char *seq, int i, int j) { 
	// Base Case 1: If there is only 1 character 
	if (i == j) //neu chi con 1 ky tu
    	return 1;//do dai la 1  
	// neu co hai ky tu va giong nhau
	if (seq[i] == seq[j] && i + 1 == j) //do dai la 2
    	return 2;   
	// neu ky tu dau va cuoi giong nhau
	if (seq[i] == seq[j]) 
    	return lps (seq, i+1, j-1) + 2;  
	// neu ky tu dau va cuoi khac nhau
	return max( lps(seq, i, j-1), lps(seq, i+1, j) ); 
}   
//Solution 2: DP
int DPlps(char *str) { 
   	int n = strlen(str); 
   	int i, j, cl; 
   	int L[n][n];  // Bang phuong an cua bai toan    
   //Buoc co so:  do dai xau la 1
   for (i = 0; i < n; i++) 
      L[i][i] = 1; 
  
    // Buoc truy hoi:
    for (cl=2; cl<=n; cl++) { //lap tu 2 den n
        for (i=0; i<n-cl+1; i++)  { 
            j = i+cl-1; 
            if (str[i] == str[j] && cl == 2) 
               	L[i][j] = 2; 
            else if (str[i] == str[j]) 
               	L[i][j] = L[i+1][j-1] + 2; 
            else
               	L[i][j] = max(L[i][j-1], L[i+1][j]); 
        } 
    } 
  	//Buoc tru vet
    return L[0][n-1]; 
} 
// Test solution 
int main() { 
	int T, n; char str[MAX]; cin>>T;
	while(T--){
		cin>>str; n = strlen(str);
		cout<<DPlps(str)<<endl;		
	}
} 
