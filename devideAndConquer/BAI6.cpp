// Tong hai so o he co so k
#include <bits/stdc++.h>  
using namespace std; 
//them so 0 vao dau de co hai xau co do dai nhu nhau
int Equal(string &s1, string &s2) { 
    int len1 = s1.size(); //lay do dai xâu 1
    int len2 = s2.size(); //lay do dai xau 2
    if (len1 < len2) { //lay do dai xau 2
        for (int i = 0 ; i < len2 - len1 ; i++) 
            s1 = '0' + s1; //them so 0 vao dau
        return len2; 
    } 
    else if (len1 > len2)  { //lay do dai xau 1	
        for (int i = 0 ; i < len1 - len2 ; i++) 
            s2 = '0' + s2; //them so 0 vao dau
    } 
    return len1; // If len1 >= len2 
}   
// cong hai xau o he co so k 
string addBasedK( string s1, string s2, int k ) { 
    string result;  // xau luu ket qua  
    // tao hai xau co do dai bang nhau
    int length = Equal(s1, s2); 
    int carry = 0;  // phan du luc dau la 0  
    //cong cac so tuan tu 
    for (int i = length-1 ; i >= 0 ; i--) { 
        int val1 = s1.at(i) - '0'; //lay gia tri s1[i]
        int val2 = s2.at(i) - '0';//lay gia tri s2[i] 
        int sum = (val1 + val2 + carry)%k +'0';//lay gia tri tong he co so k
        carry = (val1 + val2 + carry)/k;//lay gia tri nho
        result = (char)sum + result; //cong vao xau ket qua  
    }   
    // neu carry khac 0
    if (carry)  {
    	char x = ('0' + carry);
    	result = x + result; 
	}  
    return result; 
} 
  
// Test solution 
int main() { 
	int T; cin>>T;
	while(T--) {
		string X, Y; int k; cin>>X>>Y>>k;
		cout<<addBasedK(X,Y,k)<<endl;
	}
}
