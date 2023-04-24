#include <bits/stdc++.h> 
typedef long long int ll;
using namespace std; 
//dua ra phan tu lon hon tiep theo  
void NGE(ll A[], int n) { 
    stack<ll> s; //tao stack s  
    ll A1[n]; //tao mang luu tru cac phan tu lon hon    
    for (ll i = n - 1; i >= 0; i--) {//duyet tu phai qua trai	
        //lap neu stack khac rong && s.top<A[i]
        while (!s.empty() && s.top() < A[i]) 
            s.pop();//loai phan tu dau stack   
        if (s.empty())  //neu stack rong
            A1[i] = -1;//khong co phan tu lon hon			
        else //phan tu lon hon chinh la s.top()
            A1[i] = s.top();  
        s.push(A[i]); //dua arr[i] vao stack
    } 
  	//dua ra ket qua
    for (ll i = 0; i < n; i++) 
        cout << A1[i] <<" "; 
    cout<<endl;
} 
  
//Test solution
int main() { 
    ll * A , n, T; 
    cin>>T;
    while(T--){
    	cin>>n; A= new ll[n];
    	for(int i=0; i<n; i++) cin>>A[i];
    	NGE(A,n); delete A;
	}
}
