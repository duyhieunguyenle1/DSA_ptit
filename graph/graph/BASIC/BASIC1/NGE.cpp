// phan tu lon hon ke tiep trong mang
#include <bits/stdc++.h> 
typedef long long int ll;
using namespace std; 
//dua ra phan tu lon hon tiep theo  
void NGE(ll arr[], int n) { 
    stack<ll> s; //tao stack s  
    ll arr1[n]; //tao mang luu tru cac phan tu lon hon    
    for (ll i = n - 1; i >= 0; i--) {//duyet tu phai qua trai	
        //lap neu stack khac rong && s.top<arr[i]
        while (!s.empty() && s.top() < arr[i]) 
            s.pop();//loai phan tu dau stack   
        if (s.empty())  //neu stack rong
            arr1[i] = -1;//khong co phan tu lon hon			
        else //phan tu lon hon chinh la s.top()
            arr1[i] = s.top();  
        s.push(arr[i]); //dua arr[i] vao stack
    } 
  
    for (ll i = 0; i < n; i++) 
        cout << arr1[i] <<" "; 
    cout<<endl;
} 
  
/* Driver program to test above functions */
int main() { 
    ll * A , n, T; 
    cin>>T;
    while(T--){
    	cin>>n; A= new ll[n];
    	for(ll i=0; i<n; i++) cin>>A[i];
    	NGE(A,n); delete A;
	}
}
