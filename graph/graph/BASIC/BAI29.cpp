#include<bits/stdc++.h> 
using namespace std; 
int V, E; //tap dinh va tap canh cua do thi
vector <int> *adj;//danh sach ke cua do thi
void Init(void) {
	fstream fp("EULER.IN");
	fp>>V>>E;//doc so dinh va so canh cua do thi;
	cout<<"So dinh:"<<V<<endl;
	cout<<"So canh:"<<E<<endl;
	adj = new vector<int>[V+1];	
	for(int i=1;i<=E; i++){
		int u, v;//u, v la dinh dau,dinh cuoi cua canh
		fp>>u>>v;
		adj[u].push_back(v);//them v vao ke(u)
		adj[v].push_back(u);//them u vao ke(v)
	}
	fp.close();	
} 
bool isEuler(void){
	int deg_odd=0;
	for(int u=1; u<=V; u++){
		if(adj[u].size()%2) deg_odd++;
	}
	return (deg_odd==0);
}
void Result(void){	
	for(int u=1; u<=V; u++){
		cout<<"Ke ("<<u<<")=";		
		for(int v=0;v<adj[u].size(); v++)
			cout<<adj[u][v]<<" ";
		cout<<endl;
	}	
}
void Euler(int u){
	stack <int> stk, CE; //tao stk, CE la hai stack
	stk.push(u);//dua u vao stk
	while(!stk.empty()){//lap khi nao stack khac rong
		int s = stk.top();//lay s la dinh dau stack		
		if(!adj[s].empty()){//neu ke(s) khac rong
			int t=adj[s][0];//t la dinh dau ke(s)			
			stk.push(t);//dua t vao ngan xep
			adj[s].erase(adj[s].begin());//loai dinh t thuoc ke(s)
			//loai dinh s thuoc ke(t)
			int i;//i la vi tri cua dinh s thuoc ke(t)			
			for( i=0; i<adj[t].size()&& adj[t][i]!=s; i++);
			//cout<<"canh bi loai bo: "<<s<<" "<<t<<endl; cin.get();
			adj[t].erase(adj[t].begin()+i);
		}
		else {//neu ke(s) la rong
			stk.pop(); //dua s ra khoi ngan xep
			CE.push(s);//chuyen s sang CE
		}
	}
	cout<<"Chu trinh Euler:";
	while(!CE.empty()){//lat nguoc cac dinh trong CE
		int s = CE.top();CE.pop();
		cout<<s<<" ";
	}
}
int main(void){
	Init(); Result();
	if(isEuler()) Euler(1);		
}
