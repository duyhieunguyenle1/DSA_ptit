// Sinh ra ma Gray do dai n
#include <bits/stdc++.h> 
using namespace std;   
void Gray(int n) { 
    // neu n nho hon 0 ta khong co ma nao 
    if (n <= 0) return; 
    vector <string> L1; //tao mang luu ma gray  
    //B1: Xuat phat tu cac ma gray do dai 1
    L1.push_back("0");  L1.push_back("1");   
    //B2: Sinh ra 2*i ma gray tu ma Gray do dai n-1    
    for (int i = 2; i < pow(2,n); i = i*2) { 
        // Tadua them ma gray truoc do theo thu tu nguoc
        // 1. Tao L2[] la dao nguoc cua L1
        for (int j = i-1 ; j >= 0 ; j--) //xuat phat tu j=i-1
            L1.push_back(L1[j]);//them cac phan tu dao nguoc ve phia sau
        //2. Them 0 vao dau moi phan tu thuoc nua dau L1
        for (int j = 0 ; j < i ; j++) 
            L1[j] = "0" + L1[j];   
        //3. Them 1 vao dau moi phan tu nua cuoi
        for (int j = i ; j < 2*i ; j++) 
            L1[j] = "1" + L1[j]; 
    }   
    // dua ra ket qua  
    for (int i = 0 ; i < L1.size() ; i++ ) 
        cout << L1[i] << " ";
	cout<<endl;
} 
// Test solution 
int main() { 
	int T, n; cin>>T;
	while(T--){
		cin>>n;
		Gray(n);
	}
} 
