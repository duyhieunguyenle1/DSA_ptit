#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// https://www.geeksforgeeks.org/the-stock-span-problem/?ref=lbp

int main(){
    int t=1;
    cin>>t;
    while(t--){
        int n; cin>>n;
        // l(n) ghi so luong so nho hon hoac bang so hien tai
        // stack so luong so ma so hien tai khong lon hon
        // ket qua se la vi tri hien tai - so luong so (l[i])+1
        vector<int> a(n),l(n);
        for(int i=0;i<n;i++)cin>>a[i];
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty()&&a[st.top()]<=a[i])st.pop();
            if(st.empty())l[i]=0;
            else l[i]=st.top()+1;
            st.push(i);
        }
        for(int i=0;i<n;i++)cout<<i-l[i]+1<<" ";
        cout<<endl;
    }
    return 0;
}