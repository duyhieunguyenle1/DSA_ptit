#include<iostream>
using namespace std;
void insertionSort(int a[],int n){
	int k=0,j,temp;
	for(int i=1;i<n+1;i++){
		// in cac buoc
		cout<<"Buoc "<<k<<":";
		for(int l=0;l<=k;l++){
			cout<<" "<<a[l];
		}
		k++;
		cout<<endl;
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
	insertionSort(a,n);
	return 0;
}
