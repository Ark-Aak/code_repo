#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#include <bits/stdc++.h>
#define ll int
#define un unsigned
using namespace std;
const int ss=180,MAXN=200000;
int n,m;
struct ed
{
	ll v,w,next;
}edge[MAXN*2+5];
ll head[MAXN+5],cnt;
inline void add(ll u,ll v,ll w)
{
	edge[++cnt].v=v;edge[cnt].w=w;edge[cnt].next=head[u];head[u]=cnt;
	edge[++cnt].v=u;edge[cnt].w=w;edge[cnt].next=head[v];head[v]=cnt;
}
int dep[MAXN+5],in[MAXN+5],tot,f[20][2*MAXN+5],to[MAXN+5];
int dfn[MAXN+5],cot,id[MAXN+5];
un ll dis[MAXN+5],sum[MAXN+5],pre_res[MAXN+5];
ll from[MAXN+5],L[MAXN/ss+2],R[MAXN/ss+2],sz[MAXN+5],fat[MAXN+5],rsz[MAXN+5],ds[MAXN+5];
inline bool cmp(int a,int b)
{
	return dfn[a]<dfn[b];
}
ll sf[MAXN+5];
void dfs(ll id,ll fa)
{
	dep[id]=dep[fa]+1;f[0][in[id]=++tot]=id;
	dfn[id]=++cot;to[cot]=id;fat[id]=fa;rsz[id]=1;
	sf[dfn[id]]=dfn[fa];ds[cot]=dis[id];
	for(ll i=head[id];i;i=edge[i].next)
	{
		ll v=edge[i].v,w=edge[i].w;
		if(v==fa)continue;
		dis[v]=dis[id]+w;
		dfs(v,id);
		f[0][++tot]=id;rsz[id]+=rsz[v];
	}
}
inline bool check(ll u,ll v)
{
	return (un ll)(dfn[v]-dfn[u])<(un ll)rsz[u];
}
inline int nm(ll x,ll y)
{
	return (dfn[x]<dfn[y]?x:y);
}
int lg[MAXN+5];
inline int lca(int u,int v)
{
	u=in[u];v=in[v];
	const ll len=__lg(v-u+1);
	return nm(f[len][u],f[len][v-(1<<len)+1]);
}
int a[2],d[2][ss+2];
int p[ss*2+2],yc[ss*2+2];
int st[ss*4+2],tp;
struct px
{
	int l,r,bl,br;
	un ll res;
}ask[MAXN+5];
ll ns[MAXN+5];
inline void pre(const ll l,const ll r)
{
	memset(sz,0,sizeof(sz));
	for(ll i=l;i<=r;++i)sz[dfn[i]]=1;
	for(ll i=n;i;--i)sz[sf[i]]+=sz[i];
	for(ll i=1;i<=n;++i)
	{
		pre_res[i]=pre_res[sf[i]]+(sz[sf[i]]-sz[i])*ds[sf[i]];
		ns[i]=sz[i]*ds[i]+pre_res[i];
	}
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	// for(ll i=2;i<=n;i++)lg[i]=lg[i>>1]+1, assert(lg[i]==(int)__lg(i));
	ll u,v,w;
	for(ll i=1;i<n;++i)cin>>u>>v>>w,add(u,v,w);
	dfs(1,0);
	for(ll i=1;i<=n;++i)id[i]=i,sum[i]=sum[i-1]+dis[i],from[i]=(i-1)/ss+1;
	for(ll i=1;i<=from[n];++i)L[i]=(i-1)*ss+1,R[i]=i*ss;
	R[from[n]]=n;
	for(ll i=1;i<=from[n];++i)sort(id+L[i],id+1+R[i],cmp);
	for(ll j=1;j<19;++j)
	for(ll i=1;i+(1<<j)-1<=tot;++i)
		f[j][i]=((dep[f[j-1][i]]<dep[f[j-1][i+(1<<(j-1))]]?f[j-1][i]:f[j-1][i+(1<<(j-1))]));
	dfn[0]=n+1;
	for(ll i=1;i<=m;++i)
	{
		cin>>ask[i].l>>ask[i].r;
		const ll l=ask[i].l,r=ask[i].r;
		ask[i].res=(sum[r]-sum[l-1])*(r-l);
		a[0]=a[1]=cot=0;
		un ll res=0;
		const ll fl=from[l],fr=from[r];
		ask[i].bl=fl+1;ask[i].br=fr-1;
		if(fl==fr)
		{
			for(ll i=L[fl];i<=R[fl];++i)
				if(l<=id[i]&&id[i]<=r)d[0][++a[0]]=id[i];
		}
		else
		{
			for(ll i=L[fl];i<=R[fl];++i)
				if(l<=id[i])d[0][++a[0]]=id[i];
			for(ll i=L[fr];i<=R[fr];++i)
				if(id[i]<=r)d[1][++a[1]]=id[i];
			if(ask[i].bl<=ask[i].br)ask[i].res+=sum[R[ask[i].br]]-sum[L[ask[i].bl]-1];
		}
		merge(d[0]+1,d[0]+1+a[0],d[1]+1,d[1]+1+a[1],p+1,cmp);
		cot=a[0]+a[1];
		st[tp=1]=1;tot=0;
		for(ll i=2;i<=cot;++i)yc[i]=lca(p[i-1],p[i]);
		for(ll i=1;i<=cot;++i)
		{
			ll id=p[i];
			if(!check(st[tp],id))
			{
				ll c=yc[i];
				while(tp-1&&dfn[c]<=dfn[st[tp-1]])
				{
					res+=sz[tp-1]*sz[tp]*dis[st[tp-1]];
					sz[tp-1]+=sz[tp];
					--tp;
				}
				st[tp]=c;
			}
			st[++tp]=id;
			sz[tp]=1;
		}
		while(tp-1)
		{
			res+=sz[tp-1]*sz[tp]*dis[st[tp-1]];
			sz[tp-1]+=sz[tp];
			--tp;
		}
		res=res*2;
		ask[i].res-=res;
	}
	for(ll i=2;i<from[n];++i)
	{
		pre(L[i],R[i]);
		for(ll i=1;i<=n;++i)sum[i]=sum[i-1]+ns[dfn[i]];
		static ll bl[MAXN/ss+2];
		for(ll i=1;i<=from[n];++i)
		bl[i]=sum[L[i]-1];
		for(ll j=1;j<=m;++j)
		{
			if(ask[j].bl<=i&&i<=ask[j].br)
			ask[j].res-=(2*(sum[ask[j].r]-sum[ask[j].l-1])-bl[ask[j].br+1]+bl[ask[j].bl]);
		}
	}
	for(ll i=1;i<=m;++i)cout<<ask[i].res<<'\n';
}
