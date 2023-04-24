#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t=1;
    cin>>t;
    while(t--){
        queue<string>q;
        int n; cin>>n;
        q.push("1");
        while(n--){
            string s = q.front();
            q.pop();
            cout<<s<<" ";

            q.push(s+"0");
            q.push(s+"1");
        }
        cout<<endl;
    }
    return 0;
}