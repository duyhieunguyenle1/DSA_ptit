// Min Step to Reach End Aray
#include <bits/stdc++.h> 
using namespace std;  
int minSteps(int A[], int n) { 
    bool chuaxet[n] = { 0 };//mang ghi nhan trang thai phan tu  
    queue<int> q; //tao hang doi cho BFS  
    // Push the source i.e. index 0 
    q.push(0); //dua vi tri 0 vao hang doi  
    int depth = 0; //do dai duong di ban dau la 0  
    // thuat toan BFS 
    //A[] = { 1, 1, 1, 1, 1, 1 };
    while (q.size() != 0) {   
        // Current queue size 
        int x = q.size(); // lay kich co queue
        while (x--) { //lap den khi x=0              
            int i = q.front(); //lay phan tu dau tien
            q.pop(); //loai ra khoi queue              
            if (chuaxet[i]) //neu chuaxet[i] la true
                continue; //tiep tuc lap  
            // If we reach the destination             
            if (i == n - 1) //neu da o cuoi cung
                return depth; //do dai nho nhat la depth  
            // Marking the cell visited 
            chuaxet[i] = 1; //thiet lap vi tri da tham  
            if (i + A[i] < n) //neu dieu nay xay ra
                q.push(i + A[i]); //dua phan tu nay vao hang doi
            if (i - A[i] >= 0) //neu dieu nay xay ra
                q.push(i - A[i]); //dua phan tu nay vao hang doi
        } 
        depth++; //tang buoc di
    }   
    return -1; 
} 
// Driver code 
int main() { 
	int T, *A, N;cin>>T;
	while(T--){
		cin>>N; A = new int[N];
		for(int i=0; i<N; i++) cin>>A[i];
		cout<<minSteps(A,N)<<endl;
		delete A;
	}
} 
