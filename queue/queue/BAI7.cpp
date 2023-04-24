// BFS: S, T<10000 bat buoc phai dung CTDL
// Chu y xu ly: S<T
#include <iostream>
#define MAX 500000
bool chuaxet[MAX]; 
int S, T, truoc[MAX], dem=0;
using namespace std;
void Init(void){
	cout<<"\n Nhap S, T:"; cin>>S>>T;
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
		//cout<<s<< " "; 
		if (s==T) return;
		else if (s<T){		 
			if((s-1)>=0 && chuaxet[s-1] && chuaxet[2*s]){
				vao++; queue[vao]=s-1; chuaxet[s-1]=false;truoc[s-1]=s;
				vao++; queue[vao]=2*s;chuaxet[2*s]=false;truoc[2*s]=s;
			}
			else if((s-1)>=0 && chuaxet[s-1] && chuaxet[2*s]==false){
				vao++; queue[vao]=s-1;chuaxet[s-1]=false;truoc[s-1]=s;
			}
			else if((s-1)>=0 && chuaxet[s-1]==false && chuaxet[2*s]){
				vao++; queue[vao]=2*s;chuaxet[2*s]=false;truoc[2*s]=s;
			}
		}
		else {
			if(chuaxet[s-1]==true){
				vao++; queue[vao]=s-1; chuaxet[s-1]=false; truoc[s-1]=s;
			}
			
		}
			
	} 		
}
void Result(void){
	int dem=0; cout<<"\n"<<T<<"<-";
	int t = truoc[T];
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
