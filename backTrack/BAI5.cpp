// Tim so lon nhat co the tao ra bang cach thuc hien nhieu nhat K swap
#include <bits/stdc++.h> 
using namespace std; 
void Solution(string str, int k, string & max) { 
    // return if no swaps left 
    if(k == 0) //neu k=0 ta ket thuc
        return;   
    int n = str.length(); //lay do dai str      
    // xem xet moi chu so 
    for (int i = 0; i < n - 1; i++) {        
        // so sanh chu so voi so dung sau no
        for (int j = i + 1; j < n; j++) { 
            if (str[i] < str[j]) { //neu dieu nay xay ra                
                swap(str[i], str[j]); //doi cho hai so                  
                if (str.compare(max) > 0) //neu dieu nay xay ra
                    max = str;   
                // de qui phep trao doi k-1 
                Solution(str, k - 1, max);                   
                swap(str[i], str[j]); //tra lai gia tri quay lui
            } 
        } 
    } 
}   
// Test Solution 
int main() { 
    int T, K; cin>>T;
    while(T--) {
    	string str, max;
		cin>>K; cin>>str; max =str;
		Solution(str, K, max);	
		cout << max << endl;
	}
}
 
