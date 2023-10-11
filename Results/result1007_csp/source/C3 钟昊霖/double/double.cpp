#include<bits/stdc++.h>
using namespace std;

#define int long long 
#define F(i,a,b) for(int i=a;i<=b;i++)
#define mk(a,b) make_pair(a,b)
const int N=5e5+5;

int head[N],nxt[N],to[N],tot,w[N],dis[2005][2005];
bool vis[2005][2005];
inline int read();

inline void AddEdge(int u,int v,int w1) {
	to[++tot]=v;
	nxt[tot]=head[u];
	head[u]=tot;
	w[tot]=w1;
}

inline void Edge(int u,int v,int w) {
	AddEdge(u,v,w),AddEdge(v,u,w);
}

int n,Q;

inline void Dijkstar(int u){
	priority_queue<int,vector<pair<int,int> >,greater<pair<int,int> > > Q;
	dis[u][u]=0;
	Q.push(mk(0,u));
	while(!Q.empty()){
		int t=Q.top().second;
		Q.pop(); 
		if(vis[u][t]) continue;
		else vis[u][t]=1;
		for(int i=head[t];i;i=nxt[i]){
			if(dis[u][to[i]]>dis[u][t]+w[i]){
				dis[u][to[i]]=dis[u][t]+w[i];
				Q.push(mk(dis[u][to[i]],to[i]));
			}
		}
	}
	
}

signed main(){
 	freopen("double.in","r",stdin);
 	freopen("double.out","w",stdout);
	n=read();
	for(int i=1,w1;i<=n;i++){
		w1=read();
		Edge(i*2-1,i*2,w1);
	}
	for(int i=1,x,y,w1,w2;i<n;i++){
		x=read(),y=read(),w1=read(),w2=read();
		Edge(x*2-1,y*2-1,w1),Edge(x*2,y*2,w2);
	} 
	memset(dis,0x7f,sizeof dis);
	F(i,1,n*2) Dijkstar(i); 
	Q=read();
	while(Q--){
		int u=read(),v=read();
		cout<<dis[u][v]<<endl;
	}
	return 0;
}
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f*=-1;
		c=getchar();
	}
	while(c<='9'&&c>='0') {
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x*f;
}
