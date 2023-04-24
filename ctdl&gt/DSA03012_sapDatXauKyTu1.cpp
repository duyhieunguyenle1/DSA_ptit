#include<bits/stdc++.h>
using namespace std;

// ct: 2*d<=s.size()-1 d:so luong ky tu lon nhat trong s
int main(){
    int t; cin>>t;
    while(t--){
        string s; cin>>s;
        map<char,int>mp;
        int MAX=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            MAX=max(mp[s[i]],MAX);
        }
        if(MAX<=s.size()-MAX+1)cout<<"1\n";
        else cout<<"-1\n";
    }
}