#include <bits/stdc++.h>
#define  MAX   100
using namespace std;
int n, k, X[MAX], OK =true;
//thiet lap phep chia ban dau
void Init(void ){
	OK = true; k=1;
	cin>>n; //nhan n cua moi test    
	X[k] = n;//phep chia dau tien la n = n+0
}
//dua ra phep chia hien tai
void Result(void) {
    cout<<"(";
    for (int i=1; i<=k; i++) {
    	cout<<X[i];
        if(i<k) cout<<" ";        
	}        
    cout<<") ";
}

void Next_Division(void ){
    int i = k, j, R, S, D;
    while (i > 0 && X[i]==1 ) i--;
    if (i>0 ) {
        X[i] = X[i]-1;  //lay X[i] = X[i]-1 
		D = k - i + 1; // lay vi tri tiep theo D
        R = D / X[i];  //lay phep chia cua D va X[i]  
		S = D % X[i];  // lay phan du cua D va X[i]
        k= i;
       	if (R>0) {
            for ( j = i +1; j<=i + R; j++) 
                X[j] = X[i];
            k = k + R;
        }
        if (S>0 ){ 
            k = k +1; X[k] = S; 
        }
    }
    else OK =false;
} 
void Solution() {  
	Init(); //Nhap n = 5.
    while (OK ) { 
		Result(); 
		Next_Division(); 
    }     
    cout<<endl;
}
int main(void) {
	int T; cin>>T;
	while(T--) {
		Solution();
	}
}
