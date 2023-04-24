//Kiem tra do thi co chu trinh hay khong
#include<bits/stdc++.h> 
using namespace std; 
int V, E; //tap dinh va tap canh cua do thi
vector <pair < int, int> > edge;//danh sach ke cua do thi
int  *parent;//ghi nhan trang thai chua xet cu dinh
void Init(void) {
	fstream fp("DOTHI.IN");
	fp>>V>>E;//doc so dinh va so canh cua do thi;
	cout<<"So dinh:"<<V<<endl;
	cout<<"So canh:"<<E<<endl;	
	parent = new int[V+1];
	for(int i=0; i<=V; i++) 		
		parent[i]=-1;
	for(int i=1;i<=E; i++){
		int u, v;  pair <int, int> x;//doc mot canh
		fp>>u>>v; x = make_pair(u,v);		
		edge.push_back(x); 
	}
	fp.close();	
}
void Result(void){	
	for(int i=0; i<edge.size(); i++){
		cout<<"Canh "<<i<<":"<<edge[i].first;
		cout<<"  "<<edge[i].second<<endl;
	}				
}
//Tim tap con cua i 
int find(int parent[], int i){ 
    if (parent[i] == -1) 
        return i; 
    return find(parent, parent[i]); 
}   
// Hop hai tap con 
void Union(int parent[], int x, int y) { 
    int xset = find(parent, x); 
    int yset = find(parent, y); 
    cout<<"xset = "<<xset<<" yset ="<<yset<<endl;cin.get();
    if(xset!=yset){ 
       parent[xset] = yset; 
    } 
}  
//Kiem tra do thi co chu trinh hay khong
int isCycle( void ) { 	
    for(int i = 0; i <E; ++i){ 
        int x = find(parent, edge[i].first); 
        int y = find(parent, edge[i].second); 
		cout<<"x = "<<x<<" y = "<<y<<endl;          
        if (x == y) 
            return 1;   
        Union(parent, x, y); 
    } 
    return 0; 
} 
int main(void){
	Init();Result();
    if (isCycle()) 
        printf( "Do thi co chu trinh" ); 
    else
        printf( "Do thi khong co chu trinh" );     
}

