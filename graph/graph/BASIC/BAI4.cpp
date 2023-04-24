//Thuat toan DFS: do thi co huong
#include<bits/stdc++.h> 
using namespace std; 
int V, E; //tap dinh va tap canh cua do thi
vector <int> *adj;//danh sach ke cua do thi
bool  *chuaxet;//ghi nhan trang thai chua xet cu dinh
void Graph_Adj(void) {
	fstream fp("DOTHI.IN");
	fp>>V>>E;//doc so dinh va so canh cua do thi;
	adj = new vector<int>[V+1];
	for(int i=1;i<=E; i++){
		int u, v;//u, v la dinh dau,dinh cuoi cua canh
		fp>>u>>v;
		adj[u].push_back(v);//them v vao ke(u)
		//adj[v].push_back(u);//them u vao ke(v)
	}
	fp.close();	
}
void ReInit(void){	//thiet lap chuaxet[u]=true
	chuaxet = new bool[V+1];
	for(int u=0; u<=V; u++) 		
		chuaxet[u]=true;
}
void DFS(int u) { //thuat toan DFS de qui
	cout<<u<<" "; chuaxet[u]=false;
	for(int v=0; v<adj[u].size(); v++){
		if(chuaxet[adj[u][v]]) 
			DFS(adj[u][v]);
	}
}
void DFS_Stack(int u){ //thuat toan DFS stack
	stack <int> stk;stk.push(u);chuaxet[u]=false;
	cout<<"Ket qua duyet:"<<u<<" ";
	while(!stk.empty()){
		int s = stk.top(); stk.pop();
		for(int t=0; t<adj[s].size(); t++){
			if(chuaxet[adj[s][t]]){
				cout<<adj[s][t]<<" "; chuaxet[adj[s][t]] =false;
				stk.push(s); stk.push(adj[s][t]);
				break;
			}
		}
	}
	
}
// chuong trinh chinh 
int main() { 
	Graph_Adj();	ReInit();
	cout<<"Ket qua duyet:";DFS(5);
	//DFS_Stack(5);	
} 
