//  Min step to reach 1  
#include <bits/stdc++.h> 
#define MAX 100001
using namespace std;   
// bieu dien node da ta 
struct data { 
    int val; 
    int steps; 
}; 
void Solution(int N) { 
    queue<int> q; //tao hang doi q
  	bool chuaxet[MAX] = {false};
  	int truoc[MAX]={0};
  	//B1. Thuat toan BFS
  	q.push(N);//dua N vao hang doi
	chuaxet[N]=true;//doi trang thai cua N      
    while (!q.empty()) { //lap khi nao hang doi rong
        int t = q.front(); q.pop();//t ra khoi hang doi
        //cout<<t<<" ";
        if(t==1) break; //neu t la 1
        if (!chuaxet[t-1]) { //neu gia tri t-1 chua xet			        	
        	chuaxet[t-1] = true; q.push(t-1);             
        	truoc[t-1] = t;
        }   
        //dua cac uoc so tu lon den be vao hang doi
        for (int i = 2; i*i <= t; i++) { 
            if (t% i== 0 && !chuaxet[t/i] ){             	
        		chuaxet[t/i] = true; q.push(t/i);truoc[t/i]=t;            
            } 
        } 
    }  
    //dem so buoc dic chuyen
    int t = truoc[1], dem=0;
    while(t!=N) {
    	dem++;
    	t = truoc[t];
	}
	cout<<dem+1<<endl;
} 
//  Driver code 
int main() { 
    int N = 17; 
    Solution(N);  
} 
