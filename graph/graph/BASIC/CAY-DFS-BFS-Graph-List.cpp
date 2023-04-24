#include<iostream>
#include <list>
#include <fstream>
#include <iomanip>
#include <stack>
using namespace std;
struct canh{
	int dau;
	int cuoi;
};
class Graph{
private:
    int V;    // so luong dinh
    list<int> *adj;    // con tro den mang cac danh sach ke
    bool *chuaxet;
    canh *T;//tap canh cua cay khung
	int sc; //so canh cay khung
public:
    Graph(int V);  // constructor cua lop
    void addEdge(int v, int w); // them mot canh vao do thi
    void printGraph();//in bieu dien danh sach ke
    void Tree_BFS(int u);//thuat toan BFS
    void Tree_DFS(int u);//thuat toan DFS dua vao stack
};
Graph::Graph(int V){
    this->V = V;//thiet lap tap dinh
    adj = new list<int>[V];//thiet lap mang V phan tu moi phan tu la mot list
	T 	= new canh[V]; sc =1; //thiet lap so canh cay khung
    chuaxet = new bool[V];//thiet lap mang chua xet
    for(int u=0; u<V; u++)
    	chuaxet[u]=true;    
}
void Graph::addEdge(int v, int w){
    adj[v].push_back(w); // them w vao list v.
    adj[w].push_back(v); // them v vao list w.
}
void Graph::Tree_BFS(int u){//thuat toan BFS
    list<int> queue;//tao hang doi cho BFS
	//Buoc khoi tao:
    queue.push_back(u);//dua u vao hang doi
 	chuaxet[u] = false;//thiet lap trang thai s
    // 't' dung de nhan tat ca cac dinh ke cua dinh s
    list<int>::iterator t;
    //Buoc lap:
    cout<<"\n Ket qua duyet BFS:";
    while(!queue.empty()){//lap den khi hang doi rong
        int s = queue.front();//lay dinh s o dau hang doi
        cout << s << " ";//tham s
        queue.pop_front();//loai s khoi hang doi
        for(t = adj[s].begin(); t != adj[s].end(); ++t){//duyet tren list(s)
            if(chuaxet[*t]){//neu dinh t chua xet
                queue.push_back(*t);//dua t vao hang doi
                chuaxet[*t] = false;//xac nan t da xet
                T[sc].dau = s;
				T[sc].cuoi = *t;
				sc++;
            }
        }
    }
    if (sc<V-1){
    	cout<<"Do thi khong lien thong"<<endl;
	}
	else {
		cout<<"\n Tap canh cay khung:"<<endl;
		for(int i=1; i<sc; i++){
			cout<<T[i].dau<<setw(3)<<T[i].cuoi<<endl;
		}
	} 
}
void Graph::Tree_DFS(int u){
    stack <int> Stack;
	Stack.push(u);
    cout << u <<setw(3);
    chuaxet[u] = false;
    list<int>::iterator t;
    while(!Stack.empty()){
    	int s = Stack.top();Stack.pop();
    	for (t = adj[s].begin(); t != adj[s].end(); ++t){
    		if(chuaxet[*t]){
    			cout << *t <<setw(3);
    			Stack.push(s);
    			Stack.push(*t);
    			chuaxet[*t]=false;
    			T[sc].dau = s;
    			T[sc].cuoi = *t;
    			sc++;
    			break;
			}
		}
	}
	if(sc<V-1){
		cout<<"\n Do thi khong lien thong";
	}
	else {
		cout<<"\n Tap canh cay khung:"<<endl;
		for(int i=1; i<sc; i++){
			cout<<T[i].dau<<setw(3)<<T[i].cuoi<<endl;
		}
	}
}
void Graph::printGraph(){
    list<int>::iterator v;
    cout<<"\n So dinh do thi:"<<V-1;    
    for (int u = 1; u < V; ++u){
        printf("\n List(%d):",u);
        for(v=adj[u].begin(); v != adj[u].end(); ++v)
        	cout<<"-> "<<*v;
		cout<<endl;				  
    }
}

int main(void){
 	ifstream fp("Graph.in"); 
	int n, m, dau, cuoi;
	fp>>n>>m;//doc so dinh va so canh cua do thi
	Graph gh(n+1);//thiet lap do thi gom n dinh
	for(int i=1; i<=m; i++){//chuyen do thi thanh danh sach ke
		fp>>dau>>cuoi;
		gh.addEdge(dau, cuoi);
	}
	fp.close();
	gh.printGraph();	
	gh.Tree_BFS(1);
	//gh.Tree_DFS(1);
}
