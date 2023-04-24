//sinh ra to hop chap k cua n
#include <bits/stdc++.h>
#define MAX 12
using namespace std;
int X[MAX], n, k, OK;
//Thiet lap nghiem ban dau
void Init(void) {
	cin>>n>>k; OK = true;
	for(int i=1;i<=k; i++) 
		X[i] =i;
}
//Dua ra nghiem hien tai
void Result(void) {
	for(int i=1; i<=k; i++) cout<<X[i];
	cout<<" ";
}
//Sinh ra nghiem ke tiep
void Next_Combination(void){
	int i=k; //duyet tu ben phai tap con hien tai
	while(i>0 && X[i]==n-k+i) { //tim i sao cho X[i] khac n-k+i
		i--; 
	}
	if(i>0) { //neu tim thay i
		X[i]=X[i] + 1; //tang X[i] len 1
		for(int j=i+1; j<=k; j++) //tu vi tri i+1,..,k
			X[j] = X[i] + j - i;
	}
	else //neu khong tim thay i
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
	int T; cin>>T;
	while(T--) {
		Combination();
	}
}
