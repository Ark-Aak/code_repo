#include<bits/stdc++.h>
#define rep(i,j,k) for(ll i=(j),_i=(k);i<=_i;i++)
#define drp(i,j,k) for(ll i=(j),_i=(k);i>=_i;i--)
#define root 1,1,n
#define now ll t,ll l,ll r
#define mid (l+r)/2
#define ls t<<1
#define rs t<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
#define ll int
#define Nx 1000050
using namespace std;
//---------------------------------//
ll read(){
	ll x=0,f=0;char ch;
	while(!isdigit(ch=getchar())) f|=ch=='-';
	while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return f?-x:x;
}
void write(ll x){
	if(x/10) write(x/10);
	putchar(x%10+'0'); 
}
//---------------------------------//
const ll inf=INT_MAX;
ll n,q,b[Nx];
ll h[Nx],nxt[Nx<<1],to[Nx<<1],tot;
inline void add(ll u,ll v){
	nxt[++tot]=h[u],h[u]=tot,to[tot]=v;
	nxt[++tot]=h[v],h[v]=tot,to[tot]=u;
}
class SegmentTree{
public :
	ll mn[Nx<<2];
	inline ll build(now){
		if(l==r) return mn[t]=b[l];
		return mn[t]=min(build(lson),build(rson));
	}
	inline ll query(now,ll L,ll R){
		if(r<L||l>R) return inf;
		if(L<=l&&r<=R) return mn[t];
		return min(query(lson,L,R),query(rson,L,R));
	}
} tree;
class TreeChainPartition{
public :
	ll mn[Nx],top[Nx],son[Nx],dfn[Nx];
	ll f[Nx],dep[Nx],cnt,siz[Nx];
	inline ll dfs1(ll u,ll fa){
		siz[u]=1,f[u]=fa,dep[u]=dep[fa]+1;
		for(ll i=h[u];i;i=nxt[i]){
			ll v=to[i];
			if(v==fa) continue;
			siz[u]+=dfs1(v,u);
			if(siz[v]>siz[son[u]]) son[u]=v;
		}
		return siz[u];
	}
	inline void dfs2(ll u,ll fa,ll ffa){
		top[u]=ffa,dfn[u]=++cnt,b[cnt]=u;
		if(u==ffa) mn[u]=u;
		else mn[u]=min(u,mn[fa]);
		if(son[u]) dfs2(son[u],u,ffa);
		for(ll i=h[u];i;i=nxt[i]){
			ll v=to[i];
			if(v!=fa&&v!=son[u]) dfs2(v,u,v);
		}
	}
	inline ll LCA(ll u,ll v,ll &res){
		while(top[u]!=top[v]){
			if(dep[top[u]]<dep[top[v]]) swap(u,v);
			res=min(res,mn[u]),u=f[top[u]];
		}
		if(dep[u]<dep[v]) swap(u,v);
		res=min(res,tree.query(root,dfn[v],dfn[u]));
		return v;
	}
} tcp;
string s;
ll JC,JCval,Qval;
int main()
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	n=read(),q=read();
	rep(i,1,n-1) add(read(),read());
	tcp.dfs1(1,0);
	tcp.dfs2(1,0,1);
	tree.build(root);
	rep(i,1,q){
		cin>>s; 
		ll x=read();
		if(s=="JC"){
			if(!JC) JC=x,JCval=x;
			else JC=tcp.LCA(JC,x,JCval);
		} else {
			Qval=inf;
			tcp.LCA(JC,x,Qval);
			write(min(Qval,JCval)),putchar(10);
		}
	}
	return 0;
}
