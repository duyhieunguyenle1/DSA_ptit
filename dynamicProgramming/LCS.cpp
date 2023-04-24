// Bai toan tim do dai xau con chung dai nhat
// LCS: Longest Common Subsequence Problem
#include <bits/stdc++.h>
#define MAX 1000 
using namespace std;   
// Solution1: do phuc tap ham mu (submit fail)
int Solution1( char *X, char *Y, int m, int n )  {  
    if (m == 0 || n == 0)  //neu n=0 hoac m=0
        return 0;//do dai xau con chung la 0  
    if (X[m-1] == Y[n-1])//neu ky tu cuoi cung hai xau giong nhau
        //do dai xau con chung duoc tinh theo cong thuc nay
		return 1 + Solution1(X, Y, m-1, n-1);  
    else //neu ky tu cuoi cung hai xau khac nhau
	    //do dai xau con chung duoc tinh theo cong thuc nay
        return max(Solution1(X, Y, m, n-1), Solution1(X, Y, m-1, n));  
}  
//Solution2: Do phuc tap m.n (submit OK)
int Solution2( char *X, char *Y, int m, int n )  {  
    int L[m + 1][n + 1];  //Bang phuong an cua bai toan        
    //Buoc co so: giai bai toan voi n=0, m=0
    for(int i=0; i<=m; i++){
    	for(int j=0; j<=n; j++) {
    		if(i==0 || j==0) 
    			L[i][j]=0;
		}
	}
	//Buoc truy hoi: tinh toan theo cong thuc truy hoi
    for ( int i = 1; i<= m; i++)  { //duyet cac ky tu cua xau X 
        for ( int j = 1; j <= n; j++)  { //duyet cac ky tu cua xau Y 
        	if (X[i - 1] == Y[j - 1])  //neu hai ky tu giong nhau
            	//L[i][j] duoc tinh theo cong thuc nay
				L[i][j] = L[i - 1][j - 1] + 1;        
        	else
        		//L[i][j] duoc tinh theo cong thuc nay
            	L[i][j] = max(L[i - 1][j], L[i][j - 1]);  
        }  
    }  
    //Buoc truy vet
    return L[m][n];//chi can tra lai L[m][n]   
}   
//test solution 
int main()  {  
	char X[MAX], Y[MAX];
	int T, m,n; cin>>T;
	while(T--) {
		cin>>m>>n;
		for(int i=0; i<m; i++) cin>>X[i];
		for(int i=0; i<n; i++) cin>>Y[i];		
		cout<<Solution2(X,Y,m,n)<<endl;
	}
}
//X = AGGTAB; Y = GXTXAYB, m=6, n=7
