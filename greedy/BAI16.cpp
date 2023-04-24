// Sap dat lai cac ky tu sao cho cac ki tu ke nhau deu khac nhau 
#include<bits/stdc++.h> 
using namespace std;   
const int MAX_CHAR = 26;   
void rearrangeString(string str) { 
    int n = str.length();  //lay do dai xau 
    // luu so lan xuat hien moi ky tu
    int count[MAX_CHAR] = {0}; 
    for (int i = 0 ; i < n ; i++) 
        count[str[i]-'a']++; 
    priority_queue < pair< int, char> > pq; //tao mot hang doi uu tien
    for (char c = 'a' ; c <= 'z' ; c++) {	
        if (count[c-'a']) {
        	pair <int, char > x; x.first = count[c-'a'];x.second = c;
        	pq.push(x);
		}             
  	}    
    str = "" ; //goi xau tao ra luc dau la rong  
    // gia su xau dau tien '#' 
    pair <int, char> prev(-1, '#');        
    while (!pq.empty()) { //lap den khi pq rong
        pair <int, char >k;  
        k = pq.top(); //lay phan tu dau hang doi
        pq.pop(); //loai phan tu ra khoi pq
        str = str + k.second; //noi str voi ky tu  
        if (prev.first > 0) //neu prev.first>0
            pq.push(prev);   
        k.first--; 
        prev = k; 
    } 
    if (n != str.length()) 
        cout << "-1" << endl;   
    else  
        cout <<1<< endl; 
} 
  
// Driver program to test above function 
int main() { 
    string str; int T; cin>>T;
    while(T--){
    	cin>>str;
    	rearrangeString(str);	
	}
} 
