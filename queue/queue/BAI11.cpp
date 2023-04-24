// tim ky tu khong lap dau tien
#include <bits/stdc++.h> 
using namespace std; 
const int MAX_CHAR = 26; 
void Solution(char str[]) { 
    queue<char> q; //tao hang doi voi tuy bien char
    int F[MAX_CHAR] = { 0 }; //so lan xuat hien moi ky tu      
    for (int i = 0; str[i]; i++) { //duyet tu trai qua phai str[i]          
        q.push(str[i]); //dua ky tu vao queue          
        F[str[i] - 'a']++; //tang so lan xuat hien  
        // kiem tra tinh khong lap
        while (!q.empty()) { //lap den khi hang doi rong
            if (F[q.front() - 'a'] > 1) //neu ky tu xuat hien nhieu hon 1
                q.pop(); //loai khoi hang doi
            else { //nguoc lai
                cout << q.front() << " "; //dua ra front
                break; 
            } 
        }   
        if (q.empty()) //neu hang doi rong
            cout << -1 << " "; //dua ra -1
    } 
    cout << endl; 
} 
int main() { 
	int T, n;char str[1000];cin>>T;
	while(T--){
		cin>>n; 
		for(int i=0; i<n; i++) cin>>str[i];
		str[n]='\0';
		Solution(str);
	}
} 
