//Thuat toan BFS: tim duong di tu s den t
//tren do thi vo huong
#include<bits/stdc++.h> 
using namespace std; 
int V, E; //tap dinh va tap canh cua do thi
vector <int> *adj;//danh sach ke cua do thi
bool  *chuaxet;//ghi nhan trang thai chua xet cu dinh
int   *truoc;//ghi nhan cac dinh truoc do 
int   s, t; //dinh bat dau va ket thuc duong di
void Graph_Adj(void) {
	fstream fp("DUONGDI.IN");
	fp>>V>>E>>s>>t;//doc so dinh va so canh cua do thi;
	adj = new vector<int>[V+1];
	for(int i=1;i<=E; i++){
		int u, v;//u, v la dinh dau,dinh cuoi cua canh
		fp>>u>>v;
		adj[u].push_back(v);//them v vao ke(u)
		adj[v].push_back(u);//them u vao ke(v)
	}
	fp.close();	
}
void ReInit(void){	//thiet lap chuaxet[u]=true
	chuaxet = new bool[V+1];
	truoc = new int[V+1];
	for(int u=0; u<=V; u++) {		
		chuaxet[u]=true;
		truoc[u]=0;
	}
}
void BFS(int u) { //thuat toan BFS
	queue <int> q; q.push(u); //dua u vao hang doi
	chuaxet[u]=false;//thiet lap u da tham
	while(!q.empty()){//lap khi nao queue rong
		int s=q.front();//lay dinh vao truoc cua queue
		q.pop(); //xoa dinh truoc khoi hang doi
		for(int t=0; t<adj[s].size(); t++){ //duyet tren ke(s)
			if(chuaxet[adj[s][t]]) {//neu dinh adj[s][t] chua xet
				q.push(adj[s][t]);//dua adj[s][t] vao hang doi
				truoc[adj[s][t]] = s; //ghi nhan truoc[adj[s][t] la s
				chuaxet[adj[s][t]] = false;
			}
		}
	}
} 
void Ghi_nhan_duong_di(void){	
	if(truoc[t]==0) {//neu khong ton tai duong di
		cout<<"-1"<<endl;return;	
	}
	stack <int> st; //tao stack ghi nhan cac dinh
	st.push(t);//t se la dinh dau tien	
	int u= truoc[t];//u la dinh truoc cua t
	while(u!=s) { //lap den khi duoc dinh u		
		st.push(u);//dua t vao ngan xep
		u = truoc[u];//lai den dinh truoc cua t
	}	
	cout<<"Duong di:"<<s;
	while(!st.empty()){ //lap khi nao stack rong
		int x = st.top();//lay dinh dau tien
		st.pop(); //loai dinh dau ngan xep
		cout<<"-> "<<x;
	}
	cout<<endl;
}
// chuong trinh chinh 
int main() { 
	Graph_Adj();//bieu dien do thi bang adj	
	ReInit(); //thiet lap chuaxet[u], truoc[u]
	BFS(s);//goi den DFS(s):s la diem bat dau
	Ghi_nhan_duong_di();//dua ra duong di
	
} 
