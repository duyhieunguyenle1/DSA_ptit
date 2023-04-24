#include<bits/stdc++.h>
using namespace std;
void solve(int n,char a, char b, char c){
    if(n==1){
        cout<<a<<" -> "<<c<<endl;
        return ;
    }
    solve(n-1,a,c,b);// chuyen n-1 coc a sang b
    solve(1,a,b,c);//chuyen coc thu n tu cot a sang c
    solve(n-1,b,a,c);// chuyen n-1 coc b sang c
}
int main(){
    char a='A',b='B',c='C';
    int n; cin>>n;
    solve(n,a,b,c);
}