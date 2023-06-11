#include<bits/stdc++.h>
using namespace std;

bool cot[15],xuoi[30],nguoc[30];
int a[20][20],ans;

void solution(int i,int sum){
    for(int j=1;j<=8;j++){
        if(!cot[j]&&!xuoi[i-j+8]&&!nguoc[i+j-1]){
            cot[j]=true;
            xuoi[i-j+8]=true;
            nguoc[i+j-1]=true;
            sum+=a[i][j];
            if(i==8)ans=max(ans,sum);
            else solution(i+1,sum);
            //Nho hoan tra gia tri quay lui de thu tiep
            sum-=a[i][j];
			cot[j]=false;xuoi[i-j+8]=false;nguoc[i+j-1]=false;
        }
    }
}
int main(){
    int t; cin>>t;
    while(t--){
        ans=0;
        for(int i=1;i<=8;i++){
            for(int j=1;j<=8;j++)cin>>a[i][j];
        }
        solution(1,0);
        cout<<ans<<endl;
    }
}