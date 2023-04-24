#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
    cách chuyển từ mã gray sang mã nhị phân: bit đầu tiên 
    luôn giữ nguyên, kê từ bit thứ i, nếu bit thứ i của mã 
    gray là 1 thì bit thứ i của mã nhị phân sẽ ngược 
    với bit (i-1) của mã nhị phân ,nếu bit thứ i của mã 
    gray là 0 thì bit thứ i của mã nhị phân sẽ trùng với 
    bit (i-1) của mã nhị phân
*/

char flip(char a){
    return (a=='0')?'1':'0';
}

void grayToBinary(string s){
    string res = "";
    res+=s[0];

    for(int i=1;i<s.length();i++){
        if(s[i]=='0'){
            res+=res[i-1];
        }else{
            res+=flip(res[i-1]);
        }
    }
    cout<<res<<endl;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        string s; cin>>s;
        grayToBinary(s);
    }
    return 0;
}