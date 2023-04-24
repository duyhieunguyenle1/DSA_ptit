// tim so BDN nho nhat lon hon N
#include <bits/stdc++.h> 
using namespace std;   
bool isBinaryNum(int N) { //kiem tra so BDN
    while (N > 0) { 
        int digit = N % 10; 
        if (digit != 0 && digit != 1) 
            return false; 
        N /= 10; 
    } 
    return true; 
}   
int mod(string t, int N) { //lay mod t & N
    int r = 0; 
    for (int i = 0; i < t.length(); i++)  { 
        r = r * 10 + (t[i] - '0'); 
        r %= N; 
    } 
    return r; 
} 

string MinBDN(int N) { 
    queue<string> q; 
    set<int> visit;   
    string t = "1";       
    q.push(t);//dua t vao queue       
    while (!q.empty()) { //lap den khi queue rong        
        t = q.front(); q.pop();//lay va loai phantu front           
        int du = mod(t, N);//lay t mod N   
        if (du == 0) //neu du la 0
            return t; 
        else if(visit.find(du) == visit.end()) { 
            visit.insert(du); 
            q.push(t + "0"); 
            q.push(t + "1"); 
        } 
    } 
} 
  
//  Driver code to test above methods 
int main() { 
    int N = 1000013; 
    cout << MinBDN(N); 
    return 0; 
} 
