#include<bits/stdc++.h>
using namespace std;
struct node
{
	int nxt,to;
}e[114514*2];
int head[114514],cnt_edge;
void add_edge(int u,int v)
{
	e[++cnt_edge].to=v;
	e[cnt_edge].nxt=head[u];
	head[u]=cnt_edge;
}
string s=" ";
char stk[114514];
int to;
int dp[114514];
int a[114514];
int solve()
{
	memset(dp,0,sizeof dp);
	to=0;
	for(int i=1;i<s.size();i++)
	{
		if(stk[to]=='('&&s[i]==')')
			--to,dp[i]=dp[i-1]+2;
		else if(s[i]=='(')
			stk[++to]='(',dp[i]=dp[i-1];
		else if(s[i]==')')
			dp[i]=0,to=0;
	}
	int res=0;
	for(int i=1;i<s.size();i++)
		res=max(res,dp[i]);
	return res;
}
int top[114514],siz[114514],son[114514],f[114514],dep[114514],dfn[114514],cnt;
void dfs1(int u,int fa)
{
	siz[u]=1;
	dep[u]=dep[fa]+1;
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].to;
		if(v==fa)
			continue;
		f[v]=u;
		dfs1(v,u);
		siz[u]+=siz[v];
		if(siz[son[u]]<siz[v])
			son[u]=v;
	}
}
void dfs2(int u,int t)
{
	top[u]=t;
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
int lca(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]])
			swap(x,y);
		x=f[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}
string s1,s2;
int ask(int x,int y)
{
	s1=s2=" ";
	int Lca=lca(x,y);
	while(x!=Lca)
		s1+=a[x]==0?'(':')',x=f[x];
	s1+=a[Lca]==0?'(':')';
	while(y!=Lca)
		s2+=a[y]==0?'(':')',y=f[y];
	s=s1;
	for(int i=s2.size()-1;i>=1;i--)	
		s+=s2[i];
//	cout<<s1<<" "<<s2<<endl;
	return solve();
}
void update(int x,int y)
{
	int Lca=lca(x,y);
	while(x!=Lca)
		a[x]^=1,x=f[x];
	while(y!=Lca)
		a[y]^=1,y=f[y];
	a[Lca]^=1;
	   
}
int n,q;
int main()
{
	freopen("loser.in","r",stdin);
	freopen("loser.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	dfs1(1,0);
	dfs2(1,1);
//	for(int i=1;i<=n;i++)
//		cout<<f[i]<<" "<<dep[i]<<" "<<siz[i]<<" "<<son[i]<<" "<<top[i]<<" "<<dfn[i]<<endl; 
	while(q--)
	{
		int op,x,y;
		scanf("%d%d%d",&op,&x,&y);
		if(op==1)
			update(x,y);
		else
			cout<<ask(x,y)<<endl;
	}
	return 0;
}
/*
5 1
1 2
2 3
2 4
2 5
0 1 0 1 1
2 3 4
*/
