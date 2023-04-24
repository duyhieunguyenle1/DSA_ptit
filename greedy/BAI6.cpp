// Bai toan lua chon hanh dong
#include <bits/stdc++.h> 
#define MAX 101
using namespace std;   
// dinh nghia mot job: start,finish(thoi gian bat dau, ket thuc) 
struct Job { //dinh nghia mot job
    int start; //thoi gian bat dau
	int finish; //thoi gian ket thuc
	int index; //thu tu job bat dau tu 1
};   
// dinh nghia phep so sanh
bool Compare(Job s1, Job s2) { 
    return (s1.finish < s2.finish); 
}   
//Giai phap tham lam
void Solution(Job arr[], int n) { 
    //B1: sap xep theo thu tu tang cua thoi gian ket thuc
    sort(arr, arr+n, Compare);       
    //B2: luon chon Job co thoi gian ket thuc som nhat
    int i = 0; 
    cout << arr[i].index<<" "; 
  	//B3: xem xet cac job con lai    
    for (int j = 1; j < n; j++)  { 
      	if (arr[j].start >= arr[i].finish) { //neu them job j khong mu thuan
          	cout << arr[j].index<<" "; 
          	i = j; //nho chuyen giao gia tri tham tiep theo
      	} 
    } 
    cout<<endl;
}   
// Test Solution 
int main() { 
	Job arr[MAX]; 
	int n, T;cin>>T; 
	while(T--){
		cin>>n;
		for(int i=0;i<n; i++) {
			cin>>arr[i].start; //doc gia tri start
			arr[i].index = i+1;//thu tu job bat dau tinh tu 1..n
		}
		for(int i=0;i<n; i++) {
			cin>>arr[i].finish; //doc gia tri finish			
		}
		Solution(arr,n);
	}
}  
