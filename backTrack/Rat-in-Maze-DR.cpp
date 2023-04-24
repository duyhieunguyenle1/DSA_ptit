//Duong di cua con chuot trong me cung
//D: xuong duoi; R dich phai
#include <bits/stdc++.h>   
#define MAX 10 
using namespace std;  
int dem =0;
string R="";
//kiem tra toa do (x,y) co di duoc trong me cung
bool isSafe(int maze[MAX][MAX], int x, int y, int N) {     
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1) 
        return true;   
    return false; // neu (x,y) khong di duoc trong me cung
} 
// ham de dui de qua ra tat ca cac nghiem cua bai toan
void Solution(int maze[MAX][MAX], int x, int y, int sol[MAX][MAX], int N) { 
    // neu da den dich
    if (x == N - 1 && y == N - 1) { 
        sol[x][y] = 1;         
        cout<<R<<endl; //R ="";
    }   
    // neu x, y thuoc me cung & di chuyen duoc
    if (isSafe(maze, x, y, N) == true) { 
        // danh dau da den duoc o x, y 
        sol[x][y] = 1; 
        //thu dich xuong D: down
        if(isSafe(maze, x+1, y, N)) {
        	R = R +'D';Solution(maze, x + 1, y, sol, N);
        	
		}
		//thu sang R: right
		if(isSafe(maze, x, y+1, N)) {
        	R = R +'R';Solution(maze, x , y+1, sol, N);        	
		}
        //neu khong co phep nao dich duoc
        sol[x][y] = 0; //tra lai gia tri quay lui
		if(R.length()!=0) //loai phep dich cuoi cung
			R.erase(R.length()-1) ;                
    }       
}   
//  dua ra cac duong di cua con chuot
void solveMaze(int maze[MAX][MAX], int N) { 
	int sol[MAX][MAX];	
	for(int i=0; i<N; i++)
		for(int j=0; j<N; j++)
			sol[i][j]=0;
    Solution(maze, 0, 0, sol, N);          
}   
// Test Solution 
int main() { 
    int maze[MAX][MAX], N ; 
    cout<<"Nhap N="; cin>>N; 
    for(int i=0; i<N; i++)
    	for(int j=0; j<N; j++) 
    		cin>>maze[i][j];
    solveMaze(maze, N);     
    return 0; 
} 

