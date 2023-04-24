// tim cac so stepping trong khoang [n,m]
#include<bits/stdc++.h> 
using namespace std; 
void bfs(int n, int m, int num) {     
    queue<int> q;   
    q.push(num);   
    while (!q.empty()) {         
        int stepNum = q.front(); q.pop();//lay & loai phan tu front
        if (stepNum <= m && stepNum >= n) //neu nam trong mien
            cout << stepNum << " "; //in ra so stepping
        if (num == 0 || stepNum > m)//neu dieu nay xay ra
            continue; //tiep tuc lap  
        int lastDigit = stepNum % 10; //lay so cuoi
        int stepNumA = stepNum * 10 + (lastDigit- 1); 
        int stepNumB = stepNum * 10 + (lastDigit + 1); 
        if (lastDigit == 0) //neu la so 0
            q.push(stepNumB); //dua vao so B  
        else if (lastDigit == 9) //nu la so 9
            q.push(stepNumA); //dua vao so A  
        else  { //neu khong phai 0 hoac 9
            q.push(stepNumA); 
            q.push(stepNumB); 
        } 
    } 
} 
void Result(int n, int m) { 
    for (int i = 0 ; i <= 9 ; i++) 
        bfs(n, m, i); 
}   
int main() { 
    int n = 0, m = 21; 
    Result(n,m); 
} 

