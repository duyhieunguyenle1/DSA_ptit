#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// cách chuyển: xor số đầu và số ngay sau nó
// cùng 0 hoặc 1 thì là 0
// khác nhau thì là 1

void BinaToGray(string s){
    string res="";
    res+=s[0];
    for(int i=0;i<s.length()-1;i++){
        if(s[i]!=s[i+1])res+='1';
        else res+='0';
    }
    cout<<res<<endl;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        string s; cin>>s;
        BinaToGray(s);
    }
    return 0;
}