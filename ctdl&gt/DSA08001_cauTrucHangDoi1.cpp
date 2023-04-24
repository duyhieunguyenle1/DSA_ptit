#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t=1;
    cin>>t;
    while(t--){
        queue<int>q;
        int k; cin>>k;
        while(k--){
            int n; cin>>n;
            if(n==1)cout<<q.size()<<endl;
            if(n==2){
                if(q.empty())cout<<"YES\n";
                else cout<<"NO\n";
            }
            if(n==3){
                int l; cin>>l;
                q.push(l);
            }
            if(n==4){
                if(!q.empty())q.pop();
            }
            if(n==5){
                if(!q.empty())cout<<q.front()<<endl;
                else cout<<"-1\n";
            }
            if(n==6){
                if(!q.empty())cout<<q.back()<<endl;
                else cout<<"-1\n";
            }
        }
    }
    return 0;
}