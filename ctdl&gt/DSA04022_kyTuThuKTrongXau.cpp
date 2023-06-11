#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// tương tự bài này
// https://daynhauhoc.com/t/can-giai-thich-ve-code-gap-doi-day-so-c/117372/6

vector<int>f(30);
void prepare(){
    f[1]=1;
    for(int i=2;i<30;i++)f[i]=f[i-1]*2;
}
void Solution(){
    int n,k; cin>>n>>k;
    for(int i=n;i>=1;i--){
        if(k>f[i])k-=f[i];
        else if(k==f[i]){
            cout<<char(i-1+'A')<<endl;
            return;
        }
    }
}

int main(){
    int t=1;
    cin>>t;
    prepare();
    while(t--){
        Solution();
    }
    return 0;
}