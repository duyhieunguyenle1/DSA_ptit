// Tim so nho nhat co N chu so 
// Chia het cho x, y, z.
#include <bits/stdc++.h>
using namespace std;
long long GCD(long long X, long long Y){ //tim USCLN cua X va Y
	while(Y!=0)	{
		long long r = X%Y; X=Y; Y=r;
	}
	return X;
}
long long LCM(int X, int Y, int Z) { //Tim BSCNH cua X, Y, Z
	long long p = GCD(X,Y);
	long long T = (X*Y)/p;
	long long q = GCD(T,Z);
	long long Result = (T*Z)/q;
	Result;
}
long long Solution(int n, int x, int y, int z) {    
    long long  lcm = LCM(x, y, z);//tim boi chung nho nhat cua X, Y, Z     
    long long  n_digit = (long long) pow(10, n-1);//Lay so nguyen nho nhat co n chu so    
    long long  du = n_digit % lcm;//lay phan du hai so     
    if (du == 0) //neu phan du la 0
         return n_digit;
    n_digit = n_digit + (lcm - du);//cong voi hieu nay     
    if (n_digit < (long long)pow(10, n))//chu y mat test cho nay
        return n_digit;
    else
        return 0;
}
int main() {
	int T;cin>>T;
    long long  n, x, y , z ;
    while(T--){
    	cin>>x>>y>>z>>n;
    	long long Result = Solution(n, x, y, z);	
    	if (Result != 0)
        	cout << Result<<endl;
    	else
        	cout << "-1"<<endl; 	
	} 
}

