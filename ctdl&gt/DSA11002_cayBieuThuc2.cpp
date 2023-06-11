#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int calc(int x, int y,char s){
    if(s=='+')return x+y;
    if(s=='-')return x-y;
    if(s=='*')return x*y;
    if(s=='/')return x/y;
    return 1;
}

void Solution() {
    int n; cin >> n; cin.ignore();
    string s; getline(cin, s);
    queue<int> q;
    for (int i = s.length() - 1; i >= 0; --i) {
        if (s[i] == ' ') continue;
        if (isdigit(s[i])) {
            string tmp = "";
            while (isdigit(s[i])) {
                tmp = s[i--] + tmp;
            }
            i++;
            q.push(stoi(tmp));
        } else {
            int y = q.front(); q.pop();
            int x = q.front(); q.pop();
            q.push(calc(x, y, s[i]));
        }
    }
    cout << q.front()<<endl;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        Solution();
    }
    return 0;
}