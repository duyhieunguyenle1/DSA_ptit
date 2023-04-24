// Tim cac tu trong tu dien co the tao ra boi ma tran ki tu
#include <bits/stdc++.h> 
#define MAX 10
using namespace std;   
// Gia su day la mot tu dien 
string D[MAX]; //goi mang D[] la tap cac tu trong tu dien
char B[MAX][MAX];//goi B[][] la ma tran cac ky tu
int x; //goi x la so tu trong tu dien
int n; //goi n la so hang cua ma tran ky tu
int m; //goi m la so cot cua ma tran ky tu
bool V[MAX][MAX]; //goi mang V[][] la mang danh dau cac ky tu chua xet
int dem;
void Init(void){
	cin>>x; //nhap so luong tu trong tu dien
	for(int i=0; i<x; i++) cin>>D[i];
	cin>>n>>m; //nhap hang, cot ma tran ky tu
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>B[i][j];//nhap ky tu B[i][j]
			V[i][j]=false;//thiet lap V[i][j]=false
		}
	}
}
//Ham kiem tra mot tu co thuoc tu dien hay khong
bool Search(string &str) { 
    // thuat toan im kiem tuyen tinh 
    for (int i = 0; i < x; i++) 
        if (str.compare(D[i]) == 0) 
            return true; 
    return false; 
}   
// thuat toan DFS dua ra tat ca cac tu bat dau tu ky tu B[i][j]
void DFS( int i, int j, string & str, vector<string> R) { 
    V[i][j] = true; //danh dau ky tu B[i][j] da tham
    str = str + B[i][j]; //lay str noi them voi ky tu B[i][j]      
    if (Search(str)) { //neu str la mot tu trong tu dien
        R.push_back(str); dem++;
		cout << str << " "; //in ra tu nay  
	}
    // duyet theo 8 dinh ke voi o [i][j] 
    for (int row = i - 1; row <= i + 1 && row < n; row++) {	//duyet theo hang
        for (int col = j - 1; col <= j + 1 && col < m; col++) {//duyet theo cot		
            if (row >= 0 && col >= 0 && !V[row][col]) {            	
            	DFS(row, col, str, R);//goi den DFS(row, col)
			}
		}
	}           
    str.erase(str.length() - 1); //nho hoan lai gia tri de quay lui
    V[i][j] = false; //hoan lai gia tri quay lui
}   
void Result(vector <string> R){
	if(dem==0) cout<<-1<<endl;
	else {
		sort(R.begin(), R.end());
		for(int i=0; i<R.size(); i++) 
			cout<<R[i]<<" ";
		cout<<endl; 
	}
}
// liet ke cac tu trong tu dien co the tao ra boi ma tran ky tu
void findWords(void) { 
    dem =0;//so tu dem duoc luc dau la 0
    vector <string> R; //vector luu ket qua
    string str = "";// thiet lap tu hien tai la trong   
    // goi den n*m lan thu tuc DFS(i, j) 
    for (int i = 0; i < n; i++) {
	    for (int j = 0; j < m; j++) {		
            DFS(i, j, str, R); 
    	}
	}
	Result(R); 
}   
// Test solution
int main() { 
	int T; cin>>T; 
	while(T--){
		Init(); findWords();
	}
} 
