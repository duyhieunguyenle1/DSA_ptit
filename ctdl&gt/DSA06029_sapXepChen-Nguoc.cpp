#include<bits/stdc++.h>
using namespace std;
void insertionSort(int a[],int n,stack<string>&st){
	int k=0,j,temp;
	for(int i=1;i<n+1;i++){
		// in cac buoc
        string s="";
        s=s+"Buoc "+to_string(k)+":";
		for(int l=0;l<=k;l++){
			s=s+" "+to_string(a[l]);
		}
        st.push(s);
		k++;
		// thuat toan chen
		j=i-1;
		temp=a[i];
		while(temp<a[j]&&j>=0){
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=temp;
	}
}
int main(){
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
    stack<string>st;
	insertionSort(a,n,st);
    while(st.size()){
        cout<<st.top()<<endl;
        st.pop();
    }
	return 0;
}
