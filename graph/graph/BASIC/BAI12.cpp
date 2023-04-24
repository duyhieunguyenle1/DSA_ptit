// Kiem tra chu trinh tren do thi co huong
#include<iostream> 
#include <list> 
#include <vector>
#include <fstream>
#include <limits.h>   
using namespace std;  
int V, E;
bool *visited, *rs;
vector <int> *adj;
void Init(void) {
	fstream fp("DOTHI1.IN");
	fp>>V>>E;//doc so dinh va so canh cua do thi;
	adj = new vector<int>[V+1];	//cap phat mien nho cho adj
	visited = new bool[V+1];//cap phat mien nho cho visited
	rs = new bool[V+1];//cap phat mien nho cho rs
	for(int i=0; i<=V; i++) { //thiet lap true
		visited[i]=false;
		rs[i]=false;
	}
	for(int i=1;i<=E; i++){
		int u, v;fp>>u>>v;//doc canh u, v		
		adj[u].push_back(v);//them v vao ke(u)		
	}
	fp.close();	
} 
void Result(void){	
	cout<<"So dinh:"<<V<<endl;
	cout<<"So canh:"<<E<<endl;
	for(int u=1; u<=V; u++){
		cout<<"Ke ("<<u<<")=";		
		for(int v=0;v<adj[u].size(); v++)
			cout<<adj[u][v]<<" ";
		cout<<endl;
	}	
}
bool DFS(int v) { 
    if(visited[v] == false){ 
        // Mark the current node as visited and part of recursion stack 
        visited[v] = true;//danh dau da duyet 
        rs[v] = true;//danh dau da duyet   
        //de qui tai dinh chua duyet
       int i; 
        for(i = 0; i <adj[v].size(); i++) { 
            if ( !visited[i] && DFS(i) ) 
                return true; 
            else if (rs[i]) 
                return true; 
        }   
    } 
    rs[v] = false;  // bo dinh v khoi rec[]
    return false; 
} 
bool isCyclic(void) { 
    // DFS trees 
    for(int u = 1; u <= V; u++) 
        if (DFS(u) )
            return true;   
    return false; 
} 

int main() { 
	Init();
	if(isCyclic()) {
		cout<<"Co chu trinh";
	}
	else {
		cout<<"Khong co chu trinh";
	}
} 
