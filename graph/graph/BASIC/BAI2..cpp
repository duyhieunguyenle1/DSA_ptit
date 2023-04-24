//Bieu dien do thi bang danh sach canh bang STL
#include<bits/stdc++.h> 
using namespace std; 
int V, E; //tap dinh va tap canh cua do thi
vector <int> *adj;//danh sach ke cua do thi
void Init(void) {	
	cin>>V>>E;//doc so dinh va so canh cua do thi;
	adj = new vector<int>[V+1];
	for(int i=0;i<E; i++){
		int u, v;//u, v la dinh dau,dinh cuoi cua canh
		cin>>u>>v;
		adj[u].push_back(v);//them v vao ke(u)
		//adj[v].push_back(u);//them u vao ke(v)
	}
	for(int u=0; u<V; u++){
		cout<<u;		
		for(int v=0;v<adj[u].size(); v++)
			cout<<"-> "<<adj[u][v];
		cout<<endl;
	}		
}
// chuong trinh chinh 
int main() { 
	int T; cin>>T;
	while(T--){
		Init();//
	}
} 
