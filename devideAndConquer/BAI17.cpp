// Bai 13: tim floor(X)
#include<bits/stdc++.h> 
typedef long long ll;
using namespace std;  
int floorSearch(ll arr[], int low, int high, ll x) { 
    // neu can duoi vuot qua can tren
    if (low > high) 
        return -1; //ket luan floor(x)=-1  
    // neu phan tu cuoi cung nho hon x
    if (x >= arr[high]) 
        return high; //ket luan day la vi tri floor(x)      
    int mid = (low+high)/2;// lay diem giua       
    if (arr[mid] == x) //neu diem giua la x
        return mid;   
    // neu x nam giua  mid-1 and mid 
    if (mid > 0 && arr[mid-1] <= x && x < arr[mid]) 
        return mid-1;       
    if (x < arr[mid]) //neu x nho hon floor
        return floorSearch(arr, low, mid-1, x); //tim ben trai
    return floorSearch(arr, mid+1, high, x); //tim ben phai
} 
  
//test solution
int main() { 
	ll *A,T, N, X; cin>>T;
	while(T--) {
		cin>>N>>X; A = new ll[N];
		for(int i=0; i<N; i++) cin>>A[i];
		cout<<floorSearch(A, 0, N-1, X)<<endl;
		delete A;
	}
} 
