//Chu y: 
#include <bits/stdc++.h>
#define MAX 100
using namespace std;
char Fib(int n, int k) {
	string Fib[MAX];
	Fib[0]="A"; Fib[1]="B";
	for(int i=2; i<n; i++) {
		Fib[i] = Fib[i-2] + Fib[i-1];
		//cout<<Fib[i]<<" "; 
	}
	return Fib[n-1].at(k-1);
}
int main(void) {
	
	cout<<Fib(6,4)<<endl;
	cout<<Fib(8,19)<<endl; 
}
