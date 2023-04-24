// Thu tuc de qui giai bai toan subset sum
#include <bits/stdc++.h> 
#define MAX 101
using namespace std;   
// ham tra lai true neu co tap con co tong la sum 
bool isSubsetSum (int arr[], int n, int sum)  {      
    if (sum == 0) //neu sum la 0 
        return true;  //ket luan dung
    if (n == 0 && sum != 0)  //neu dieu nay xay ra
        return false;  //ket luan khong co  
    if (arr[n-1] > sum)  //neu phan tu cuoi cung lon hon sum
       return isSubsetSum (arr, n-1, sum);  //tim trong tap n-1 so thoi  
    /* truong hop khac: 
        (a) tong chua phan tu cuoi cungincluding the last element  
        (b) khong chua phan tu cuoi cung 
    */
    return isSubsetSum (arr, n-1, sum) ||  
        isSubsetSum (arr, n-1, sum-arr[n-1]);  
}  
// ham tra lai gia tri dung neu mang chia thanh hai tap
// co tong bang nhau, nguoc lai tra lai gia tri false
bool findPartiion (int arr[], int n)  {  
    //B1: tinh tong cac phan tu 
    int sum = 0;  
    for (int i = 0; i < n; i++)  
    	sum += arr[i];    
    if (sum%2 != 0)  //neu tong le
    	return false;  //chac chan khong chia duoc
    return isSubsetSum (arr, n, sum/2);  //neu dieu nay dung
}    
//giai phap qui hoach dong
bool findPartiion (int arr[], int n)  {  
    int sum = 0;  
    int i, j;       
    // Tinh tong cac phan tu  
    for (i = 0; i < n; i++)     sum += arr[i];        
    if (sum % 2 != 0)  //neu tong le
		return false;        
    bool part[sum / 2 + 1][n + 1];        
    // thiet lap hang dau tien la true 
    for (i = 0; i <= n; i++)  
    	part[0][i] = true;            
    // initialize leftmost column,  
    // except part[0][0], as 0  
    for (i = 1; i <= sum / 2; i++)  
    	part[i][0] = false;  
      
    // Fill the partition table in botton up manner  
    for (i = 1; i <= sum / 2; i++)  {  
        for (j = 1; j <= n; j++)    {  
            part[i][j] = part[i][j - 1];  
            if (i >= arr[j - 1])  
            part[i][j] = part[i][j] ||  
                         part[i - arr[j - 1]][j - 1];  
        }      
    }  
      
    /*// uncomment this part to print table  
    for (i = 0; i <= sum/2; i++)  
    {  
    for (j = 0; j <= n; j++)  
        cout<<part[i][j];  
    cout<<endl;  
    } */      
    return part[sum / 2][n];  
}  
  
// Test solution  
int main()  {  
    int A[MAX], T, N; cin>>T;
    while(T--) {
    	cin>>N;
    	for(int i=0; i<N; i++) cin>>A[i];
    	if(findPartiion(A,N)) cout<<"YES"<<endl;
    	else cout<<"NO"<<endl;
	}
}  
