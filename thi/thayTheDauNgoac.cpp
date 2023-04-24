#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t=1;
    cin>>t;
    while(t--){
        string s; cin>>s;
        stack<int>st;
        int a[1005];
        for(int i=0;i<s.size();i++)a[i]=1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')st.push(i);
            else if(s[i]==')'){
                if(!st.empty()&&s[st.top()]=='('){
                    s[i]='1';
                    s[st.top()]='0';
                    st.pop();
                }else{
                    st.push(i);
                }
            }
        }
        while(!st.empty()){
            int tmp = st.top();
            a[tmp]=0;
            st.pop();
        }
        for(int i=0;i<s.size();i++){
            if(!a[i])cout<<"-1";
            else cout<<s[i];
        }
        cout<<endl;
    }
    return 0;
}