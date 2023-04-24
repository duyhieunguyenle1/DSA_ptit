#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solution(string s){
    stack<int>st; // lưu vị trí các dấu (
    st.push(-1); // để stack không rỗng
    int res=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='(')st.push(i);
        else {
            st.pop();
            if(!st.empty())res=max(res,i-st.top());
            else st.push(i);
        }
    }
    cout<<res<<endl;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        string s; cin>>s;
        Solution(s);
    }
    return 0;
}