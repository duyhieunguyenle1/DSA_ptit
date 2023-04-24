//sinh ra to hop chap k cua n
#include <bits/stdc++.h>
#define MAX 12
using namespace std;
int X[MAX], n, k, OK;
//Thiet lap to hop ban dau
void Init(void) {
	cin>>n>>k; //dua vao n, k cua moi test
	OK = true;//thiet lap OK la true
	//sinh ra to hop dau tien: 1, 2, .., k
	for(int i=1;i<=k; i++) 
		X[i] =i;
}
//Dua ra to hop hien tai
void Result(void) {
	for(int i=1; i<=k; i++) cout<<X[i];
	cout<<" ";
}
//Sinh ra to hop ke tiep
void Next_Combination(void){
	int i=k; //duyet tu ben phai tap con hien tai
	while(i>0 && X[i]==n-k+i) { //tim i sao cho X[i] khac n-k+i
		i--; 
	}
	if(i>0) { //neu tim thay i>0 va X[i] khac n-k+i
		X[i]=X[i] + 1; //tang X[i] len 1
		for(int j=i+1; j<=k; j++) //tu vi tri i+1,..,k
			X[j] = X[i] + j - i;
	}
	else //neu khong tim thay i: i=0
		OK = false;//da den nghiem cuoi cung
}
void Combination(void ) {
	Init();//thiet lap nghiem ban dau
	while(OK) { //lap khi nghiem chua phai cuoi cung
		Result();//dua ra nghiem hien tai
		Next_Combination(); //sinh ra nghiem ke tiep
	}
	cout<<endl;//ket thuc mot test
}
int main(void) {
	int T; cin>>T;//dua vao so test
	while(T--) { //lap den test cuoi cung
		Combination();//liet ke cac to hop cua test
	}
}
