// Binary Search 
#include <bits/stdc++.h> 
using namespace std; 
int binarySearch(int A[], int L, int H, int X) { 
    if (L <= H) { 
    	//lay  M la vi tri giua L va H
        int M = L + (H - L) / 2; 
        if (A[M] == X) //neu phan tu o giua la X
            return M; //day chinh la vi tri can tim
        if (A[M] > X) //neu phan tu o giua lon hon x
            //tim nhi phan trong doan [L, M-1]
			return binarySearch(A, L, M - 1, X);   
        // truong hop khac tim nhi phan trong doan [mid+1, H]         
        return binarySearch(A, M + 1, H, X); 
    }   
    // neu L>H ket luan khong tim thay X
    return -1; 
} 
//thu tuc tim kiem nhi phan khong de qui
int binarySearch1(int A[], int L, int H, int X) { 
    while (L <= H) { //lap khi nao L<=H
        int M = L + (H - L) / 2; //lay M o giua          
        if (A[M] == X) //neu X la A[M]
            return M;//tra lai vi tri can tim  
        // If x greater, ignore left half 
        if (A[M] < X) //neu X lo hon A[M]
            L = M + 1; //thay doi can duoi          
        else //neu X nho hon A[M]
            H = M - 1;//thay doi can tren
    }   
    // neu can duoi vuot qua can tren: L>H
    return -1; //ket luan tim khong thay
} 
//Test solution  
int main(void) { 
    int *A, N, T, X; cin>>T;
    while(T--){
    	cin>>N>>X; A = new int[N];
    	for(int i=0; i<N; i++) cin>>A[i];
    	cout<<binarySearch(A, 0, N-1, X)<<endl;
	}
} 
