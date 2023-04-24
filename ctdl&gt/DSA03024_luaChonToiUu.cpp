#include<bits/stdc++.h>
using namespace std;
typedef struct tgian{
    int start,end;
}tg;

bool cmp(tg a,tg b){
    if(a.end==b.end)return a.start>b.start;
    return a.end<b.end;
}

int res=1;
void Solution(tg a[],int n){
    sort(a,a+n,cmp);
    int now=a[0].end;
    for(int j=1;j<n;j++){
        if(now<=a[j].start){
            res++;
            now=a[j].end;
        }
    }
}

int main(){
    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        tg a[n];
        for(int i=0;i<n;i++){
            cin>>a[i].start>>a[i].end;
        }
        res=1;
        Solution(a,n);
        cout<<res<<endl;
    }
    
}