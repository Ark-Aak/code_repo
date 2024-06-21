#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int read(){
	char c=getchar();int x=0;
	while(c<48||c>57) c=getchar();
	do x=(x<<1)+(x<<3)+(c^48),c=getchar();
	while(c>=48&&c<=57);
	return x;
}
const int N=400003,M=460003,INF=0x3f3f3f3f;
int n,m,cnt;
int hd[N],ver[M<<1],nxt[M<<1],tot;
void chmx(int &x,int v){if(x<v) x=v;}
void chmn(int &x,int v){if(x>v) x=v;}
void add(int u,int v){
	nxt[++tot]=hd[u];hd[u]=tot;ver[tot]=v;
}
int p[N],loc;
namespace bipolar{
	int hd[N],ver[M<<1],nxt[M<<1],tot;
	void add(int u,int v){
		cout << u << " -> " << v << endl;
		nxt[++tot]=hd[u];hd[u]=tot;ver[tot]=v;
	}
	int dfn[N],low[N],num;
	vector<int> vec[N];
	int fa[N],deg[N];
	int sink;
	int chain[N],len;
	bool dfs(int u){
		bool fl=(u==sink);
		dfn[u]=low[u]=++num;
		for(int i=hd[u];i;i=nxt[i]){
			int v=ver[i];
			if(dfn[v]) chmn(low[u],dfn[v]);
			else{
				fa[v]=u;
				++deg[u];
				fl|=dfs(v);
				chmn(low[u],low[v]);
			}
		}
		if(fl) chain[++len]=u;
		return fl;
	}
	int que[N],tl;
	bool del[N];
	void proc(int u){
		if(del[u]) return;
		p[++loc]=u;
		del[u]=1;
		for(int x:vec[dfn[u]]) proc(x);
	}
	void orient(int s,int t,int rk){
		sink=t;dfs(s);
		for(int i=1;i<=rk;++i) if(!deg[i]) que[++tl]=i;
		for(int pos=1;pos<=tl;++pos){
			int u=que[pos];
			if(u==t) continue;
			vec[dfn[fa[u]]].emplace_back(u);
			vec[low[u]].emplace_back(u);
			if(!--deg[fa[u]]) que[++tl]=fa[u];
		}
		while(len) proc(chain[len--]);
	}
}
namespace bct{
	const int N=::N<<1;
	int hd[N],ver[N<<1],nxt[N<<1],tot;
	void add(int u,int v){
		nxt[++tot]=hd[u];hd[u]=tot;ver[tot]=v;
		nxt[++tot]=hd[v];hd[v]=tot;ver[tot]=u;
	}
	int sz[N],f[N],sn[N];
	int res,pos,pa,pb;
	void dfs(int u,int fa){
		int a=0,b=0;
		sz[u]=(u<=n);
		for(int i=hd[u];i;i=nxt[i]){
			int v=ver[i];
			if(v==fa) continue;
			dfs(v,u);
			sz[u]+=sz[v];
			if(sz[v]>sz[a]) b=a,a=v;
			else if(sz[v]>sz[b]) b=v;
		}
		int cur=(u<=n),tmp=(u<=n);
		f[u]=f[a];
		sn[u]=a;
		for(int i=hd[u];i;i=nxt[i]){
			int v=ver[i];
			if(v==fa||v==a) continue;
			if(u<=n) tmp+=sz[v];
			else chmx(tmp,sz[v]);
			if(v==b) continue;
			if(u<=n) cur+=sz[v];
			else chmx(cur,sz[v]);
		}
		if(u<=n) cur+=n-sz[u];
		else chmx(cur,n-sz[u]);
		chmx(cur,f[a]);
		chmx(cur,f[b]);
		chmx(f[u],tmp);
		if(cur<=res){res=cur;pos=u;pa=a;pb=b;}
	}
	bool del[N];
	int col[N],rk;
	vector<int> nd[N];
	void paint(int u){
		if(col[u]||del[u]) return;
		col[u]=rk;
		if(u<=n) nd[rk].emplace_back(u);
		for(int i=hd[u];i;i=nxt[i])
			paint(ver[i]);
	}
	void solve(){
		res=INF;pos=0;
		dfs(1,0);
		if(pos>n) del[pos]=1;
		cout << "chain:" << pa << " " << pb << endl;
		int pu=pos,pv=pos;
		for(int i=pa;i;i=sn[i]) if(i>n) del[i]=1;else pu=i;
		for(int i=pb;i;i=sn[i]) if(i>n) del[i]=1;else pv=i;
		for(int i=1;i<=n+cnt;++i) if(!col[i]) ++rk,paint(i);
		for (int i = 1; i <= n; i++) {
			cout << col[i] << " ";
		}
		cout << endl;
		for(int u=1;u<=n;++u)
			for(int i=::hd[u];i;i=::nxt[i]){
				int v=::ver[i];
				if(col[u]!=col[v]) bipolar::add(col[u],col[v]);
			}
		cout << "orient: " << pu << " " << pv << endl;
		bipolar::orient(col[pu],col[pv],rk);
		printf("%d %d\n",res,loc);
		for(int i=1;i<=loc;++i){
			printf("%d ",(int) nd[p[i]].size());
			for(int x:nd[p[i]]) printf("%d ",x);
			putchar('\n');
		}
	}
}
int dfn[N],low[N],num;
int stk[N],tp;
void tarjan(int u){
	dfn[u]=low[u]=++num;stk[++tp]=u;
	for(int i=hd[u];i;i=nxt[i]){
		int v=ver[i];
		if(dfn[v]) chmn(low[u],dfn[v]);
		else{
			tarjan(v);
			chmn(low[u],low[v]);
			if(low[v]>=dfn[u]){
				int x;
				++cnt;
				do{
					x=stk[tp--];
					bct::add(n+cnt,x);
				}while(x!=v);
				bct::add(n+cnt,u);
			}
		}
	}
}
int main(){
	n=read();m=read();
	for(int i=1;i<=m;++i){
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	for(int i=1;i<=n;++i) if(!dfn[i]) tarjan(i),tp=0;
	bct::solve();
	return 0;
}
