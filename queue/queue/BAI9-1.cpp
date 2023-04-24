// tim max cua moi day con lien tuc do dai k
#include <bits/stdc++.h> 
using namespace std; 
// su dung Dequeue 
void Solution(int A[], int n, int k) { 
	//Qi luu vi tri phan tu lon nhat o truoc, nho nhat o sau
	deque<int> DQ(k);//khai bao dequeue size(k) 			
    //xu ly day con dau tien
    int i; //int A[] = { 12, 1, 78, 90, 57, 89, 56 }, k = 3;
    for (i = 0; i < k; ++i) { 
        // lap neu DQ khac rong va A[i]>=A[DQ.back()]
        while ((!DQ.empty()) && A[i] >= A[DQ.back()]) {    		        	
        	DQ.pop_back(); // loai phan tu phia sau DQ
		}          
        DQ.push_back(i);//them i vao phia sau DQ         
        
    } 
    /*cout<<"DQ.size()="<<DQ.size()<<"DQ.front="<<DQ.front()<<endl;    
    return;*/
    // xu ly cac phan tu con lai: A[k] to A[n-1] 
    for (i=k; i < n; ++i) { 
        // dua ra phan tu lon nhat day con truoc do
        cout << A[DQ.front()] << " ";  cin.get() ;
        // loai cac phan tu khong phai day con khoi dqueue
        while ((!DQ.empty()) && DQ.front() <= i - k) 
            DQ.pop_front(); // nho loai front  
        // loai cac phan tu nho hon         
        while ((!DQ.empty()) && A[i] >= A[DQ.back()]) 
            DQ.pop_back();   
        // dua phan tu hien tai vao sau
        DQ.push_back(i); 
    }   
    // dua ra not max cua day con cuoi dung
    cout << A[DQ.front()]<<endl; 
} 
int main() { 
    int arr[] = { 12, 1, 78, 90, 57, 89, 56 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int k = 3; 
    Solution(arr, n, k); 
    return 0; 
} 
/*
int main()  {  
	int T, *A, n, k; cin>>T;
	while(T--){
		cin>>n>>k; A = new int[n];
		for(int i=0; i<n; i++) cin>>A[i];
		Solution(A, n, k);
		delete A;
	}	 
}*/
