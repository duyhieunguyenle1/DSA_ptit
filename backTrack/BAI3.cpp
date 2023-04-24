// Duong di cua con chuot trong me cung
// D: xuong duoi; R dich phai
#include <bits/stdc++.h>   
#define MAX 10 
using namespace std;  
int N; //bieu dien kich co me cung
int maze[MAX][MAX];//bieu dien me cung
bool sol[MAX][MAX];//bieu dien trang thai cac o da di qua
string P="";//bieu dien  1 duong di
int dem =0; //so luong duong di
void Init(void) {
	cin>>N; //nhap kich co me cung
	for(int i=0; i<N; i++){
		for(int j=0; j<N; j++){
			cin>>maze[i][j];//nhap gia tri o me cung
			sol[i][j]=false;//thiet lap gia tri giai phap ban dau
		}
	}
}
// in mot loi giai bang ma tran
void Result(void) { 
    for (int i = 0; i < N; i++) { 
        for (int j = 0; j < N; j++) 
            cout<<sol[i][j]<<" ";
        cout<<endl;  
    }     
}   
//kiem tra toa do (x,y) co di chuyen duoc trong me cung
bool isSafe( int x, int y) {     
    if (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1) 
        return true;// neu (x,y) di chuyen duoc trong me cung    
    return false; // neu (x,y) khong di chuyen duoc trong me cung
} 
// ham de qui de qua ra mot nghiem cua bai toan
void Solution( int x, int y) { 
    // neu da di chuyen den dich
    if (x == N - 1 && y == N - 1) { 
        //Result(sol, N); dem++; //ghi nhan duong di
		sol[x][y] = true; cout<<P<<" "; dem++;
    }   
    // neu x, y di chuyen duoc trong me cung
    if (isSafe( x, y) == true) { 
        sol[x][y] = true; // xac nhan da den duoc (x, y)                  
        if(isSafe(x+1, y)) {//neu xuong duoi duoc:D 
        	//tiep tuc xuong duoi ô (x+1, y)
			P = P +'D';Solution( x + 1, y);        	
		}
		if(isSafe( x, y+1)) {//neu sang phai duoc:R
        	//tiep tuc xuong duoi ô (x, y+1)
			P = P +'R';Solution( x , y+1);        	
		}
        //neu khong co phep nao dich duoc
        sol[x][y] = false; //tra lai gia tri quay lui
		if(P.length()!=0) //loai phep dich cuoi cung
			P.erase(P.length()-1) ;                
    }       
}   
// Test Solution 
int main() {     
	int T; cin>>T;
	while(T--){
		Init(); Solution( 0, 0);cout<<endl;
	}
} 

