//Kiem tra mang co chia thanh k tap co tong bang nhau
#include <bits/stdc++.h> 
#define MAX 101
using namespace std;   
//Input:
    //A[]:	mang du lieu vao gom N phan tu 
    //subsetSum array: tong luu moi tap con 
    //taken    : mang dung de kiem tra co chia duoc hay khong                      
    //K 	: so luong tap con
    // N  : so luong phan tu
    //curIdx: chi so tap con hien tai
    //limitIdx 
bool K_Test(int A[], int subsetSum[], bool taken[], 
                   int subset, int K, int N, int curIdx, int limitIdx) { 
    if (subsetSum[curIdx] == subset) { 
        /*  current index (K - 2) represents (K - 1) subsets of equal 
            sum last partition will already remain with sum 'subset'*/
        if (curIdx == K - 2) //neu dieu nay xay ra
            return true;//chac chan da co nghiem  
        // goi de qui den tap con tiep theo
        return K_Test(A, subsetSum, taken, subset, 
                                            K, N, curIdx + 1, N - 1); 
    }   
    // duyet tu limitIdx  
    for (int i = limitIdx; i >= 0; i--)  {         
        if (taken[i]) //neu phan tu da dung den
            continue; //duyet phan tu khac
        //tinh tong tap con
		int tmp = subsetSum[curIdx] + A[i];   
        // if temp is less than subset then only include the element 
        // and call recursively 
        if (tmp <= subset)  { //neu temp nho hon hoac bang subset
            //  mark the element and include into current partition sum 
            taken[i] = true; 
            subsetSum[curIdx] += A[i]; 
            bool nxt = K_Test(A, subsetSum, taken, 
                                            subset, K, N, curIdx, i - 1); 
  
            // after recursive call unmark the element and remove from 
            // subsetition sum 
            taken[i] = false; 
            subsetSum[curIdx] -= A[i]; 
            if (nxt) 
                return true; 
        } 
    } 
    return false; 
} 
bool Solution(int A[], int N, int K) {     
    if (K == 1) //luon co nghiem
        return true;   
    if (N < K) //khong bao gio co nghiem
        return false;   
    int sum = 0; //tinh tong cac phan tu cua mang
    for (int i = 0; i < N; i++) 
        sum += A[i]; 
    if (sum % K != 0) //neu sum khong chia het cho K
        return false; //cung khong bao gio co nghiem  
    //  neu co the co nghiem moi tap con chi co the co tong la sum/K
    int subset = sum / K; //tong cua moi tap con
    int subsetSum[K]; //luu tong K tap con
    bool taken[N]; //trang thai cac phan tu  
    //  thiet lap tong moi tap con ban dau la 0
    for (int i = 0; i < K; i++) 
        subsetSum[i] = 0;   
    //  danh dau tat ca cac phan tu chua dung den
    for (int i = 0; i < N; i++) 
        taken[i] = false;   
    // thiet lap tap con dau tien la phan tu cuoi cung    
    subsetSum[0] = A[N - 1]; 
    //xac nhan phan tu cuoi cung da dung
    taken[N - 1] = true;   
    // goi den thu tuc K_Test()
    return K_Test(A, subsetSum, taken, subset, K, N, 0, N - 1); 
} 
  
//  Test solution 
int main() { 
    int A[MAX], N, K, T; cin>>T;
    while(T--) {
    	cin>>N;
    	for(int i=0; i<N; i++) cin>>A[i];
    	cin>>K;
    	cout<<Solution(A,N,K)<<endl;
	}
}
