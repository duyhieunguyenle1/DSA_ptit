// dich chuyen it buoc nhat den canh o bien
#include <bits/stdc++.h> 
using namespace std; 
#define r 4 
#define c 5 
  
// Function to check validity 
bool check(int i, int j, int n, int m, int mat[r][c]) 
{ 
    if (i >= 0 && i < n && j >= 0 && j < m) { 
        if (mat[i][j] == 0) 
            return true; 
    } 
    return false; 
} 
  
// Function to find out minimum steps 
int findMinSteps(int mat[r][c], int n, int m) 
{ 
  
    int indx, indy; 
    indx = indy = -1; 
  
    // Find index of only 2 in matrix 
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) { 
            if (mat[i][j] == 2) { 
                indx = i, indy = j; 
                break; 
            } 
        } 
        if (indx != -1) 
            break; 
    } 
  
    // Push elements in the queue 
    queue<pair<int, pair<int, int> > > q; 
  
    // Push the position 2 with moves as 0 
    q.push(make_pair(0, make_pair(indx, indy))); 
  
    // If already at boundary edge 
    if (check(indx, indy, n, m, mat)) 
        return 0; 
  
    // Marks the visit 
    bool vis[r]; 
    memset(vis, 0, sizeof vis); 
  
    // Iterate in the queue 
    while (!q.empty()) { 
        // Get the front of the queue 
        auto it = q.front(); 
  
        // Pop the first element from the queue 
        q.pop(); 
  
        // Get the position 
        int x = it.second.first; 
        int y = it.second.second; 
  
        // Moves 
        int val = it.first; 
  
        // If a boundary edge 
        if (x == 0 || x == (n - 1) || y == 0 || y == (m - 1)) { 
            return val; 
        } 
  
        // Marks the visited array 
        vis[x][y] = 1; 
  
        // If a move is possible 
        if (check(x - 1, y, n, m, mat)) { 
  
            // If not visited previously 
            if (!vis[x - 1][y]) 
                q.push(make_pair(val + 1, make_pair(x - 1, y))); 
        } 
  
        // If a move is possible 
        if (check(x + 1, y, n, m, mat)) { 
  
            // If not visited previously 
            if (!vis[x + 1][y]) 
                q.push(make_pair(val + 1, make_pair(x + 1, y))); 
        } 
  
        // If a move is possible 
        if (check(x, y + 1, n, m, mat)) { 
  
            // If not visited previously 
            if (!vis[x][y + 1]) 
                q.push(make_pair(val + 1, make_pair(x, y + 1))); 
        } 
  
        // If a move is possible 
        if (check(x, y - 1, n, m, mat)) { 
  
            // If not visited previously 
            if (!vis[x][y - 1]) 
                q.push(make_pair(val + 1, make_pair(x, y - 1))); 
        } 
    } 
  
    return -1; 
} 
  
// Driver Code 
int main() 
{ 
    int mat[r] = { { 1, 1, 1, 0, 1 }, 
                      { 1, 0, 2, 0, 1 }, 
                      { 0, 0, 1, 0, 1 }, 
                      { 1, 0, 1, 1, 0 } }; 
  
    cout << findMinSteps(mat, r, c); 
}
