//Thuat toan BFS: do thi co huong
#include<bits/stdc++.h> 
using namespace std; 
int V, E; //tap dinh va tap canh cua do thi
vector <int> *adj;//danh sach ke cua do thi
bool  *chuaxet;//ghi nhan trang thai chua xet cu dinh
void Graph_Adj(void) {
	fstream fp("DOTHI.IN");//mo file de doc
	fp>>V>>E;//doc so dinh va so canh cua do thi;
	adj = new vector<int>[V+1];
	for(int i=1;i<=E; i++){
		int u, v;//u, v la dinh dau,dinh cuoi cua canh
		fp>>u>>v; // doc mot canh
		adj[u].push_back(v);//them v vao ke(u)
		//adj[v].push_back(u);//them u vao ke(v)
	}
	fp.close();	
}
void ReInit(void){	//thiet lap trang thai cac dinh
	chuaxet = new bool[V+1];
	for(int i=0; i<=V; i++) 		
		chuaxet[i]=true;
}
void BFS(int u){ //thuat toan BFS
	queue <int> q; //tao lap q la mot hang doi
	q.push(u);//dua u vao queue
	chuaxet[u]=false;//thiet lap trang thai dinh u
	cout<<"Ket qua duyet:";
	while(!q.empty()) { //lap den khi queue rong
		int s=q.front();//s la dinh vao truoc cua queue
		q.pop();//loai s khoi hang doi
		cout<<s<<" ";//tham dinh s
		for(int t=0; t<adj[s].size(); t++){//duyet tren ke(s)
			if(chuaxet[adj[s][t]]){//neu dinh chua xet
				q.push(adj[s][t]);//dua vao hang doi
				chuaxet[adj[s][t]]=false;//thiet lap trang thai
			}
		}
	}	
}
// chuong trinh chinh 
int main() { 
	Graph_Adj();//bieu dien do thi bang adj
	ReInit();//thiet lap chua xet
	BFS(1);//duyet BFS
} 
