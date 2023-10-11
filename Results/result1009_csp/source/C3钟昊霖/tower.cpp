#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=b;i++)
#define mk(a,b) make_pair(a,b)
const int N=5e5+5;

int head[N],nxt[N],tot,to[N];
char s[N];
int a[N],n,k;
int dis[N];
bool vis[N];
vector<int> _to[N];
inline void AddEdge(int u,int v) {
	to[++tot]=v;
	nxt[tot]=head[u];
	head[u]=tot;
}
//+n inpoint +2*n outpoint
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >Q;
inline void Calc(int t,int v,int u) {
//	cout<<u<<endl;
	if(u==4) return;
	for(int i=head[v]; i; i=nxt[i]) {
		if(to[i]<=n) {
			if(dis[to[i]]>dis[t]+abs(t-to[i])) {
				dis[to[i]]=dis[t]+abs(t-to[i]);
				Q.push(mk(dis[to[i]],to[i]));
			}
			continue;
		}
		else if(to[i]!=u) Calc(t,to[i],u+1);
	}
	return;
}

inline void Dijkstar() {
	memset(dis,0x7f,sizeof dis);
	dis[1]=0;
	Q.push(mk(0,1));
	while(!Q.empty()) {
		int t=Q.top().second;
		Q.pop();
		if(vis[t]) continue;
		vis[t]=1;
		for(int i=head[t]; i; i=nxt[i]) {
			if(to[i]<=n) {
				if(dis[to[i]]>dis[t]+abs(t-to[i])) {
					dis[to[i]]=dis[t]+abs(t-to[i]);
					Q.push(mk(dis[to[i]],to[i]));
				}
				continue;
			} else {
				Calc(t,to[i],0);
			}
		}
	}
}

signed main() {
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	cin>>n>>k;
	//	cout<<1<<endl;

	F(i,1,n) {
		cin>>a[i];
		_to[a[i]].push_back(i);
		AddEdge(a[i]+n,i);
		AddEdge(i,a[i]+2*n);
	}
	F(i,1,k) {
		scanf("%s",s+1);
		F(j,1,k) {
			if(s[j]=='0') continue;
			if(j==i) {
				F(kk,0,_to[i].size()-1) AddEdge(_to[i][kk],i+n);
			} else {
				AddEdge(i+2*n,j+n);
			}
		}
	}
//	cout<<1<<endl;
	Dijkstar();
	//F(i,1,n) cout<<dis[i]<<endl;
	if(dis[n]<dis[0])cout<<dis[n];
	else cout<<-1;
	return 0;
}
