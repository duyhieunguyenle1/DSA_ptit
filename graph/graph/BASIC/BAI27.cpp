#include<bits/stdc++.h> 
using namespace std; 
int V, E; //tap dinh va tap canh cua do thi
vector <int> *adj;//danh sach ke cua do thi
void Init(void) {
	fstream fp("EULER.IN");
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
int  isEuler(void){ //kiem tra do thi la Euler/semi-euler
	int deg_odd=0;//so dinh bac chan
	int deg_eve=0;//so dinh bac le
	for(int u=1; u<=V; u++){
		if(adj[u].size()%2) deg_eve++;//so dinh bac chan
		else deg_odd++;//so dinh bac le
	}
	if (deg_odd==V) //truong hop cac dinh deu co bac chan
		return 1;
	else if (deg_eve==2)//truong hop co hai dinh bac le
		return -1;
	else 
		return 0;
}
void Result(void){	
	for(int u=1; u<=V; u++){
		cout<<"Ke ("<<u<<")=";		
		for(int v=0;v<adj[u].size(); v++)
			cout<<adj[u][v]<<" ";
		cout<<endl;
	}	
}

int main(void){
	Init();Result();
	cout<<isEuler()	<<endl;
}
