#include <bits/stdc++.h> 
using namespace std;   
int countWords(string str) {     
	getline(cin,str);
    stringstream s(str); // Used for breaking words 
    for(string str; s >> str; )//duyet tren tap cac tu
    	cout<<str<<endl;
} 
  
// Driver code 
int main() { 
    string str;
	countWords(str);
} 
