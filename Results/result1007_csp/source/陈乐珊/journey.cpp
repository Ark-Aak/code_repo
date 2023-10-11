#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1005;
int n,m,q;
vector < pair<int,int> > w[N];
bool p[N];
int ans;
int l,r,s,t;
void ooo(int now,int ti) {
	if(ti>=ans) return ;
	if(ti>r) return ;
	if(p[now]) return ;
	p[now]=1;
	if(p[t]) return ;
	for(int i=0;i<w[now].size();i++) {
		if(w[now][i].first<ti) continue;
		ooo(w[now][i].second,w[now][i].first);
		if(p[t]) return ;
	}
	if(p[t]) return ;
	p[now]=0;
}
int main() {
	freopen("journey.in","r",stdin);
	freopen("journey.out","w",stdout);
	cin>>n>>m>>q;
	int u,v;
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&u,&v);
		pair<int,int> x;
		x.first=i;
		x.second=v;
		w[u].push_back(x);
		x.second=u;
		w[v].push_back(x);
	}
	while(q--) {
		scanf("%d%d%d%d",&l,&r,&s,&t);
		memset(p,0,sizeof(p));
		ans=1e9;
		ooo(s,l);
		if(p[t]) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}

