// Thuat toan Karatsuba nhan hai so nhi phan
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
// cong hai xau bít 
string addBitStrings( string s1, string s2 ) { 
    string result;  // xau luu ket qua  
    // tao hai xau co do dai bang nhau
    int length = Equal(s1, s2); 
    int carry = 0;  // phan du luc dau la 0  
    //cong cac bit tuan tu 
    for (int i = length-1 ; i >= 0 ; i--) { 
        int bits1 = s1.at(i) - '0'; //lay gia tri bit xau s1
        int bits2 = s2.at(i) - '0';//lay gia tri bit xau s2  
        int sum = (bits1 + bits2 + carry)%2 +'0';//lay gia tri tong
        carry = (bits1 + bits2 + carry)/2;//lay gia tri nho
        result = (char)sum + result; //cong vao xau ket qua  
    }   
    // neu carry khac 0
    if (carry)  result = '1' + result;   
    return result; 
} 
  
// ham nhan 1 bit
int multiplyiSingleBit(string a, string b) {  
	return (a[0] - '0')*(b[0] - '0');  
}  
// nhan hai xau bnit nhi phan
long int multiply(string X, string Y) { 
    // ma hai xau co do dai bang nhau
    int n = Equal(X, Y);       
    if (n == 0) //neu hai xau rong
		return 0; 
    if (n == 1) //neu xau co do dai 1
		return multiplyiSingleBit(X, Y);   
    int fh = n/2;   // lay nua dau cua xau 
    int sh = (n-fh); // lay nua thu hai cua xau  
    
    string Xl = X.substr(0, fh); //Xl la nua dau xau X
    string Xr = X.substr(fh, sh); //Xr la nua cuoi xau X  
    
    string Yl = Y.substr(0, fh); //Yl la nua dau xau Y
    string Yr = Y.substr(fh, sh); //Yr la nua cuoi xau Y 
  
    // de qui ba phep phan kich co n/2
    long int P1 = multiply(Xl, Yl); //de qui Xl, Yl
    long int P2 = multiply(Xr, Yr); //de qui Xr, Yr
    //de qui phep tinh tong
    long int P3 = multiply(addBitStrings(Xl, Xr), addBitStrings(Yl, Yr)); 
  
    // tong hop ba phep nhan de nhan ket qua cuoi cung
    return P1*(1<<(2*sh)) + (P3 - P1 - P2)*(1<<sh) + P2; 
}   
// Test solution 
int main() { 
	int T; cin>>T;
	while(T--) {
		string X, Y; cin>>X>>Y;
		cout<<multiply(X,Y)<<endl;
	}
}
