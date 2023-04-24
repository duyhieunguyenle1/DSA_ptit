#include<bits/stdc++.h> 
using namespace std; 
int V, E; //tap dinh va tap canh cua do thi
vector <int> *adj;//danh sach ke cua do thi
int 	*neg_deg;
void Init(void) {
	fstream fp("EULER.IN");
	fp>>V>>E;//doc so dinh va so canh cua do thi;
	adj = new vector<int>[V+1];	
	neg_deg = new int[V+1];
	for(int i=0; i<=V; i++) neg_deg[i]=0;
	for(int i=1;i<=E; i++){
		int u, v;//u, v la dinh dau,dinh cuoi cua canh
		fp>>u>>v;
		adj[u].push_back(v);//them v vao ke(u)
		neg_deg[v]++;//ghi nha ban bac vao cua v		
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
int isEuler(void){	
	int s=0, t=0, d=0;
	for(int u=1; u<=V; u++){
		int pos_deg=adj[u].size();
		if(pos_deg==neg_deg[u]) d++;
		else if(pos_deg-neg_deg[u]==1) s++;
		else if(neg_deg[u]-pos_deg==1) t++;			
	}	
	if(d==V) return 1;
	else if(s==1 && t==1) return -1;
	else return 0;
}
int main(void){
	Init(); Result();
	cout<<isEuler()<<endl;		
}
