// Bai toan Sudoku 
#include <bits/stdc++.h> 
using namespace std; 
//#define UNASSIGNED 0  //dung de xac nhan o rong
#define N 9  //Kich co luoi N luon la 9  
// hma tim o trong chua co gia tri
bool Find(int grid[N][N],int &row, int &col) {  
    for (row = 0; row < N; row++)  
        for (col = 0; col < N; col++)  
            if (grid[row][col] == 0)  
                return true;  
    return false;  
}  
// tra lai dung neu co so num theo hang
bool TestRow(int grid[N][N], int row, int num)  {  
    for (int col = 0; col < N; col++)  
        if (grid[row][col] == num)  
            return true;  
    return false;  
}  
//tra lai gia tri dung neu co gia tri num theo cot
bool TestCol(int grid[N][N], int col, int num) {  
    for (int row = 0; row < N; row++)  
        if (grid[row][col] == num)  
            return true;  
    return false;  
}  
//tra lai gia tri dung neu co gia tri num theo ma tran 3x3
bool TestIn(int grid[N][N], int boxStartRow, int boxStartCol, int num) {  
    for (int row = 0; row < 3; row++)  
        for (int col = 0; col < 3; col++)  
            if (grid[row + boxStartRow] 
                    [col + boxStartCol] == num)  
                return true;  
    return false;  
}    
// kiem tra o co ghi duoc so hanh khong 
bool isSafe(int grid[N][N], int row,int col, int num) {  
    //kiem tra num chua ton tai theo hang, cot & 3x3 box    
    return !TestRow(grid, row, num) &&  
           !TestCol(grid, col, num) &&  
           !TestIn(grid, row - row % 3 ,  
                      col - col % 3, num) &&  
            grid[row][col] == 0;  
}  
// Dua ra ket qua
void printGrid(int grid[N][N]) {  
    for (int row = 0; row < N; row++) {  
    	for (int col = 0; col < N; col++)  
            cout << grid[row][col] << " ";  
        cout << endl; 
    }  
}    
//Giai bai toan Sudocu
bool Sudoku(int grid[N][N])  {  
    int row, col;    
    // neu da dien day du
    if (!Find(grid, row, col))  
    	return true; // da giai xong bai toan  
    // duyet cac so tu 1..9 
    for (int num = 1; num <= 9; num++) {  
        // if looks promising  
        if (isSafe(grid, row, col, num)) { //neu o row, col dien duoc            
            grid[row][col] = num;  //lay gia tri la num              
            if (Sudoku(grid))  //dien o tiep theo
                return true;    
            // neu hong tra lai gia tri quay lui 
            grid[row][col] = 0;  
        }  
    }  
    return false; // neu khong co giai phap 
}  
// Test solution
int main()  {  
    // gia tri 0 can duoc dien cac so tu 1..9 
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},  
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},  
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},  
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},  
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},  
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},  
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},  
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},  
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};  
    if (Sudoku(grid) == true)  
        printGrid(grid);  
    else
        cout << "Khong co giai phap";  
  
    return 0;  
}
