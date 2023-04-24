// Dua ra tat ca cac xau cua xau cho truoc bang cach thep space
#include <bits/stdc++.h> 
using namespace std;   
//ham de qui dua ra cac xau   
void Try(char str[], char buff[], int i, int j, int n) { 
    if (i==n) { 
        buff[j] = '\0'; 
        cout << buff << endl; 
        return; 
    }       
    buff[j] = str[i]; //lay buff[j]==buff[i]
    Try(str, buff, i+1, j+1, n); //de qui den ki tu tiep theo      
    buff[j] = ' '; //dat vao ki tu space
    buff[j+1] = str[i];   
    Try(str, buff, i+1, j+2, n); 
} 
void Solution(char *str) { 
    int n = strlen(str);       
    char buf[2*n];   
    buf[0] = str[0];   
    Try(str, buf, 1, 1, n); 
}   
void Solution1(string str) { 
    int n = str.length(); 
    unsigned int opsize = pow(2, n - 1);   
    for (int counter = 0; counter < opsize; counter++) { 
        for (int j = 0; j < n; j++) {   
            cout << str[j]; 
            if (counter & (1 << j)) 
                cout << " "; 
        } 
        cout << endl; 
    } 
} 
void Solution2(string str) { 
    int n = str.length(); 
    unsigned int opsize = pow(2, n - 1);   
    for (int counter = opsize-1; counter >=0 ; counter--) { 
        for (int j = 0; j < n; j++) {   
            cout << str[j]; 
            if (counter & (1 << j)) 
                cout << " ";             
        } 
        cout << endl; 
    } 
} 
// Test solution 
int main() { 
    char str[] = "ABC"; 
    Solution2(str); 
    return 0; 
} 
