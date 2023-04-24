// Giai bai toan 0-1 Knapsack 
#include <bits/stdc++.h> 
using namespace std;  
// A utility function that returns maximum of two integers 
//int max(int a, int b) { return (a > b) ? a : b; }   
// Loi giai bai toan 
void Solution(int W, int A[], int C[], int n) { 
    int i, w; 
    int T[n + 1][W + 1]; //bang phuong an cua bai toan
  	//Buoc co so: dien vao hang 1 cac so 0
  	for(int i=0, j=0; j<=W; j++){ //tui khong duoc chon do vat nao 		
  			T[0][j]=0;//gia tri toi uu la 0
	}
    //Buoc truy hoi: tinh T[i][w] theo cong thuc truy hoi
    for (int i = 1; i <= n; i++) { //duyet tren cac hang i=1, 2,..,n
        for (int w = 1; w <= W; w++) { //duyet tren cac cot j=1, 2,.., W
            if (A[i - 1] <= w) //neu dua duoc do vat i vao tui
                //T[i][w] duoc tinh theo cong thuc truy hoi
				T[i][w] = max(C[i - 1] + T[i - 1][w - A[i - 1]], T[i - 1][w]); 
            else //neu khong dua do vat i vao tui
                T[i][w] = T[i - 1][w]; //T[i][w] giu nguyen
        } 
    }   
    //Buoc truy vet: lan nguoc lai vet de dua ra ket qua
    int res = T[n][W];//gia tri toi uu cua bai toan
	cout<<"Gia tri toi uu:"<<res<<endl;   
	w = W;    
    for (i = n; i > 0 && res > 0; i--) { //lan nguoc lai          
        if (res == T[i - 1][w]) //neu khong chon goi thu i
            continue;//tiep tuc truy vet         
        else { //neu chon goi thu i 
            cout<<A[i - 1]<<" "; //dua ra goi duoc chon
            res = res - C[i - 1]; //giam gia tri phuong an
            w = w - A[i - 1]; //giam trong luong tui
        } 
    } 
}   
// Test solution 
int main() 
{ 
    int C[] = { 60, 100, 120 }; 
    int A[] = { 10, 20, 30 }; 
    int W = 50; 
    int n = sizeof(C) / sizeof(C[0]); 
      
    Solution(W, A, C, n); 
      
    return 0; 
} 
