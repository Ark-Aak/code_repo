#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2005;
int n,t,m;
int a,b;
struct sss {
	int p,q,t;
}e[N];
int ti[N];
map<int,int>w;
int cmp(sss x,sss y) {
	return x.t<=y.t;
}
int main() {
	freopen("seal.in","r",stdin);
	freopen("seal.out","w",stdout);
	cin>>n>>t>>m;
	int cnt=0;
	for(int i=1;i<=n;i++) {
		cin>>a>>b;
		e[++cnt].p=i;
		e[cnt].q =0;
		e[cnt].t = a;
		e[++cnt].p=i;
		e[cnt].q=1;
		e[cnt].t = b;
	}
	sort(e+1,e+n*2+1,cmp);
	e[0].t=0;
	e[n*2+1].t=t;
	for(int i=1;i<=n*2;i++) {
		if(e[i].q==0) {
			if(e[i+1].p==e[i].p) ti[e[i].p]=e[i+1].t-e[i].t;
			else ti[e[i].p]+=e[i+1].t-e[i].t;
		} else {
			if(e[i-1].p==e[i].p) ti[e[i].p]=e[i].t-e[i-1].t;
			else ti[e[i].p]+=e[i].t-e[i-1].t;
		}
	}
	sort(ti+1,ti+n+1);
	for(int i=1;i<=n-m;i++) t-=ti[i];
	cout<<t;
	return 0;
}

