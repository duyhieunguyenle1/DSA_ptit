#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t=1;
    cin>>t;
    while(t--){
        int n; cin>>n;
        queue<string>q;
        q.push("9");
        while(true){
            string s = q.front();
            q.pop();
            if(stoi(s)%n==0){
                cout<<s<<endl;
                break;
            }

            q.push(s+"0");
            q.push(s+"9");
        }
    }
    return 0;
}