// Bai toan: Job Sequencing
#include <bits/stdc++.h> 
#define MAX 101
using namespace std; 
  
// dinh nghia mot job 
struct Job { 
   int id;      // Job Id 
   int dead;    // thoi gian ket thuc job 
   int profit;  // loi nhuan thuc hien trong deadline 
};   
// Dinh nghia phep so sanh
bool comparison(Job a, Job b) { 
     return (a.profit > b.profit); 
}   
// Giai phap tham lam 
void Solution(Job A[], int n) { 
    //B1: sap xep theo thu tu giam dan cua loi nhuan
    sort(A, A+n, comparison);  
    int result[n]; // luu ket qua thu tu Job
    bool slot[n];  // luu vet thoi gian   
    //B2: thiet lap tat ca cac khe thoi gian la false
    for (int i=0; i<n; i++) 
        slot[i] = false;   
    // lap tren tat ca cac job 
    for (int i=0; i<n; i++) { 
       // tim khe thoi gian cho Job 
       for (int j=min(n, A[i].dead)-1; j>=0; j--) {           
          if (slot[j]==false)  { // neu slot[j] chua dung den
             result[j] = i;  // them job nay vao ket qua 
             slot[j] = true; // xac nhan job nay da dung
             break; 
          } 
       } 
    }   
    // dua ra ket qua
	int dem=0, FOPT =0; 
    for (int i=0; i<n; i++) 
       if (slot[i]) {
       		dem++; FOPT= FOPT+ A[result[i]].profit;
	   }
	cout<<dem<<" "<<FOPT<<endl;         
} 
  
// Test Solution
int main() { 	
    Job A[MAX]; int T, n;cin>>T;
	while(T--) {
		cin>>n; 
		for(int i=0; i<n; i++){
			cin>>A[i].id>>A[i].dead>>A[i].profit;
		}
		Solution(A,n);
	}                   
} 
