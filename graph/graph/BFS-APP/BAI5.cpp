//  Min step to reach 1  
#include <bits/stdc++.h> 
#define MAX 100001
using namespace std;   
// bieu dien node da ta 
struct data { 
    int val; 
    int steps; 
}; 
int Solution(int N) { 
    queue<data> q; //tao hang doi q
    struct data x; 
	x.val=N; x.steps=0; //node bat dau voi so buoc 0
    q.push(x); //dua x vao hang doi
  	bool chuaxet[MAX] = {false};
    //set<int> st; 
    while (!q.empty()) { 
        data t = q.front(); q.pop();//t ra khoi hang doi
        if (t.val == 1) //neu da dat den 1
            return t.steps; //day la so buoc nho nhat          
        if (chuaxet[t.val-1]== false) { 
        	struct data x; x.val=t.val-1; x.steps=t.steps+1;
        	chuaxet[t.val-1] = true; q.push(x);             
        }   
        //dua cac uoc so tu lon den be vao hang doi
        for (int i = 2; i*i <= t.val; i++) { 
            if (t.val % i == 0 && !chuaxet[t.val/i] ){ 
            	struct data x; x.val=t.val/i; x.steps=t.steps+1;
        		chuaxet[t.val/i] = true; q.push(x);            
            } 
        } 
    }  
} 
//  Driver code 
int main() { 
    int N = 17; 
    cout << Solution(N) << endl;  
} 
