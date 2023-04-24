#include <bits/stdc++.h>
#define MAX 10
using namespace std;
string Test(string str){
	int F[MAX]={0};
	int chuaxet[MAX]={true}, k=-1;
	//tim F[] la so lan xuat hien cac so
	for(int i=0; i<str.length();i++){
		F[str[i]-'0']++;
	}
	int Le =0, Max_le=0, chuso=0;
	//tim k=i là so lon nhat xuat hien le nhieu nhat
	for(int i=0; i<MAX; i++){ 
		if(F[i]) chuso++;//so cac so
		if(F[i]%2){ Max_le++;//so cac so xuat hien le
			if(Le<=F[i]) {//k=i la so le xuat hien nhieu la nnhat
				Le = F[i];k=i;	
			}
		}
	}
	//Truong hop tat ca cac chu so xuat hien deu le
	//lay so le khac 0 xuat hien nhieu lan nhat
	if(Max_le==chuso){
		string Result;int p=0, q=0;
		for(int i=1; i<MAX; i++){
			if(p<=F[i]) {//tim q=i khac 0 xuat hien le nhieu nhat
				p=F[i]; q=i;
			}
		}
		Result.append(F[q],'0'+q);
		return Result;
	}
	//truong hop co ca chan ca le	
	string Result;
	//Noi cac so tu 9..0 voi F[i]/2 lan
	for(int i=9; i>=0; i--){
		if(F[i] && F[i]%2==0) {
			Result.append(F[i]/2, '0'+i);			
		}
		else if (i==k && F[k]>1){
			Result.append(F[i]/2, '0'+i);
		}
	} 			
	string tmp = Result;
	if(F[k]>=1) {//neu ton tai k la so xuat hien le nhieu nhat
		Result.append(1,'0'+k);//so k duoc noi them o giua
	}				
	//noi  voi dao nguoc cua tmp
	for(int i=tmp.length()-1; i>=0; i--){
		Result.append(1,tmp[i]);
	}	
	return (Result);
}
int main(void){
	string str; int T, n;
	cin>>T;
	while(T--){
		cin>>str;
		cout<<Test(str)<<endl;
	}	
} 
//chu y test nay
//1
//100000000022233333456789
//33333
