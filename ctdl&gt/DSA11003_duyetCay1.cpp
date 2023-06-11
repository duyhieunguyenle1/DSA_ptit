#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int pos=0;

void postOrder(int inOrder[],int preOrder[],int l, int r, unordered_map<int,int>&m){
    if(l<=r){
        int idx=m[preOrder[pos++]];
        postOrder(inOrder,preOrder,l,idx-1,m);
        postOrder(inOrder,preOrder,idx+1,r,m);
        cout<<inOrder[idx]<<" ";
    }
}

int main(){
    int t=1;
    cin>>t;
    while(t--){
        int n; cin>>n;
        int inOrder[n],preOrder[n];
        for(int &i:inOrder)cin>>i;
        for(int &i:preOrder)cin>>i;
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)m[inOrder[i]]=i;
        pos=0;
        postOrder(inOrder,preOrder,0,n-1,m);
        cout<<endl;
    }
    return 0;
}