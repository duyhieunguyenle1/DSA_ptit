//Duong di cua con chuot trong me cung
//D:xuong duoi;L:dich trai;R:dich phai; U:len tren
#include <bits/stdc++.h> 
#define MAX 10
using namespace std; 
string S="";//ket qua 1 duong di
void Init(int maze[MAX][MAX], int sol[MAX][MAX], int N)   {
	//cin>>N; //nhap kich co me cung	
	for(int i=0; i<N;i++) {	//thiet lap me cung
		for(int j=0; j<N; j++) {		
			cin>>maze[i][j];//nhap gia tri cac o cua me cung
			sol[i][j] = false;//thiet lap trang thai cac o chua den
		}
	}
}
// kiem tra mot o co den duoc hay khong
bool isSafe(int x, int y, int maze[MAX][MAX], int sol[MAX][MAX], int N) { 
	if(x>=0 && x<N && y>=0 && y<N && !sol[x][y] && maze[x][y]) 
		return true;  //neu den duoc
    return false; //neu khongden duoc
}   
// Dua ra tat ca cac duong di bang DFS(0,0)
void Solution(int x, int y, int maze[MAX][MAX], int sol[MAX][MAX], int N, vector <string> &R, string &S) { 
    if (x == N - 1 && y == N - 1) {         
        R.push_back(S);//cout<<S<<" ";  
    }       
    sol[x][y] = true; //ghi nhan o (i,j) da den
  
    // de qui theo 4 huong: D, L, R, U     
    
	if (isSafe(x + 1, y, maze, sol, N)) { //neu phep D duoc chap thuan        
		S = S+"D"; //cong them vao path ki tu D
        Solution(x + 1, y, maze,sol, N, R, S);//goi DFS bat dau tai o (i+1,j) 
        S.erase(S.length() - 1); //nho hoan lai gia tri de quay lui		
    }       
    if (isSafe(x, y - 1, maze, sol, N)) { //neu phep L duoc chap thuan
        S = S+"L"; //them vao path ki tu L
        Solution(x, y - 1, maze,sol, N, R, S); //goi DFS bat dau tai o (i,j-1)
        S.erase(S.length() - 1); //nho hoan lai gia tri de quay lui           
        //path.pop_back(); 
    }   
    if (isSafe(x, y + 1, maze, sol, N))  {//neu phep R duoc chap thuan 
        S = S+"R";; //them vao path ki tu R
        Solution(x, y + 1, maze,sol, N, R, S); //goi DFS bat dau tai o (i,j+1)
        S.erase(S.length() - 1); //nho hoan lai gia tri de quay lui
		//path.pop_back(); 
    }     
    if (isSafe(x - 1, y, maze, sol, N)) { //neu phep U duoc chap thuan
        S = S+"U";; //them vao path ki tu U
        Solution(x - 1, y, maze,sol, N, R, S); //goi DFS bat dau tai o (i-1,j)
        S.erase(S.length() - 1); //nho hoan lai gia tri de quay lui       
        //path.pop_back(); 
    } 
    sol[x][y] = false; //hoan tra lai V[i][j]
}   

vector<string> printPath(int m[MAX][MAX], int n)
{
    vector <string > R; int sol[MAX][MAX];string S;    
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			sol[i][j]=false;
		}
	} 
	if(m[0][0]==0) R.push_back("-1");
	else Solution(0,0,m,sol,n,R,S);
	if(R.size()==0) R.push_back("-1");
	return R;
}
// Test solution 
int main() { 
    int T, N; cin>>T; 
    while(T--){ 
    	cin>>N; int maze[MAX][MAX], sol[MAX][MAX];
    	Init(maze, sol,N);
    	vector <string > R = printPath(maze,N);
    	for(int i=0; i<R.size(); i++) cout<<R[i]<<" ";
    	cout<<endl;
/*    	Init(maze, sol, N); Solution(0,0,maze, sol, N, R, S); 
    	if(R.size()==0)  cout<<"-1"<<endl;
		else {
			for(int i=0; i<R.size(); i++) 
    			cout<<R[i]<<" ";
    		cout<<endl;
		}  */  	    	
	}
	
} 
/*4
0 1 1 1 
1 1 1 0 
1 0 1 1 
0 0 1 1*/
