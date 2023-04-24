// Dua ra tat ca cac tap con co tong la sum
#include <bits/stdc++.h> 
#define MAX 10
using namespace std;   
// su dung vector v luu tap con hien tai 
void Try(int A[], int n, vector<int> v, int sum) { 
    if (sum == 0) { //dua ra tat ca cac phan tu cua tap con hien tai
        for (int i=0; i<v.size(); i++) 
            cout << v[i] << " "; 
        cout << endl; 
        return; 
    }       
    if (n == 0) //neu khong con phan tu nao
        return;  	
    Try(A, n - 1, v, sum); //tap con khong chua phan tu cuoi cung
    v.push_back(A[n - 1]); //dua phan tu cuoi cung vao tap con
    Try(A, n - 1, v, sum - A[n - 1]); ////tap con chua phan tu cuoi cung
}   
// duyet tat ca cac tap con 
void Solution(int A[], int n, int sum) { 
    vector<int> v; 
    Try(A, n, v, sum); 
} 
// Driver code 
int main() { 
	int T, n, A[MAX], sum;cin>>T;
    while(T--) {
    	cin>>n>>sum; vector <int> v;
    	for(int i=0; i<n; i++) cin>>A[i];
    	Try(A,n,v,sum);
	}
} 
