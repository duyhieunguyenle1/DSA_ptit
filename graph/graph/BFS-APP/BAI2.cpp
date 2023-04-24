//Min step to reach end of matrix
#include <bits/stdc++.h> 
#define MAX 1000 
using namespace std; 
int minSteps(int arr[][MAX], int n) { 
	//B1: khoi tao
    bool v[n][n] = { 0 }; //thiet lap trang thai cac o    
    queue<pair<int, int> > q; //tao hang doi pair
	pair <int,int> t; t.first =0;t.second =0;      
    q.push(t); //dua phan tu dau tien vao hang doi      
    int depth = 0; //do dai ban dau la 0
	//B2: lap den khi hang doi rong      
    while (q.size()!=0) {           
        int x = q.size();//lay so phan tu hang doi 
        while (x--) { //lap den khi x =0  
            // Top-most element of queue 
            pair<int, int> y = q.front(); //lay dinh   
            int i = y.first, j = y.second; //lay toa do
            q.pop(); //loai dinh  
            // Base case 
            if (v[i][j]) //neu dinh da tham
				continue; //lay dinh khac  
            // neu den dinh coi cung (n-1, n-1) 
            if (i == n - 1 && j == n - 1) 
                return depth; //tra lai do dai              
            v[i][j] = 1; //danh dau o da tham  
            if (i + arr[i][j] < n) {
            	pair <int, int> t;
            	t.first = i + arr[i][j];
            	t.second = j;
            	q.push(t);
			}
            if (j + arr[i][j] < n) {
            	pair <int, int> t;
            	t.first = i;
            	t.second = j+arr[i][j];
            	q.push(t);
			}
        } 
        depth++; 
    }   
    return -1; 
} 
// Driver code 
int main() { 
	int A[MAX][MAX], n, T;
	cin>>T; 
	while(T--){
		cin>>n;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++) 
				cin>>A[i][j];
		cout<<minSteps(arr)<<endl;
	}
}
