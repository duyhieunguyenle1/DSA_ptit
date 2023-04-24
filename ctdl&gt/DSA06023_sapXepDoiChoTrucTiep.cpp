#include<bits/stdc++.h>
using namespace std;
void selection(int a[],int n){
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(a[j]<a[i]){
			int temp=a[j];
				a[j]=a[i];
				a[i]=temp;
			}
		}
		printf("Buoc %d: ",i+1);
		for(int k=0;k<n;k++)cout<<a[k]<<" ";
		cout<<endl;
	}
}
int main(){
	int n; cin>>n;
	int a[n];
	for(int i=0;i<n;i++)cin>>a[i];
	selection(a,n);
	return 0;
}
