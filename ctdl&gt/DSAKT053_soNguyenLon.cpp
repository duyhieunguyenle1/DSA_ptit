#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t=1;
    cin>>t;
    while(t--){
        string s1,s2; cin>>s1>>s2;
        int len1=s1.size(),len2=s2.size();
        int F[len1+1][len2+1];
        for(int i=0;i<=len1;i++){
            for(int j=0;j<=len2;j++){
                if(i==0||j==0)F[i][j]=0;
                else {
                    if(s1[i-1]==s2[j-1])F[i][j]=F[i-1][j-1]+1;
                    else F[i][j]=max(F[i][j-1],F[i-1][j]);
                }
            }
        }
        cout<<F[len1][len2]<<endl;
    }
    return 0;
}