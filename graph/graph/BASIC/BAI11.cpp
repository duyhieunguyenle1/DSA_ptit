//DFS: kiem tra do thi vo huong co chu trinh
#include<bits/stdc++.h> 
using namespace std; 
int V, E; //tap dinh va tap canh cua do thi
vector <int> *adj;//danh sach ke cua do thi
bool  *visited;//ghi nhan trang thai chua xet cu dinh
void Graph_Adj(void) {
	fstream fp("DD1.IN");
	fp>>V>>E;//doc so dinh va so canh cua do thi;
	adj = new vector<int>[V+1];
	for(int i=1;i<=E; i++){
		int u, v;//u, v la dinh dau,dinh cuoi cua canh
		fp>>u>>v;
		adj[u].push_back(v);//them v vao ke(u)
		adj[v].push_back(u);//them u vao ke(v)
	}
	fp.close();	
}
void ReInit(void){	//thiet lap visited[u]=true
	visited = new bool[V+1];	
	for(int u=0; u<=V; u++) {		
		visited[u]=true;		
	}
}
bool  DFS(int u, int parrent) { //thuat toan DFS de qui
	visited[u]=false;//thiet lap u da tham
	//cout<<parrent<<" ";
	for(int v=0; v<adj[u].size(); v++){
		if(visited[adj[u][v]]) {//neu dinh adj[u][v] chua xet
			if(DFS(adj[u][v],u))
				return true;			
		} //DFS(1)=1,2,3 3
		else if(adj[u][v]!=parrent) 
			return true;
	}
	return false;
} 
bool isCyclic(void){
    for (int u = 1; u <= V; u++) {	
	   if (visited[u]) {	   
          if (DFS(u,-1)) 
             return true; 
    	}
  	}
    return false; 	
}
// chuong trinh chinh 
int main() { 
	Graph_Adj();//bieu dien do thi bang adj	
	ReInit(); //thiet lap chuaxet[u], truoc[u]
	if(isCyclic()) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
} 
