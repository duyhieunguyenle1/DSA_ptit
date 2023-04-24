#include <iostream>
#include <fstream>
#include <queue>
#define MAX 1000
using namespace std;
int A[MAX][MAX], chuaxet[MAX], n;
void Read_Data(void){
	ifstream fp("dothi.in");
	fp>>n; cout<<"\n So dinh do thi:"<<n<<endl;
	cout<<"Ma tran ke bieu dien do thi:"<<endl;
	for (int u=1; u<=n; u++){
		for(int v=1; v<=n; v++){
			fp>>A[u][v];
			cout<<A[u][v]<<" ";
		}
		cout<<endl;
	}
	fp.close();
}
void ReInit(void){
	for(int u=1; u<=n; u++){
		chuaxet[u]=true;
	}   
}
void BFS(int u){
	queue <int> MyQueue;
	MyQueue.push(u); chuaxet[u]=false;
	cout<<"\n Ket qua duyet:";
	while(!MyQueue.empty()){
		int s = MyQueue.front();MyQueue.pop();
		cout<<s<<" ";
		for(int t=1; t<=n; t++){
			if(chuaxet[t]&& A[s][t]){
				MyQueue.push(t); chuaxet[t]=false;
			}
		}
		
	}
}
int main(void){
	Read_Data();ReInit(); BFS(3);
}
