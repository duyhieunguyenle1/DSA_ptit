#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solution(){
    int n; cin>>n;
    queue<string>q;
    q.push("9");
    while(true){
        string s = q.front();
        q.pop();

        int x = 0;
        for (char i : s) {
            x = x * 10 + (i - '0');
            x %= n;
        }
        if (x == 0) {
            cout << s << endl;
            return;
        }
        q.push(s + '0');
        q.push(s + '9');
    }
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        Solution();
    }
    return 0;
}