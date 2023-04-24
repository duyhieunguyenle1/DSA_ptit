#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// sort array then loop from 0 to n-2
// initialize j = i+1 and k = n-1
// loop if a[i]+a[j]+a[k] < sum 
// then all the element from j to k is less than x 
// then move j else k--
int main(){ 
    int t; cin>>t;
    while(t--){
        int n;
        ll x; 
        cin>>n>>x;
        ll a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        ll res=0;
        for(int i=0;i<n-2;i++){
            int j=i+1,k=n-1;
            while(j<k){
                if(a[i]+a[j]+a[k]>=x)k--;
                else {
                    res+=(k-j);
                    j++;
                }
            }
        }
        cout<<res<<endl;
    }
}