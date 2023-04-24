#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// cho tất cả trừ ) vào stack
// gặp ) thì sẽ xét các trường hợp
// nếu có dấu trong 1 ngoặc thì thỏa mãn
// nếu ko thì ko thỏa mãn

void Check(string s){
    int len=s.size();
    stack<char>st;
    for(int i=0;i<len;i++){
        if(s[i]!=')')st.push(s[i]);
        else {
            bool ok=false;
            while(!st.empty()){
                char tmp=st.top(); st.pop();
                if(tmp=='+'||tmp=='-'||tmp=='/'||tmp=='*')ok=true;
                if(tmp=='(')break;
            }
            if(!ok){
                cout<<"Yes\n";
                return;
            }
        }
    }
    cout<<"No\n";
}

int main(){
    int t=1;
    cin>>t;
    cin.ignore();
    while(t--){
        string s; 
        getline(cin,s);
        Check(s);
    }
    return 0;
}