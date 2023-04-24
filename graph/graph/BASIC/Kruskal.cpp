// thuat toan Kruskal tim MST
#include<bits/stdc++.h> 
using namespace std; 
//dinh nghia mot canh cua du thi
typedef  pair<int, int> iPair;   
// Bieu dien graph bang danh sach canh
int	V, E;//So dinh va so canh cua do thi
vector < pair <int, iPair> > edge; //tap canh cua do thi
int *parent;//luu tru cac node cha cua moi canh
//Doc du lieu tu danh sach canh
void Init(void) {
	fstream fp("MST.IN");
	fp>>V>>E;//doc so dinh va so canh cua do thi;
	cout<<"So dinh:"<<V<<endl;
	cout<<"So canh:"<<E<<endl;	
	parent = new int[V+1];
	for(int i=0; i<=V; i++) 		
		parent[i]=-1;
	for(int i=1;i<=E; i++){
		int u, v, w;  fp>>u>>v>>w;
		pair <int, int> e;e = make_pair(u,v);//doc mot canh
		pair<int, iPair> ew;//canh co trong so canh
		ew.first=w; ew.second = e;		
		edge.push_back(ew); 
	}
	fp.close();	
} 
//Ket qua bieu dien do thi
void Result(void){	
	cout<<"So dinh:"<<V<<endl;
	cout<<"So canh:"<<E<<endl;	
	cout<<"Tap canh cua do thi:"<<endl;
	for(int i=0; i<edge.size(); i++){
		cout<<"Canh "<<i<<":"<<edge[i].second.first;
		cout<<"  "<<edge[i].second.second;
		cout<<"  "<<edge[i].first<<endl;		
	}				
}
//Tim tap con cua i 
int find( int i){ 
    if (parent[i] == -1) 
        return i; 
    return find( parent[i]); 
}   
// Hop hai tap con 
void Union( int x, int y) { 
    int xset = find( x); 
    int yset = find( y); 
    //cout<<"xset = "<<xset<<" yset ="<<yset<<endl;cin.get();
    if(xset!=yset){ 
       parent[xset] = yset; 
    } 
}  
int kruskalMST() { 
    //Buoc 1: khoi tao
	int mst_wt = 0; // Do dai nho nhat cay khung
	int edge_number =0;//so canh cay khung
  	//vecror <pair <int, ipair> > T;//tap canh cay khung
    //Buoc 2: Sap xep    
    sort(edge.begin(), edge.end()); 
  	//Buoc 3: lap
  	cout<<"Tap canh cay khung:"<<endl;
  	for(int i=0; i<edge.size(); i++) {	  	
		int u = edge[i].second.first;
		int v = edge[i].second.second;  	
        int set_u = find(u); 
        int set_v = find(v); 
        if(set_u!=set_v) {        	
			mst_wt += edge[i].first;        	
        	cout<<"Canh :"<<u<<"  "<<v<<"  "<<edge[i].first<<endl;	
        	parent[set_u] = set_v;
        	edge_number++;
		}     
	} 
	if(edge_number<V-1)	return -1;
	return(mst_wt);
}
int main(void){
	Init(); Result();
	cout<<kruskalMST()<<endl;
}
 
