#include<bits/stdc++.h>
using namespace std;
int n,maze[15][15],dem=0;
bool sol[15][15];
string res="";

void init(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>maze[i][j];
            sol[i][j]=false;
        }
    }
}

bool isSafe(int x,int y){
    if(x>=0 && x<n && y>=0 && y<n && maze[x][y]==1)return true;
    return false;
}

void solution(int x,int y){
    if(x==n-1&&y==n-1){
        sol[x][y] = true;
        cout<<res<<" ";
        dem++;
    }
    if(isSafe(x,y)){
        sol[x][y] = true;
        if(isSafe(x+1,y)){
            res+='D';
            solution(x+1,y);
        }
        if(isSafe(x,y+1)){
            res+='R';
            solution(x,y+1);
        }
        sol[x][y] = false;
        if(res.length()!=0) 
			res.erase(res.length()-1) ;
    }
}
int main(){
    int t; cin>>t;
    while(t--){
        cin>>n;
        dem=0;
        init();
        solution(0,0);
        if(!dem)cout<<"-1";
        cout<<endl;
    }
}