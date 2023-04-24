#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

// https://cachhoc.net/2013/06/11/spojdem-so-chu-so-0123-9-trong-day-so-tu-1-n/

struct ndigit {
    ll d[11];
};
ll p[11];
ndigit f[11];
ndigit g[11];
ll a,b;
void init(void) {
    int i,j;
    p[0]=1;
    for (i=1;i<=9;i++) p[i]=p[i-1]*10;
    for (i=0;i<=9;i++) {
        f[1].d[i]=1;
        g[1].d[i]=1;
        f[0].d[i]=0;
        g[0].d[i]=0;
    }
    for (i=2;i<=9;i++)
        for (j=0;j<=9;j=j+1) f[i].d[j]=10*f[i-1].d[j]+p[i-1];
    for (i=2;i<=9;i++)
        for (j=0;j<=9;j=j+1) g[i].d[j]=g[i-1].d[j]+9*f[i-1].d[j]+p[i-1]*(j>0);
}
int ndgs(ll x) {
    int i=1;
    while (p[i]<=x) i++;
    return (i);
}
ndigit count(ll x) {
    ndigit res;
    if (x<10) {
        int i;
        for (i=0;i<=9;i++) res.d[i]=(i<=x);
        return (res);
    }
    int dig[11];
    int i,j,k;
    int nd=0;
    while (x>0) {
        nd++;
        dig[nd]=x%10;
        x=x/10;
    }
    res=g[nd-1];
    for (i=nd;i>0;i=i-1)
        for (j=(i==nd);j<dig[i]+(i==1);j=j+1) {
            for (k=nd;k>i;k=k-1) res.d[dig[k]]+=p[i-1];
            res.d[j]+=p[i-1];
            for (k=0;k<=9;k=k+1) res.d[k]+=f[i-1].d[k];
        }
    return (res);
}
void process(void) {
    if (a>b) swap(a,b);
    ndigit t1=count(a-1);
    ndigit t2=count(b);
    int i;
    for (i=0;i<9;i++) printf("%lld ",t2.d[i]-t1.d[i]);
    printf("%lld\n",t2.d[9]-t1.d[9]);
}
int main(void) {
    init();
    int t; cin>>t;
    while (t--) {
        cin>>a>>b;
        process();
    }
}