//Kiem tra do thi co chu trinh hay khong
//su dung union dua vao danh sach canh
#include<bits/stdc++.h> 
using namespace std; 
int V, E; //tap dinh va tap canh cua do thi
vector <pair < int, int> > edge;//danh sach canh cua do thi
int  *parent;//ghi nhan trang thai chua xet cu dinh
void Graph_Edge(void) { //bieu dien do thi bang danh sach canh
	fstream fp("DOTHI.IN");
	fp>>V>>E;//doc so dinh va so canh cua do thi;
	for(int i=1;i<=E; i++){
		int u, v;  
		pair <int, int> x;//mot canh la pair
		fp>>u>>v; //doc mot canh
		x = make_pair(u,v);//tao mot pair<u,v>		
		edge.push_back(x); //dua vao edge[]
	}
	fp.close();	
}
void ReInit(void){	
	parent = new int[V+1];
	for(int u=0; u<=V; u++) 		
		parent[u]=-1;
}
//Tim tap con cua i 
int find(int parent[], int u){ //tim node goc cua i
    if (parent[u] == -1) //neu goc la -1
        return u; //goc chinh la i
    return find(parent, parent[u]); //de qui de tim ra goc
}   
// Hop them hai dinh x, y 
void Union(int parent[], int x, int y) { 
    int xset = find(parent, x);//goc cua dinh x
    int yset = find(parent, y); //goc cua dinh y
    if(xset!=yset){ //neu hai goc khong giong nhau
       parent[xset] = yset; //goc cua y la x
    } 
}  
//Kiem tra do thi co chu trinh hay khong
int isCycle( void ) { 	
    for(int i = 0; i <E; ++i){ //duyet tren tap canh
        int u= edge[i].first;//dinh dau cua canh
        int v= edge[i].second;//dinh cuoi cua canh
		int x = find(parent, u);//tim dinh goc cua u 
        int y = find(parent, v);//tim dinh goc cua v 
        if (x == y) //neu hai goc trung nhau
            return 1;//ket luan co chu trinh   
        Union(parent, x, y); //hop canh x,y
    } 
    return 0; 
} 
int main(void){
	Graph_Edge();ReInit();
    if (isCycle()) 
        cout<<"YES"<<endl; 
    else
        cout<<"NO"<<endl;     
}

