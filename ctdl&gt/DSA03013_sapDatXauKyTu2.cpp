#include<bits/stdc++.h>
using namespace std;

// ct: d*k-(k-1)<=s.size() d la so luong ky tu nhieu nhat, k la kcach

int main(){
    int t; cin>>t;
    while (t--){
        int d; string s;
        cin>>d>>s;
        map<char,int>mp;
        int MAX=0;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
            MAX=max(mp[s[i]],MAX);
        }
        if(MAX*d-(d-1)<=s.size())cout<<"1\n";
        else cout<<"-1\n";
    }
    return 0;
}