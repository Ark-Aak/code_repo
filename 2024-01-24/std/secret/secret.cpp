#include<bits/stdc++.h>
#define re register
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
typedef long long ll;
typedef double db;
inline ll win(){
	ll x=0;bool w=0;char c=getchar();
	while(c<'0'||c>'9') w|=c=='-',c=getchar();
	while(c<='9'&&c>='0') x=(x<<1)+(x<<3)+(c^48),c=getchar();
	return w?-x:x;
}

const int N=505050,K=N*3,M=K*2;
const int inf=0x3f3f3f3f;
int tot,v[M],ne[M],h[K],cnt,dfn[K],low[K],tp,st[K],sct,scc[K];
vector<int> vts[K];

inline void add(int x,int y){v[++tot]=y,ne[tot]=h[x],h[x]=tot;}
inline void dfs(int x){
	dfn[x]=low[x]=++cnt,st[++tp]=x;
	for(re int i=h[x],y=v[i];i;y=v[i=ne[i]])
		if(!dfn[y]) dfs(y),low[x]=min(low[x],low[y]);
		else if(!scc[y]) low[x]=min(low[x],dfn[y]);
//	debug("%d :%d %d\n",x,dfn[x],low[x]);
	if(dfn[x]==low[x]){
		++sct;
		do{vts[scc[st[tp]]=sct].push_back(st[tp]);}while(st[tp--]!=x);
	}
}

#define ls k<<1
#define rs k<<1|1
int a[N];
struct qwe{
	ll s,v;
	friend qwe operator +(qwe p,qwe q){return (qwe){p.s+q.s,min(p.v+q.s,q.v)};}
}t[M];

inline void bld(int k,int l,int r){
	if(l==r) return t[k]=(qwe){max(0,-a[l]),inf},void();
	int d=(l+r)>>1;
	bld(ls,l,d),bld(rs,d+1,r);
	t[k]=t[ls]+t[rs];
}

inline void upd(int k,int l,int r,int x,ll v){
	if(l==r) return t[k]=(qwe){t[k].s+v,t[k].s+v},void();
	int d=(l+r)>>1;
	if(x<=d) upd(ls,l,d,x,v);
	else upd(rs,d+1,r,x,v);
	t[k]=t[ls]+t[rs];
}

inline qwe qry(int k,int l,int r,int x){
	if(x<=l) return t[k];
	int d=(l+r)>>1;
	if(d<=x) return qry(rs,d+1,r,x);
	return qry(ls,l,d,x)+t[rs];
}
#undef ls
#undef rs

int p[K],q[K],mp[K],mq[K];
vector<int> o[N];
inline void solve(){
	int n=win(),m=(n<<1)+2;ll sum=0ll;
	for(re int i=1;i<=n;++i) a[i]=win();
	for(re int i=1;i<=n;++i) a[i]-=win();
	for(re int i=1;i<=n;++i) p[i]=win()+1;
	for(re int i=1;i<=n;++i) q[i+1]=win();
	a[++n]=0,q[1]=0,p[n]=n+1;
	for(re int i=n;i>=1;--i) a[i]=a[i]-a[i-1];
	add(n+1,1);
	for(re int i=2  ;i<=n;++i) add(n+i,n+i-1),add(n+i,i);
	add(m+n,n);
	for(re int i=n-1;i>=1;--i) add(m+i,m+i+1),add(m+i,i);
	for(re int i=1;i<=n;++i){
		if(q[i])    add(i,q[i]+n);
		if(p[i]<=n) add(i,p[i]+m);
		p[i+n]=p[i+m]=inf,q[i+n]=q[i+m]=0;
	}
	m+=n;
	for(re int i=1;i<=m;++i) if(!dfn[i]) dfs(i);
	for(re int k=1;k<=sct;++k){
		mp[k]=inf,mq[k]=0;
		for(re int x:vts[k]){
//			debug("scc %d:%d\n",k,x);
			mp[k]=min(mp[k],p[x]),mq[k]=max(mq[k],q[x]);
			for(re int i=h[x],y=v[i];i;y=v[i=ne[i]])
				mp[k]=min(mp[k],p[y]),mq[k]=max(mq[k],q[y]);
		}
		for(re int x:vts[k]) p[x]=mp[k],q[x]=mq[k];
	}
//	for(re int i=1;i<=n;++i) debug("%d:%d %d %d\n",i,a[i],p[i],q[i]);
	for(re int i=1;i<=n;++i) if(a[i]>0) o[q[i]].push_back(i);
	a[++n]=0,bld(1,1,n);int fl=1;
	for(re int i=0;i<n;++i){
		if(a[i]<0) sum-=a[i];
		for(re int j:o[i]) upd(1,1,n,p[j],-a[j]);
//		debug("%d:%lld %lld\n",i,sum,qry(1,1,n,i+1).v);
		if(o[i].size()&&(sum+qry(1,1,n,i+1).v)<0) fl=0,i=n;
	}
	puts(fl?"YES":"NO");
	for(re int i=1;i<=m;++i) h[i]=scc[i]=dfn[i]=0;
	for(re int i=1;i<=sct;++i) vts[i].clear();
	for(re int i=0;i<=n;++i) o[i].clear();
	tp=sct=cnt=tot=0;
}

signed main(){
	freopen("secret.in","r",stdin);
	freopen("secret.out","w",stdout);
	int T=win();
	while(T--) solve();
	return 0;
}
