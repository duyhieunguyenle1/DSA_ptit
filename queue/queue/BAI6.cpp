// BFS: S, T<10000 bat buoc phai dung CTDL
// Chu y xu ly: S<T
#include <iostream>
#define MAX 500000
bool chuaxet[MAX]; 
int S, truoc[MAX], dem=0;
using namespace std;
void Init(void){
	cout<<"\n Nhap S:"; cin>>S;
	for(int i=0;i<MAX; i++){
		chuaxet[i]=true;	
		truoc[i]=0;
	}
}
void BFS(int S){
	int queue[MAX], vao=1,ra=1;
	queue[vao]=S; chuaxet[S]=false;
	while(ra<=vao){
		int s = queue[ra]; ra++;
		cout<<s<< " "; 
		if (s==1) return;
		else {
			if(chuaxet[s-1]){
				vao++; queue[vao]=s-1; 
				truoc[s-1]=s;chuaxet[s-1]=false;
			}
			for(int t=2; t*t<=s; t++){
				if(s%t==0){
					if(chuaxet[s/t]){
						vao++; queue[vao]=s/t; 
						truoc[s/t]=s;chuaxet[s/t]=false;			 	
					}
				}
			}						
		}
	} 		
}
void Result(void){
	int dem=0; cout<<"\n"<<1<<"<-";
	int t = truoc[1];
	while(t!=S){
		dem++; cout<<t<<"<-";
		t = truoc[t];
	}
	cout<<S<<endl;
	cout<<"\n Dem="<<++dem;
	
}
int main (){
  Init();BFS(S);Result();
}
