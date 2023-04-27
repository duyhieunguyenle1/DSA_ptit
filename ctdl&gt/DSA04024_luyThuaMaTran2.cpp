#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

//https://www.geeksforgeeks.org/matrix-exponentiation/

int MOD = 1e9+7;
int n,k;
ll a[11][11],d[11][11];

void Multi(ll a[11][11], ll b[11][11]){
    // multiply matrix
    ll c[11][11]={}; // store value if doesnt have {} then wrong cuz all value are undefined
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                c[i][j]+=a[i][k]*b[k][j];
                c[i][j]%=MOD;
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            a[i][j]=c[i][j]; // update matrix
        }
    }
}

void Pow(ll a[11][11],int k){
    // calc matrix exponentiation
    if(k==1)return;
    Pow(a,k/2);
    Multi(a,a);
    if(k%2==1)Multi(a,d);
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                cin>>a[i][j];
                d[i][j]=a[i][j];
            }
        }
        Pow(a,k);
        ll ans=0;
        for(int i=1;i<=n;i++){
            ans+=a[i][n];
            ans%=MOD;
        }
        cout<<ans<<endl;
    }
    return 0;
}