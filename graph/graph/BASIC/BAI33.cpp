// bieu dien do thi trong so bang adj
#include<bits/stdc++.h> 
using namespace std; 
//dinh nghia mot canh cua du thi
typedef  pair<int, int> iPair;   
// Bieu dien graph bang danh sach canh
int	V, E;//So dinh va so canh cua do thi
vector < pair <int, iPair> > edge; //tap canh cua do thi
//Doc du lieu tu danh sach canh
void Init(void) {
	fstream fp("MST.IN");
	fp>>V>>E;//doc so dinh va so canh cua do thi;
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
		cout<<"Canh "<<i+1<<":"<<edge[i].second.first;
		cout<<"  "<<edge[i].second.second;
		cout<<"  "<<edge[i].first<<endl;		
	}				
}
int main(void){
	Init(); Result();
}
 
