#include<bits/stdc++.h>
#define ls root<<1
#define rs root<<1|1
#define mid ((t[root].l+t[root].r)>>1)
using namespace std;
//-------------------------
int w[1000005];
struct SET
{
	int l,r,val;
}t[4000005];
inline void bld(int l,int r,int root)
{
	t[root].l=l;
	t[root].r=r;
	if(l==r)
	{
		t[root].val=w[l];
		return;
	}
	bld(l,mid,ls);
	bld(mid+1,r,rs);
	t[root].val=min(t[ls].val,t[rs].val);
}
inline int query(int x,int y,int root)
{
	if(t[root].l>=x&&t[root].r<=y)
		return t[root].val;
	int res=1e9;
	if(x<=mid)
		res=min(res,query(x,y,ls));
	if(y>mid)
		res=min(res,query(x,y,rs));
	return res;
}
//--------------------------
struct node
{
	int nxt,to;
}e[2000005];
int head[1000005],cnt_edge;
inline void add(int u,int v)
{
	e[++cnt_edge].to=v;
	e[cnt_edge].nxt=head[u];
	head[u]=cnt_edge;
}
int top[1000005],son[1000005],siz[1000005],dfn[1000005],f[10000005],dep[1000005],cnt;
int s[1000005];
inline void dfs1(int u,int fa)
{
	f[u]=fa;
	dep[u]=dep[fa]+1;
	siz[u]=1;
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v==fa)
			continue;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[son[u]]<siz[v])
			son[u]=v;
	}
}
inline void dfs2(int u,int t)
{
	top[u]=t;
	dfn[u]=++cnt;
	w[cnt]=u;
	if(son[u])
		dfs2(son[u],t);
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v==f[u]||v==son[u])
			continue;
		dfs2(v,v);
	}
}
inline int ask(int x,int y)
{
	int res=1e9;
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])
			swap(x,y);
		res=min(res,query(dfn[top[x]],dfn[x],1));
		x=f[top[x]];
	}
	if(dfn[x]>dfn[y])
		swap(x,y);
	res=min(res,query(dfn[x],dfn[y],1));
	return res;
}
int n,q;
int jced[1000005],cnt_jc;
int flag=1;
int p1,p2;
int cnt1,cnt2;
int main()
{
	freopen("network.in","r",stdin);
	freopen("network.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
		add(v,u);
		++s[u],++s[v];
	}
	int root=0;
	for(int i=1;i<=n;i++)
	{
		cnt1+=(s[i]==1),cnt2+=(s[i]==2);
		if(!root&&s[i]==1)
			root=i;
	}
	if(cnt1==2&&cnt2==n-2)
		flag=1;
	else
		flag=0;
	if(flag)
	{
		dfs1(root,0);
		dfs2(root,root);
	}
	else
	{
		dfs1(1,0);
		dfs2(1,1);
	}
	bld(1,n,1);
	if(flag)
	{
		while(q--)
		{
			string op;
			int x;
			cin>>op;
			scanf("%d",&x);
			if(op=="JC")
			{
				if(!p1&&!p2)
				{
					p1=p2=x;
					continue;
				}
				if(dep[p1]<dep[x])
					p1=x;
				if(dep[p2]>dep[x])
					p2=x;
//				cout<<p1<<" "<<p2<<endl;
			}
			else
			{
				int ans=1e9;
				ans=min(ans,ask(x,p1));
				ans=min(ans,ask(x,p2));
				printf("%d\n",ans);
			}
		}
		return 0;
	}
	while(q--)
	{
		string op;
		int x;
		cin>>op;
		scanf("%d",&x);
		if(op=="JC")
			jced[++cnt_jc]=x;
		else
		{
			int ans=1e9;
			for(int i=1;i<=cnt_jc;i++)
				ans=min(ans,ask(x,jced[i])),x=jced[i];
			printf("%d\n",ans);
		}
	}
	return 0;
}
