#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    int t=1;
    cin>>t;
    while(t--){
        ll n; cin>>n;
        ll res=0;
        queue<string>q;
        q.push("1");
        while(true){
            string s = q.front();
            q.pop();
            if(stoll(s)<=n)res++;
            else break;

            q.push(s+"0");
            q.push(s+"1");
        }
        cout<<res<<endl;
    }
    return 0;
}