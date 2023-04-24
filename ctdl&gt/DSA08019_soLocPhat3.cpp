#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t=1;
    cin>>t;
    while(t--){
        int n; cin>>n;
        stack<string>st;
        queue<string>q;
        q.push("");
        while(!q.empty()){
            string s=q.front();
            q.pop();
            if(s!="")st.push(s);

            if(s.size()==n)continue;
            q.push(s+"6");
            q.push(s+"8");
        }
        cout<<st.size()<<endl;
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
        cout<<endl;
    }
    return 0;
}