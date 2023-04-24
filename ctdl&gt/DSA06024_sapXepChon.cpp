#include<bits/stdc++.h>
using namespace std;
void swap(int *a,int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
void selection(int a[],int n){
	int min;
	for(int i=0;i<n-1;i++){
		min=i;
		for(int j=i+1;j<n;j++){
			if(a[j]<a[min])min=j;
		}
		swap(&a[min],&a[i]);
		cout<<"Buoc "<<i+1<<": ";
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
