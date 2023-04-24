// Dem so phep doi cho can thiet de tao nen bieu thuc dung
#include <bits/stdc++.h> 
#define MAX 100001
using namespace std;   
// dem so phep doi cho can thiet
long swapCount(string s) {     
    vector<int> pos; // giu vet cua ki tu '[' 
    for (int i = 0; i < s.length(); ++i) //duyet cac ki tu trong s
        if (s[i] == '[') //neu s la '['
            pos.push_back(i); //dua i vao vector
  	//s = []][][
    int count = 0; // dung de dem so ky tu '[' da gap
    int p = 0;  // dung de theo doi vi tri cua ky tu '[' tiep theo
    long sum = 0; // dung de luu ket qua 
  
    for (int i = 0; i < s.length(); ++i) { //duyet cac ky tu trong s
        // Increment count and move p to next position 
        if (s[i] == '[') { //neu gap '['
            ++count; //tang count
            ++p; //tang p
        } 
        else if (s[i] == ']') //neu gap dong ngoac
            --count; //giam count          
        if (count < 0)  { //phat hien vet cua ki tu mat can bang
            sum += pos[p] - i; //tang sum
            swap(s[i], s[pos[p]]); 
            ++p; //tang p              
            count = 1; //khoi tao lai count=1
        } 
    } 
    return sum; 
}   
// Test solution
int main() { 
	int T, n; cin>>T; char s[MAX];
	while(T--){
		cin>>n; //cin>>s;
		for(int i=0; i<n; i++) cin>>s[i];		
		cout<<swapCount(s)<<endl;		
	}
} 
//[]][][
