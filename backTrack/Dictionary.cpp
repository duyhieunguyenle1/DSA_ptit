// Tim cac tu trong tu dien co the tao ra boi ma tran ki tu
#include <bits/stdc++.h> 
using namespace std;   
#define M 3 
#define N 3 
  
// Gia su day la mot tu dien 
string dictionary[] = { "GEEKS", "FOR", "QUIZ", "GO" }; 
int n = sizeof(dictionary) / sizeof(dictionary[0]); 
//kiem tra mot tu co thuoc tu dien hay khong
bool Search(string& str) { 
    // thuat toan im kiem tuyen tinh 
    for (int i = 0; i < n; i++) 
        if (str.compare(dictionary[i]) == 0) 
            return true; 
    return false; 
}   
// thuat toan DFS dua ra tat ca cac tu
void SearchWords(char B[M][N], bool V[M][N], int i, 
                   int j, string& str) { 
    V[i][j] = true; //danh dau o i, j da tham
    str = str + B[i][j]; //lay str noi them voi ky tu       
    if (Search(str)) //neu la mot tu trong tu dien
        cout << str << endl; //in ra tu nay  
    // duyet theo 8 dinh ke voi o [i][j] 
    for (int row = i - 1; row <= i + 1 && row < M; row++) 
        for (int col = j - 1; col <= j + 1 && col < N; col++) 
            if (row >= 0 && col >= 0 && !V[row][col]) 
                SearchWords(B, V, row, col, str); 
  
    // Erase current character from string and mark V 
    // of current cell as false 
    str.erase(str.length() - 1); 
    V[i][j] = false; 
} 
  
// liet ke cac tu trong tu dien co the tao ra boi ma tran ky tu
void findWords(char B[M][N]) { 
    // danh dau tat ca cac ky tu chua tham la false
    bool V[M][N] = { { false } };   
    // thiet lap tu hien tai la trong
    string str = "";   
    // tim tat ca cac tu bat dau tu moi ky tu     
    for (int i = 0; i < M; i++) {
	    for (int j = 0; j < N; j++) {		
            SearchWords(B, V, i, j, str); 
    	}
	}
} 
  
// Test solution
int main() { 
    char B[M][N] = { { 'G', 'I', 'Z' }, 
                          { 'U', 'E', 'K' }, 
                          { 'Q', 'S', 'E' } }; 
  
    cout << "Tap cac tu:\n"; 
    findWords(B); 
    return 0; 
} 
