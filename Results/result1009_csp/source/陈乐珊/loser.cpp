#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
int n,q,d[N];
vector<int> m[N];
int f[N],dep[N];
void dfs(int now,int fa) {
	f[now]=fa;
	dep[now]=dep[fa]+1;
	for(int i=0;i<m[now].size();i++) {
		int to=m[now][i];
		if(to==fa) continue;
		dfs(to,now) ;
	}
}
void f1(int x,int y) {
	if(dep[x]<dep[y]) swap(x,y);
	while(dep[x]>dep[y]) {
		d[x]=-d[x];
		x=f[x];
	}
	while(x!=y) {
		d[x]=-d[x];
		d[y]=-d[y];
		x=f[x];
		y=f[y];
	}
	d[x]=-d[x];
}
int mm[N],nn[N],p[N],r;
int f2(int x,int y) {
	int cnt=0,e=0;
	if(dep[x]<dep[y]) swap(x,y),e=1;
	while(dep[x]>dep[y]) {
		mm[++cnt]=d[x];
		x=f[x];
	}
	int cnt2=0;
	while(x!=y) {
		mm[++cnt]=d[x];
		nn[++cnt2]=d[y];
		x=f[x];
		y=f[y];
	}
	mm[++cnt]=d[x];
	for(int i=cnt2;i>=1;i--) mm[++cnt]=nn[i];
	if(e==1) reverse(mm+1,mm+cnt+1);
	r=0;
	int ret=0;
	for(int i=1;i<=cnt;i++) {
		if(mm[p[r]]==-1&&mm[i]==1) {
			r--;
		} else {
			p[++r]=i;
		}
	}
	p[++r]=cnt;
	for(int i=1;i<=r;i++) ret=max(ret,p[i]-p[i-1]-1);
	return ret ;
}
int main() {
	freopen("loser.in", "r", stdin);
	freopen("loser.out", "w", stdout);
	cin>>n>>q;
	int u,v;
	for(int i=1;i<n;i++) {
		cin>>u>>v;
		m[u].push_back(v);
		m[v].push_back(u);
	}
	for(int i=1;i<=n;i++) {
		cin>>d[i];
		if(d[i]==0) {
			d[i]=-1;
		} else {
			d[i]=1;
		}
	}
	dfs(1,0);
	int opt,x,y;
	while(q--) {
		cin>>opt>>x>>y;
		if(opt==1) {
			f1(x,y);
		} else {
			cout<<f2(x,y)<<"\n";
		}
	}
	return 0;
}

