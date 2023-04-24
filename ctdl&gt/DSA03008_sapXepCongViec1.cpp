#include<bits/stdc++.h>
using namespace std;

int res=0;

typedef struct time{
    int start,end;
}tg;

bool cmp(tg a,tg b){
    return a.end<b.end;
}
void Solution(tg a[],int n){
    sort(a,a+n,cmp);
    res++;

    int i=0;
    for(int j=1;j<n;j++){
        if(a[j].start>=a[i].end){
            res++;
            i=j;
        }
    }
}

int main(){
    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        tg a[n];
        for(int i=0;i<n;i++)cin>>a[i].start;
        for(int i=0;i<n;i++)cin>>a[i].end;

        // reset res
        res=0;
        Solution(a,n);
        cout<<res<<endl;
    }
}