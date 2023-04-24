// minimum mode steps
#include <bits/stdc++.h> 
#define MAX 100001
using namespace std;   
void Solution(int start, int end, int a[], int n) { 
    bool visited[MAX]={false};//tao mang ket qua luc dau la -1    
    int truoc[MAX] = {0};
    memset(visited, false, sizeof(visited)); //ghi visited[i]=-1:i=0..100001
    int mod = 100000; //phep mode theo dau bai       
    queue<int> q; //tao hang doi q      
    q.push(start % mod); //dua trang thai dau tien vao q      
    visited[start] = true; //ghi nhan so buoc di la 0      
    while (!q.empty()) { //duyet khi nao hang doi rong  
        int s = q.front(); //lay phan tu front          
        q.pop(); //loai phan tu front  
        // if the smott element is end 
        if (s == end) //neu s dung la end
            break; //thoi khong thuc hien nua  
        // neu khong ta se lam the nay
        for (int i = 0; i < n; i++) { 
            int t = s * a[i]; //nhan voi phan tu cua mang
            t = t % mod; //lay phan du voi 100000              
            if (visited[t] == false) { //neu no dung la chua xet
                visited[t] = visited[s] + 1;//tang duong di len 1 
                q.push(t); //dua no vao hang doi
                truoc[t]=s;
            } 
        } 
    } 
    if(truoc[end]==0){//neu dieu na xay ra
    	cout<<"-1"<<endl;//ket luan khong co nghiem
	}
	else {
		int dem =0, t=truoc[end];
		while(t!=start){
			dem++;
			t=truoc[t];
		}
		cout<<dem+1<<endl;
	}    
} 
// Driver Code 
int main() { 
	int T, Start, End, N, *A; cin>>T;
	while(T--){
		cin>>N>>Start>>End;
		A = new int [N];
		for(int i=0; i<N; i++) cin>>A[i];
		Solution(Start, End, A, N);
		delete A;
	}
    //int start = 7, end = 66175; 
    //int A[] = { 3, 4, 65 };    
} 
