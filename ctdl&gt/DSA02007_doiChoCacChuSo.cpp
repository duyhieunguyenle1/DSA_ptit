#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solution(){
    int k; string s;
    cin>>k>>s;
    for(int i=0;i<s.size();i++){
        if(k==0)break;
        char c='0';
        for(int j=i+1;j<s.size();j++){
            c=max(c,s[j]);
        }
        if(c<=s[i])continue;
        string news=s;
        for(int j=i+1;j<s.size();j++){
            if(s[j]==c){
                string temp=s;
                swap(temp[i],temp[j]);
                news=max(news,temp);
            }
        }
        s=news;
        k--;
    }
    cout<<s<<endl;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        Solution();
    }
    return 0;
}