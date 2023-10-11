#include<bits/stdc++.h>
using namespace std;

#define F(i,a,b) for(int i=a;i<=b;i++)

inline int read();

const int N=1e6+5,M=5e5+5;

int head[M],nxt[M],to[M],w[M],tot,fkc;

inline void AddEdge(int u,int v,int w1) {
	to[++tot]=v;
	nxt[tot]=head[u];
	head[u]=tot;
	w[tot]=w1;
}

inline void Edge(int u,int v,int w) {
	AddEdge(u,v,w),AddEdge(v,u,w);
}

struct node {
	int l,r,s,t;
} Q[N];

int n,m,q;

bool falg;

inline void Check(int l,int r,int s,int t){
	if(l>r+1) return; 
	if(falg) return;
	if(s==t) {
		if(l<=r+1) falg=true;
		return;
	}
	for(int i=head[s];i;i=nxt[i]){
		if(w[i]>=l) Check(l+1,r,to[i],t);
		if(falg) return;
	}
}

inline void Subtask1() {
	falg=false;
	F(i,1,q) {
		Q[i].l=read(),Q[i].r=read(),Q[i].s=read(),Q[i].t=read();
		falg=false;
		Check(Q[i].l,Q[i].r,Q[i].s,Q[i].t);
		if(falg) printf("Yes \n");
		else printf("No \n");
	}
}


signed main() {
	freopen("journey.in","r",stdin);
	freopen("journey.out","w",stdout);
	n=read(),m=read(),q=read();
	for(int i=1,u,v; i<=m; i++) {
		u=read(),v=read();
		if(u==1) fkc++; 
		Edge(u,v,i);
	}
	Subtask1();
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
