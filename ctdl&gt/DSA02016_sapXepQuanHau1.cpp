#include<bits/stdc++.h>
using namespace std;
int n,res=0;
int cot[15],xuoi[30],nguoc[30];

void init(){
    for(int i=1;i<=n;i++)cot[i]=true;
    for(int i=1; i<=30; i++) {
		xuoi[i]=true;nguoc[i]=true;	
	}
    res=0;
}

void solution(int i){
    for(int j=1;j<=n;j++){
        if(cot[j]&&xuoi[i-j+n]&&nguoc[i+j-1]){
            cot[j]=false;
            xuoi[i-j+n]=false;
            nguoc[i+j-1]=false;
            if(i==n)res++;
            else solution(i+1);
            //Nho hoan tra gia tri quay lui de thu tiep
			cot[j]=true;xuoi[i-j+n]=true;nguoc[i+j-1]=true;
        }
    }
}
int main(){
    int t; cin>>t;
    while(t--){
        cin>>n;
        init();
        solution(1);
        cout<<res<<endl;
    }
}