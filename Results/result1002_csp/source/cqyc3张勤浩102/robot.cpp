#include <bits/stdc++.h>
#define ll long long
using namespace std;

namespace IO{
	template<typename T>
	inline void qread(T &x){
		x=0;char ch;bool f=0;
		while((ch=getchar())&&(ch>'9'||ch<'0')) if(ch=='-') f=1;x=(ch^48);
		while((ch=getchar())&&(ch<='9'&&ch>='0')) x=(x<<1)+(x<<3)+(ch^48);
		x=f?-x:x;
	}
	template<typename T>
	inline void write(T x){
		if(x<0) putchar('-'),x=-x;
		if(x>9) write(x/10);
		putchar(x%10+'0');
	}
}
using namespace IO;

const int Maxn=1e5;
int T,n,m,p[Maxn],q[Maxn];
int prs[Maxn],qrs[Maxn];
vector<int>e[Maxn];

vector<int>ve[Maxn];

short flg[Maxn];

inline bool toposort(int u){
	flg[u]=-1;
	for(auto v:ve[u]){
		if(flg[v]==-1) return 0;
		if(!flg[v]){
			if(!toposort(v)) return 0;
		}
	}
	flg[u]=1;
	return 1;
}

int dep[Maxn],fa[Maxn];

void DFS(int u,int ft){
	dep[u]=dep[ft]+1;
	fa[u]=ft;
	for(auto v:e[u])if(v!=ft) DFS(v,u);
}

inline void LCA(int u,int v,int id){
	if(prs[v]&&prs[v]!=id) ve[prs[v]].push_back(id);
	if(qrs[u]&&qrs[u]!=id) ve[id].push_back(qrs[u]);
	if(dep[u]<dep[v]) swap(u,v);
	while(dep[u]>dep[v]){
		u=fa[u];
		if(u!=v){
			if(prs[u]&&prs[u]!=id) ve[prs[u]].push_back(id);
			if(qrs[u]&&qrs[u]!=id) ve[id].push_back(qrs[u]);
		}
	}
	if(u==v){
		return ;
	}
	while(u!=v){
		u=fa[u];
		v=fa[v];
		if(u!=v){
			if(prs[u]&&prs[u]!=id) ve[prs[u]].push_back(id);
			if(prs[v]&&prs[v]!=id) ve[prs[v]].push_back(id);
			if(qrs[u]&&qrs[u]!=id) ve[id].push_back(qrs[u]);
			if(qrs[v]&&qrs[v]!=id) ve[id].push_back(qrs[v]);
		}
	}
	if(prs[u]&&prs[u]!=id) ve[prs[u]].push_back(id);
	if(qrs[u]&&qrs[u]!=id) ve[id].push_back(qrs[u]);
	return ;
}

int main(){
	freopen("robot.in","r",stdin);
	freopen("robot.out","w",stdout);
	qread(T);
	while(T--){
		qread(n);
		for(int i=1,u,v;i<n;i++){
			qread(u),qread(v);
			e[u].push_back(v);
			e[v].push_back(u);
		}
		DFS(1,0);
		qread(m);
		for(int i=1;i<=m;i++){
			qread(p[i]),qread(q[i]);
			prs[p[i]]=i,qrs[q[i]]=i;
		}
		for(int i=1;i<=m;i++){
			LCA(p[i],q[i],i);
		}
//		cout<<"test\n";
//		for(int i=1;i<=m;i++){
//			
//			cout<<i<<": ";
//			for(auto v:ve[i])cout<<v<<' ';
//			cout<<endl;
//		}
		bool alflg=1;
		memset(flg,0,sizeof flg);
		for(int i=1;i<=m;i++){
			alflg&=toposort(i);
		}
		for(int i=1;i<=m;i++) prs[p[i]]=qrs[q[i]]=0,ve[i].resize(0);
		for(int i=1;i<=n;i++) e[i].resize(0);
		if(alflg) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

/*
1
10
1 2
1 3
2 4
3 5
5 6
2 7
1 8
4 9
3 10
2
9 2
2 4

2
6
1 2
1 3
2 4
2 5
2 6
2
2 1
6 3
5
1 2
2 3
3 4
4 5
2
1 3
2 5

2
9
1 2
1 3
2 4
2 5
5 6
5 7
7 8
8 9
3
5 6
4 2
9 3
4
1 2
2 3
3 4
2
1 3
4 2

*/
