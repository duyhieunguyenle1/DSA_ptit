#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t=1;
    cin>>t;
    queue<int>q;
    while(t--){
        string s; cin>>s;
        if(s=="PUSH"){
            int n; cin>>n;
            q.push(n);
        }
        if(s=="POP"){
            if(!q.empty())q.pop();
        }
        if(s=="PRINTFRONT"){
            if(!q.empty())cout<<q.front()<<endl;
            else cout<<"NONE\n";
        }
    }
    return 0;
}