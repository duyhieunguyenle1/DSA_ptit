// Chuyen ma Gray thanh Binary
// Chuyen Binary thay Gray
#include <bits/stdc++.h>
using namespace std; 
// Lay phep tuyen loai cua hai ky tu
char xor_c(char a, char b) { 
	if(a==b) return '0';
	return '1';	
}
 
// Chuyen c tu 0 thanh 1
char flip(char c) { 
	if(c=='0') return '1';
	return '0';
}
// Chuyen xau nhi phan thanh ma Gray
string binarytoGray(string binary) {
    string gray = ""; //xuat phat tu xau rong
    //B1: xac dinh bit dau tien
    gray += binary[0];//bit ngoai cung bao gio cung giong nhau 
    //B2: tinh toan cac bit con lai	
    for (int i = 1; i < binary.length(); i++) {//duyet tu bit tiep theo
		//giua bit truoc va bit hien tai
        char c = xor_c(binary[i - 1], binary[i]);
        //noi bit tuyen loai vao ma Gray
        gray += xor_c(binary[i - 1], binary[i]);
    } 
    return gray;
}
 
// Chuyen xau Gray thanh Binary
string graytoBinary(string gray){    
	string binary = ""; //xuat phat tu xau rong
    //B1: Tao bit dau tien
    binary += gray[0]; 
    //B2: tinh toan cac bit con lai
    for (int i = 1; i < gray.length(); i++) {
        // neu bit hien tai la 0If current bit is 0, concatenate
        // previous bit
        if (gray[i] == '0') //// neu bit hien tai la 0
            binary += binary[i - 1];//noi voi bit truoc do 
        else //neu bit hien tai la 1
        	//chuyen thanh 1 va noi voi bit truoc do
            binary += flip(binary[i - 1]);
    }
 
    return binary;
} 
// Test solution
int main() { 
	int T; string binary, gray;
	cin>>T;
	while(T--) {
		cin>>binary;
		cout<<binarytoGray(binary)<<endl;
	}
}
