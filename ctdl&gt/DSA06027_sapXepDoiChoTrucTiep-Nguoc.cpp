#include<bits/stdc++.h>
using namespace std;
void selection(int a[],int n,stack<string>&st){
	for(int i=0;i<n-1;i++){
        string s="";
		for(int j=i+1;j<n;j++){
			if(a[j]<a[i])swap(a[i],a[j]);
        }
        s+="Buoc ";
        s+=to_string(i+1);
        s+=": ";
		for(int k=0;k<n;k++){
            s=s+to_string(a[k])+" ";
        }
        st.push(s);
    }
}
int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        stack<string>st;
        selection(a,n,st);
        while(st.size()){
            cout<<st.top()<<endl;
            st.pop();
        }
    }
	return 0;
}
