#include<iostream>
using namespace std;
void bubbleSort(int a[],int n){
    for(int i=0;i<n-1;i++){
        int check=0;
        for(int j=0;j<n-i-1;j++){
            if(a[j+1]<a[j]){
                swap(a[j],a[j+1]);
                check++;
            }
        }
        if(check!=0){
            printf("Buoc %d:",i+1);
            for(int k=0;k<n;k++)cout<<" "<<a[k];
            cout<<endl;
        }
    }
}
int main(){
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    bubbleSort(a,n);
    return 0;
}