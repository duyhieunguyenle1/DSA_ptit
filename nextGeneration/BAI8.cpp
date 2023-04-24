//Duyet cac xau nhi phan do dai n co k bit 1
#include <bits/stdc++.h>
#define MAX 17
using namespace std;
int X[MAX], n,k, OK; 
//thiet lap xau nhi phan ban dau
void Init(void) {
	cin>>n>>k; //nhap do dai test hien tai
	OK = true;//lay OK =true
	//thiet lap xau gom n so 0
	for(int i=0; i<n; i++) X[i] =0;
}
//dua ra xau nhi phan hien tai
void Result(void) {
	for(int i=0; i<n; i++) cout<<X[i];
	cout<<endl;
} 
int Test(void){
	int S =0;
	for(int i=0; i<n; i++) S += X[i];
	return(S==k);
}
//sinh xau nhi phan tiep theo
void Next_Bits_String(void) {
	int i = n-1;//duyet tu phai qua trai
	while(i>=0 && X[i]) { //lap neu X[i]==1
		X[i]=0; i--; //dat X[i]=0
	}
	if(i>=0) X[i] =1;//phan tu bang 0 dau tien thiet lap la 1
	else OK = false; //ghi nhan da den cuoi cung
}
//Duyet Xau nhi phan
void Binary_String(void) {
	Init();//thiet lap xau dau tien
	while(OK) { //lap khi chua phai xau cuoi cung
		if(Test() ) Result(); //dua ra xau hien tai
		Next_Bits_String();//sinh ra xau ke tiep
	}
	//cout<<endl;//ket thuc mot test
}
//Test Solution
int main(void) {
	int T; cin>>T;//nhap so luong test T
	while(T--){ //lap den test cuoi cung
		Binary_String();//dua ra ket qua test hien tai
	}
}
