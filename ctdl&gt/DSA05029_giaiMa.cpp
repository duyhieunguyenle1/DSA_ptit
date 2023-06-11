#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void Solution(string s){
    // nếu ký tự đầu là 0 thì ko có cách nào giải mã được (vì ko có ký tự 0)
    if(s[0]=='0'){
        cout<<0<<endl;
        return;
    }
    int n=s.size();
    int dp[n+1]={}; // dp[i] số lượng cách giải mã i ký tự đầu tiên của M
    dp[0]=1; // ko có ký tự nào thì chỉ có 1 cách giải mã
    dp[1]=1; // có 1 ký tự thì chỉ có 1 cách giải mã
    // nếu (dp[i-1],dp[i]) ghép lại nhỏ hơn 26(Z) thì ta có
    // f[i]+=f[i-2] (do có thêm f[i-2] cách sắp xếp)
    // ngược lại thì vẫn có từng đấy cách f[i]=f[i-1]
    for(int i=2;i<=n;i++){
        // nếu f[i]=0 mà f[i-1]>2 thì sẽ 0 có cách giải mã
        if(s[i-1]>'0')dp[i]=dp[i-1];
        if(s[i-2]=='1' || (s[i-2]=='2'&&s[i-1]<'7'))dp[i]+=dp[i-2];
    }
    cout<<dp[n]<<endl;
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        string s; cin>>s;
        Solution(s);
    }
    return 0;
}