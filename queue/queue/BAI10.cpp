//tong so lon nhat va be nhat
//cua tat ca cac day con lien tuc do dai k
#include<bits/stdc++.h> 
using namespace std; 
int Solution(int A[] , int n , int k) { 	
    int sum = 0;  // thiet lap ket qua ban dau  
    // G luu tru thu tu giam dan
    // S luu tru thu tu tang dan
    deque< int > S(k), G(k);   	
    // xu ly day con dau tien
    int i = 0; 
    for (i = 0; i < k; i++) { 
        // loai cac phan tu lon hon khong dung den
        while ( (!S.empty()) && A[S.back()] >= A[i]) 
            S.pop_back(); // nho lai phia sau  
        // loai cac phan tu nho hon khong dung den
        while ( (!G.empty()) && A[G.back()] <= A[i]) 
            G.pop_back(); // nho lai phia sau  
        // Add current element at rear of both deque 
        G.push_back(i); //dua phan tu hien tai vao dequeue G
        S.push_back(i); //dua phan tu hien tai vao dequeue S
    }   
    // xu ly cac day con con lai
    for (i=k ; i < n; i++ )     { 
        // tinh tong lon nhat va be nhat
        sum += A[S.front()] + A[G.front()];   
        // loai cac phan tu khong thuoc day hien tai
        while ( !S.empty() && S.front() <= i - k) 
            S.pop_front(); 
        while ( !G.empty() && G.front() <= i - k) 
            G.pop_front();   
        // loai cac phan tu lon hon trong S khong dung den
        while ( (!S.empty()) && A[S.back()] >= A[i]) 
            S.pop_back(); // Remove from rear 
  		// loai cac phan tu nho hon trong G khong dung den
        while ( (!G.empty()) && A[G.back()] <= A[i]) 
            G.pop_back(); // Remove from rear 
        G.push_back(i); //dua i vao G
        S.push_back(i); //dua i vao S
    }   
    // cong not day con cuoi cung
    sum += A[S.front()] + A[G.front()];   
    return sum; 
}   
// Driver program to test above functions 
int main() { 
    int A[] = {2, 5, -1, 7, -3, -1, -2} ; 
    int n = sizeof(A)/sizeof(A[0]); 
    int k = 3; 
    cout << Solution(A, n, k) ; 
    return 0; //4+6+4+4-4
} 
