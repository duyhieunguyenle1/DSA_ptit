//Duyet cac hoan vi cua 1, 2,.., n
#include <bits/stdc++.h>
#define MAX 10
using namespace std;
int X[MAX], n, OK; 
//thiet lap hoan vi ban dau
void Init(void) {
	cin>>n; OK = true;
	for(int i=1; i<=n; i++) X[i] =i;
}
//dua ra hoan vi hien tai
void Result(void) {
	for(int i=1; i<=n; i++) cout<<X[i];
	cout<<" ";
}
//sinh hoan vi tiep theo
void Next_Permutation(void) {
	int j = n-1;//duyet tu vi tri n-1
	while(j > 0 && X[j] > X[j+1]) { //tim vi tri j de X[j]<X[j+1]
		j--; 
	}
	if(j>0) { //neu tim thay j:X[j]<X[j+1]
		int k =n; //duyet tu vi ti thu n
		while(X[j]>X[k]) //tim vi tri thu k de X[j]<X[k]
			k--;
		//doi gia tri cua X[j] cho X[k]		
		int t = X[j]; X[j]=X[k]; X[k]=t; 
		//Lat nguoc doan X[j]+1,..,X[n]
		int r = j+1, s = n;
		while(r<=s) {
			t = X[r]; X[r]=X[s]; X[s]=t;			
			r++; s--;
		}
	}
	else OK = false; //ghi nhan da den cuoi cung
}
//Duyet hoan vi
void Permutation(void) {
	Init();//thiet lap hoan vi dau tien
	while(OK) { //lap khi chua phai hoan vi cuoi cung
		Result(); //dua ra hoan vi hien tai
		Next_Permutation();//sinh ra hoan vi ke tiep
	}
	cout<<endl;//ket thuc mot test
}
int main(void) {
	int T; cin>>T;
	while(T--){
		Permutation();
	}
}
