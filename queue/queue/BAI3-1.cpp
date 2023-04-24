// Tim so nguyen X nho nhat duoc tao boi so 9,0
// chia het cho N
#include <bits/stdc++.h>
using namespace std;
#define MAX 100000
vector <long long> vec;
void Generation(void) {   
	vec.push_back(9); 
	for(int i=1; i<=MAX; i++)    {
		
	}
    queue <long long > q;//tao queue rong thich nghi voi long long
    q.push(9);long long X=9; //so dau tien la so 9
    while(!q.empty()) {
    	X = q.front();q.pop();
    	vec.push_back(X);
    	if(X* 10 <=MAX) q.push(X*10 + 0);
    	if(X* 10 + 9 <=MAX) q.push(X*10 + 9);    		
	}    
}
long long FindNumber(int n){
	for(int i=0; i<vec.size(); i++){
		if(vec[i]%n==0) return vec[i];		
	}	
}
int main(){    
    int T, n; cin>>T;Generation();
    FindNumber(n);
    while(T--) {
		cin>>n; cout << FindNumber(n)<<endl;
	}   
}

