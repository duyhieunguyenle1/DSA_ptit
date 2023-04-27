#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int t = 1;
    // cin>>t;
    while (t--){
        int n;
        cin >> n;
        int a[n+1][n+1]={0};
        cin.ignore();
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j)a[i][j]=0;
        }
        for (int i = 1; i <= n; i++){
            string s;
            getline(cin, s);
            stringstream ss(s);
            int x;
            while (ss >> x){
                a[i][x] = 1;
                a[x][i] = 1;
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}