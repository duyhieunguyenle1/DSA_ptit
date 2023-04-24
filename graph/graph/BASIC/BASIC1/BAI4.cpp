#include <iostream> 
#include <string> 
#include <vector> 
#include <algorithm> 
using namespace std;   
// so sanh hai xau 
int myCompare(string X, string Y) {     
    string XY = X.append(Y); //noi X voi Y      
    string YX = Y.append(X); //noi Y voi X  
    if(XY.compare(YX)>0) return 1;
    return 0;    
} 
//Sap xep cac phan tu cua vector 
void Largest(vector<string> arr) { 
    sort(arr.begin(), arr.end(), myCompare);   
    for (int i=0; i < arr.size() ; i++ ) 
        cout << arr[i]; 
} 
//chuong trinh chinh
int main() { 
    int n, T;cin>>T; string str;
	while(T--){
		cin>>n;vector<string> arr;
		for(int i=0; i<n; i++) {
			cin>>str; arr.push_back(str);	
		}	
		Largest(arr);cout<<endl;
	}	      
}
