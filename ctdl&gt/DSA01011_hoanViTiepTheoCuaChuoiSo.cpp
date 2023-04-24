#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t=1;
    cin>>t;
    while(t--){
        int n; string s;
        cin>>n>>s;
        int len=s.size();
        int a[len];
        for(int i=0;i<len;i++)a[i]=s[i]-'0';
        cout<<n<<" ";
        if(next_permutation(a,a+len))
            for(int i=0;i<len;i++)cout<<a[i];
        else cout<<"BIGGEST";
        cout<<endl;
    }
    return 0;
}