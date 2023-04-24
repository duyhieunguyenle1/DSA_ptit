#include<bits/stdc++.h>
using namespace std;
void bubbleSort(int a[],int n,stack<string>&st){
    for(int i=0;i<n-1;i++){
        string s="";
        int check=0;
        for(int j=0;j<n-i-1;j++){
            if(a[j+1]<a[j]){
                swap(a[j],a[j+1]);
                check++;
            }
        }
        if(check!=0){
            s=s+"Buoc "+to_string(i+1)+":";
            for(int k=0;k<n;k++)s=s+" "+to_string(a[k]);
            st.push(s);
        }
    }
}
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        stack<string>st;
        bubbleSort(a,n,st);
        while(st.size()){
            cout<<st.top()<<endl;
            st.pop();
        }
    }
    return 0;
}