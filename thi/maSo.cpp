#include<bits/stdc++.h>
using namespace std;
char t[7]={};
bool dd[7]={};
int x[7]={},n;
vector<string>v1,v2;

void printStr(){
    string s="";
    for(int i=1;i<=n;i++){
        char tmp = (char)x[i]+'A'-1;
        s+=tmp;
    }
    v1.push_back(s);
}

void printInt(){
    string s="";
    for(int i=1;i<=n;i++)
        s+=to_string(x[i]);
    v2.push_back(s);
}

void Tryint(int i){
    for(int j=1;j<=n;j++){
        x[i]=j;
        if(i<n)
            Tryint(i+1);
        else 
            printInt();
    }
}

void TryStr(int i){
    for(int j=1;j<=n;j++){
        if(!dd[j]){
            dd[j]=1;
            x[i]=j;
            if(i<n)
                TryStr(i+1);
            else 
                printStr();
            dd[j]=0;
        }
    }
}
int main(){
    cin>>n;
    Tryint(1);
    TryStr(1);
    for(string i:v1)
        for(string k:v2)
            cout<<i+k<<endl;
}