//Thuat toan DFS: tim duong di tu s den t
//tren do thi vo huong
#include<bits/stdc++.h> 
using namespace std; 
int V, E; //tap dinh va tap canh cua do thi
vector <int> *adj;//danh sach ke cua do thi
bool  *chuaxet;//ghi nhan trang thai chua xet cu dinh
int   *truoc;//ghi nhan cac dinh truoc do 
int   s, t; //dinh bat dau va ket thuc duong di
void Graph_Adj(void) {
	fstream fp("DD1.IN");
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
void DFS(int u) { //thuat toan DFS de qui
	chuaxet[u]=false;//thiet lap u da tham
	for(int v=0; v<adj[u].size(); v++){
		if(chuaxet[adj[u][v]]) {//neu dinh adj[u][v] chua xet
			truoc[adj[u][v]]=u; //ghi nhan truoc[adj[u][v]] la u
			DFS(adj[u][v]);//duyet theo chieu sau tu dinh adj[u][v]
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
	DFS(s);//goi den DFS(s):s la diem bat dau
	Ghi_nhan_duong_di();//dua ra duong di
	
} 
