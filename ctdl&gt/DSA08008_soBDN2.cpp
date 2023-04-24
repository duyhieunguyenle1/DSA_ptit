#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    int t=1;
    cin>>t;
    while(t--){
        ll n; cin>>n;
        queue<string>q;
        q.push("1");
        while(true){
            string s = q.front();
            q.pop();
            if(stoll(s)%n==0){
                cout<<s<<endl;
                break;
            }

            q.push(s+"0");
            q.push(s+"1");
        }
    }
    return 0;
}