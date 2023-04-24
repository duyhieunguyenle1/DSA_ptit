#include<bits/stdc++.h>
using namespace std;
int cnt=1;
void print(vector<pair<int,int>>v){
    cout<<cnt++<<": ";
    for(int i=0;i<v.size();i++)cout<<v[i].first<<" ";
    cout<<endl;
}
int main(){
    // int t; cin>>t;
    // while(t--){
        int n; cin>>n;
        vector<pair<int,int>>v(n);
        // ktao
        for(int i=0;i<n;i++){
            // first là hoán vị kế tiếp
            v[i].first=i+1;
            // second là hoán vị ngược của hoán vị first
            // v[i].second=n-v[i].first+1;
        }
        // in hoán vị đầu tiên
        print(v);
        // sinh các hoán vị tiếp theo (next là hvi kế tiếp, prev là hvi ngược)
        while(next_permutation(v.begin(),v.end()))print(v);
        cout<<endl;
    // }
    return 0;
}