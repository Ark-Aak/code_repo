#include<bits/stdc++.h>
using namespace std;
const int N=300005,LN=18;
int n,w[N],lg[N],df[N],ans[N],st[LN+3][N];
int up[N][LN+3],ps[N],siz[N],dep[N];
int fa[N][LN+3],ch[N][2],hson[N];
int ml[N],len[N],dot[N],dfn[N],lst[N],idx;
vector<int> pos[N];
inline int read(){
	int x=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9')
		x=(x<<3)+(x<<1)+(c^48), c=getchar();
	return x;
}
struct Opt{
	int u,v,w;
	Opt(int _u=0,int _v=0,int _w=0){ u=_u, v=_v, w=_w; }
};
inline bool cmp(Opt a,Opt b){
	return a.w<b.w;
}
struct Pro{
	Opt opt[N*3];
	int ans[N],df[N],cnt;
	inline void Insert(Opt o){ opt[++cnt]=o; }
	inline int Find(int u){
		return df[u]==u?u:df[u]=Find(df[u]);
	}
	inline void Modify(Opt o){
		for(register int i=Find(o.u);dep[i]>dep[o.v];)
			ans[i]=o.w, df[i]=Find(fa[i][0]), i=df[i];
	}
	inline void Solve(){
		sort(opt+1,opt+1+cnt,cmp);
		memset(ans,0x3f,sizeof(ans));
		for(register int i=1;i<=n;++i) df[i]=i;
		for(register int i=1;i<=cnt;++i) Modify(opt[i]);
	}
}pro;
namespace Case1{
	int ans[N],nxt[N],lst[N],cnt[N];
	inline void Modify(int c,int op){
		cnt[c]+=op;
		if(op==1&&cnt[c]==1) nxt[lst[c]]=nxt[c], lst[nxt[c]]=lst[c];
		if(op==-1) nxt[c-1]=c, lst[c]=c-1, nxt[c]=c+1, lst[c+1]=c;
	}
	inline void mdf(int u,int op){
		Modify(w[u]+1,op);
		for(register int i=0;i<2;++i) if(ch[u][i]) mdf(ch[u][i],op);
	}
	inline void dfs(int u){
		int v=ch[u][hson[u]==ch[u][0]];
		if(v) dfs(v), mdf(v,-1);
		if(hson[u]) dfs(hson[u]);
		if(v) mdf(v,1);
		Modify(w[u]+1,1), ans[u]=len[u]-(nxt[0]-1);
	}
	inline void Work(){
		for(register int i=0;i<=n+1;++i) nxt[i]=i+1, lst[i+1]=i;
		dfs(1);
	}
}
inline int Ask(int l,int r){
	if(l>r) return 0; int k=lg[r-l+1];
	return max(st[k][l],st[k][r-(1<<k)+1]);
}
inline int LCA(int u,int v){
	if(dep[u]<dep[v]) swap(u,v);
	for(register int i=dep[u]-dep[v];i;i-=i&-i)
		u=fa[u][lg[i&-i]];
	if(u==v) return u;
	for(register int i=LN;i>=0;--i)
		if(fa[u][i]!=fa[v][i]) u=fa[u][i], v=fa[v][i];
	return fa[u][0];
}
inline int Next(int u,int x){
	for(register int i=LN;i>=0;--i)
		if(up[u][i]<=x) u=fa[u][i];
	return u;
}
inline int Find(int u){
	return df[u]==u?u:df[u]=Find(df[u]);
}
namespace Case2{
	int ans[N],wc[N][2],mex,ecnt;
	int rcd[N],md[N],stk[N],tot;
	bool sp[N];
	inline void add(int u,int v){
		int x=ch[u][1]; x=(dfn[x]<=dfn[v]&&dfn[v]<=lst[x]);
		wc[u][x]=v, rcd[++rcd[0]]=u, rcd[++rcd[0]]=v;
	}
	inline void Insert(int u){
		if(u==stk[tot]) return;
		int lca=LCA(u,stk[tot]);
		if(!tot||lca==stk[tot]) return void(stk[++tot]=u);
		while(tot>1&&dep[stk[tot-1]]>dep[lca])
			add(stk[tot-1],stk[tot]), --tot;
		add(lca,stk[tot]), --tot;
		if(stk[tot]!=lca) stk[++tot]=lca;
		if(u!=lca) stk[++tot]=u;
	}
	inline void Modify(int u,int v,int c){
		int p=Next(u,md[u]);
		if(dep[p]-1<=dep[v]){
			return void(pro.Insert(Opt(u,ch[v][c],mex-md[u])));
		}
		pro.Insert(Opt(u,fa[p][0],mex-md[u])), p=Find(p);
		while(dep[ps[p]]-1>dep[v])
			pro.Insert(Opt(fa[p][0],fa[ps[p]][0],mex-up[p][0])), p=Find(ps[p]);
		if(dep[p]-1>dep[v])
			pro.Insert(Opt(fa[p][0],ch[v][c],mex-up[p][0]));
	}
	inline void dfs(int u){
		int s[2]={dep[u],dep[u]};
		for(register int i=0;i<2;++i){
			int v=wc[u][i],cv=ch[u][i];
			if(!v) s[i]=max(s[i],Ask(dfn[cv],lst[cv]));
			else{
				int ld=Ask(dfn[cv],dfn[v]-1),rd=Ask(lst[v]+1,lst[cv]);
				dfs(v), s[i]=max(max(s[i],md[v]),max(ld,rd)), Modify(v,u,i);
			}                                                                                         
		}
		if(sp[u]) md[u]=dep[u]-1;
		else{
			md[u]=max(s[0],s[1]);
			ans[u]=max(ans[u],s[0]+s[1]-dep[u]*2+1-mex);
		}
	}
	inline void Solve(){
		rcd[0]=tot=ecnt=0, Insert(1), rcd[++rcd[0]]=1;
		for(auto u:pos[mex]) sp[u]=true, Insert(u);
		Insert(1), dfs(1);
		for(register int i=1,u;u=rcd[i],i<=rcd[0];++i)
			wc[u][0]=wc[u][1]=md[u]=sp[u]=0;
	}
	inline void Work(){
		for(mex=0;mex<n;++mex) Solve();
	}
}
inline void dfs(int u){
	pos[w[u]].push_back(u), dfn[u]=++idx, dot[idx]=u;
	siz[u]=1, ml[u]=dep[u]=st[0][idx]=dep[fa[u][0]]+1;
	for(register int i=0;i<2;++i){
		int v=ch[u][i]; if(!v) continue;
		dfs(v), siz[u]+=siz[v], ml[u]=max(ml[u],ml[v]);
		if(siz[v]>siz[hson[u]]) hson[u]=v;
	}
	int ls=ch[u][0],rs=ch[u][1];
	up[ls][0]=max(dep[u],ml[rs]), up[rs][0]=max(dep[u],ml[ls]);
	len[u]=up[ls][0]+up[rs][0]-dep[u]*2+1, lst[u]=idx;
}
inline void Init(){
	for(register int i=2;i<=n;++i) lg[i]=lg[i>>1]+1;
	for(register int i=1;i<=LN;++i)
		for(register int j=1;j<=n;++j){
			fa[j][i]=fa[fa[j][i-1]][i-1];
			up[j][i]=max(up[j][i-1],up[fa[j][i-1]][i-1]);
			if(j+(1<<i)-1<=n)
				st[i][j]=max(st[i-1][j],st[i-1][j+(1<<i-1)]);
		}
	for(register int i=2;i<=n;++i) ps[i]=Next(i,up[i][0]);
	for(register int i=1;i<=n;++i) df[i]=i;
}
int main(){
	freopen("mex.in","r",stdin);
	freopen("mex.out","w",stdout);
	n=read();
	for(register int i=1;i<=n;++i) w[i]=read();
	for(register int i=2,f;i<=n;++i)
		f=fa[i][0]=read(), ch[f][ch[f][0]>0]=i;
	up[1][0]=n+1, dfs(1), Init();
	Case1::Work(), Case2::Work(), pro.Solve();
	for(register int i=1;i<=n;++i)
		ans[i]=max(Case1::ans[i],Case2::ans[i]);
	for(register int i=2,f;f=fa[i][0],i<=n;++i)
		ans[f]=max(ans[f],up[i][0]-dep[i]*2+3-pro.ans[i]);
	for(register int i=n;i>1;--i)
		ans[fa[i][0]]=max(ans[fa[i][0]],ans[i]);
	for(register int i=1;i<=n;++i) printf("%d ",ans[i]);
	putchar('\n');
	return 0;
}
