#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t=1;
    cin>>t;
    deque<int>dq;
    while(t--){
        string s; cin>>s;
        if(s=="PUSHBACK"){
            int n; cin>>n;
            dq.push_back(n);
        }
        if(s=="PUSHFRONT"){
            int n; cin>>n;
            dq.push_front(n);
        }
        if(s=="POPFRONT"){
            if(!dq.empty())dq.pop_front();
        }
        if(s=="POPBACK"){
            if(!dq.empty())dq.pop_back();
        }
        if(s=="PRINTBACK"){
            if(!dq.empty())cout<<dq.back()<<endl;
            else cout<<"NONE\n";
        }
        if(s=="PRINTFRONT"){
            if(!dq.empty())cout<<dq.front()<<endl;
            else cout<<"NONE\n";
        }
    }
    return 0;
}