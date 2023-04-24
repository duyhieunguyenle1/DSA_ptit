#include <bits/stdc++.h>
#define MAX 12
using namespace std;
int n; //n la do dai xau
int X[MAX];//X[] la xau co do dai n<MAX
int OK =1;//OK ghi nhan xau da la cuoi cung
//Thiet lap xau nhi phan ban dau
void Init(void){
	//thiet lap x0=x1=..=xn-1 =0
	for(int i=0; i<n; i++)
		X[i]= 0;
}
//Dua ra xau nhi phan hien tai
void Result(void){
	for(int i=0; i<n; i++) 
		cout<<X[i];
	cout<<" ";
}
//Sinh xau nhi phan ke tiep
void Next_Bit_String(void){
	int i=n-1; //duyet tu vi tri ben phai nhat
	while(i>=0 && X[i]==1) {//lap khi nao X[i] =1 & chua phai cuoi xau
		X[i] =0; //thiet lap X[i]=0;
		i--; //lui lai phan tu tiep theo
	}
	if(i>=0) //neu i chua phai cuoi cung thi X[i]=0
		X[i] = 1; //thiet lap X[i]=1;
	else //neu i la cuoi cung: i <0
		OK = 0; //ket thuc sinh xau nhi phan
} 
//Test solution
int main(void) {
	int T; //so luong test T
	cin>>T; //nhap vao so luong test	
	while(T--) { //lap den test cuoi cung		
		cin>>n;//nhap do dai xau test hien tai
		OK =1; //thiet lap OK =1
		Init();//khoi tao xau ban dau
		while(OK) {//lap khi xau chua phai cuoi cung
			Result(); //dua ra xau hien tai
			Next_Bit_String(); //sinh ra xau ke tiep
		}
		cout<<endl;//ket thuc 1 test		
	}
}
