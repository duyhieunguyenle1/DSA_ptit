// tim max moi day con lien tuc do dai k
#include <bits/stdc++.h> 
using namespace std; 
//Do phuc tap O(n.k): submit fail
void Solution1(int A[], int n, int k){
    int j, max;        
    for (int i=0; i<=n-k; i++){//duyet n-k day con lien tuc do dai k
        max = A[i]; //lay max = A[i]   
        for (j = 1; j < k; j++) {  //duyet k-1 phan tu tiep theo
            if (A[i + j] > max)  //neu phat hien dieu nay
                max = A[i + j]; //doi gia tri cua max 
        }  
        cout << max << " ";  //max cua tat ca day con lien tuc do dai k
    }  
    cout<<endl;
}  
int main()  {  
	int T, *A, n, k; cin>>T;
	while(T--){
		cin>>n>>k; A = new int[n];
		for(int i=0; i<n; i++) cin>>A[i];
		Solution1(A, n, k);
		delete A;
	}	
    //int A[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };  
}
