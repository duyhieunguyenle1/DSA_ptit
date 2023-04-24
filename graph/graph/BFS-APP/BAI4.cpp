// minimum mode steps
#include <bits/stdc++.h> 
using namespace std;   
int Solution(int start, int end, int a[], int n) { 
    int ans[100001];//tao mang ket qua luc dau la -1    
    memset(ans, -1, sizeof(ans)); //ghi ans[i]=-1:i=0..100001
    int mod = 100000; //phep mode theo dau bai       
    queue<int> q; //tao hang doi q      
    q.push(start % mod); //dua trang thai dau tien vao q      
    ans[start] = 0; //ghi nhan so buoc di la 0      
    while (!q.empty()) { //duyet khi nao hang doi rong  
        int top = q.front(); //lay phan tu front          
        q.pop(); //loai phan tu front  
        // if the topmost element is end 
        if (top == end) //neu top dung la end
            return ans[end]; //day la phep mod it nhat  
        // neu khong ta se lam the nay
        for (int i = 0; i < n; i++) { 
            int pushed = top * a[i]; //nhan voi phan tu cua mang
            pushed = pushed % mod; //lay phan du voi 100000              
            if (ans[pushed] == -1) { //neu no dung la chua xet
                ans[pushed] = ans[top] + 1;//tang duong di len 1 
                q.push(pushed); //dua no vao hang doi
            } 
        } 
    } 
    return -1; 
} 
// Driver Code 
int main() { 
	int T, Start, End, N, *A; cin>>T;
	while(T--){
		cin>>N>>Start>>End;
		A = new int [N];
		for(int i=0; i<N; i++) cin>>A[i];
		cout<<Solution(Start, End, A, N)<<endl;
		delete A;
	}
    //int start = 7, end = 66175; 
    //int A[] = { 3, 4, 65 };    
} 
