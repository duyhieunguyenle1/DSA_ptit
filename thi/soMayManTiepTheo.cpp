#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t=1;
    // cin>>t;
    while(t--){
        queue<ll>q;
        vector<ll>v;
        q.push(4);
        q.push(7);
        v.push_back(4);
        v.push_back(7);
        while(q.front()<1e9){
            ll top,x,y;
            top = q.front();
            q.pop();
            x=top*10+4;
            y=top*10+7;
            q.push(x);
            q.push(y);
            v.push_back(x);
            v.push_back(y);
        }
        int a,b; cin>>a>>b;
        ll res=0,cnt=0;
        int index = lower_bound(v.begin(),v.end(),a)-v.begin();
        while(a<=b){
            cnt=min(v[index],1LL*b)-a+1;
            res+=cnt*v[index];
            a=v[index]+1;
            index++;
        }
        cout<<res;
    }
    return 0;
}