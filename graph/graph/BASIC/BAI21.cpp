// A C++ Program to detect cycle in a graph 
#include<bits/stdc++.h> 
using namespace std; 
#include<bits/stdc++.h> 
using namespace std; 
int V, E; //tap dinh va tap canh cua do thi
vector <int> *adj;//danh sach ke cua do thi
//ghi nhan trang thai chua xet cu dinh
bool *visited, parrent; 
void Graph_Adj(void) {
	fstream fp("DOTHICYCLE.IN");
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
bool ReInit() { 
    visited = new bool[V+1];
	parrent=-1;     
    for(int i = 0; i <= V; i++) { 
        visited[i] = true;         
    } 
}  

bool  DFS(int u) { //thuat toan DFS de qui
    if(visited[u] ){ 
        //danh dau dinh hien tai da tham va recstack
        visited[u] = false;         
        //duyet tren tap dinh ke cua u
        for(int v = 0; v!= adj[u].size(); v++) { 
            if ( visited[adj[u][v]] ){
				parrent=v; DFS(adj[u][v]) ;
                	return true; 
        	}
            else if (adj[u][v]!=parrent) 
                return true; 
        }   
    } 
    return false; 
} 
/*
bool Graph::isCyclicUtil(int v, bool visited[], int parent) 
{ 
    // Mark the current node as visited 
    visited[v] = true; 
  
    // Recur for all the vertices adjacent to this vertex 
    list<int>::iterator i; 
    for (i = adj[v].begin(); i != adj[v].end(); ++i) 
    { 
        // If an adjacent is not visited, then recur for that adjacent 
        if (!visited[*i]) 
        { 
           if (isCyclicUtil(*i, visited, v)) 
              return true; 
        } 
  
        // If an adjacent is visited and not parent of current vertex, 
        // then there is a cycle. 
        else if (*i != parent) 
           return true; 
    } 
    return false; 
} */
bool isCyclic() { 
    Graph_Adj();ReInit(); 	
    for(int u = 1; u <= V; u++) {
    	if(visited[u]) {
    		if(DFS(u)) return true;
		}
	}
    return false; 
} 

int main(void){	
	Graph_Adj();ReInit();	
	if(isCyclic()) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}
  
 
