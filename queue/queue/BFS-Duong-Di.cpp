#include <iostream>
#include <fstream>
#include <queue>
#define MAX 1000
using namespace std;
int A[MAX][MAX], chuaxet[MAX], n, truoc[MAX];
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
		truoc[u]=0;
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
				MyQueue.push(t); chuaxet[t]=false;truoc[t]=s;				
			}
		}
		
	}
}
void Duong_Di(int s, int t){
	BFS(s);
	if(truoc[t]==0){
		cout<<"\n Khong ton tai duong di"<<endl;
	}
	else {
		cout<<"\n Duong di:"<<t;
		int v = truoc[t];
		while(v!=s){
			cout<<"<-"<<v;
			v = truoc[v];
		}
		cout<<"<-"<<s;
	}
}
int main(void){
	Read_Data();ReInit(); Duong_Di(3, 10);
}
