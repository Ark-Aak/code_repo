#include<bits/stdc++.h>
using namespace std;
long long n,c[200005],p[200005][5],kk[400005],ff[400005],top,fg[400005],ans;
struct sd
{
	long long u,v,w;
}bi[400005];
vector<int> G[400005];
void dfs(int x,int fa,int op)
{
	ff[x]=op;
	for(int i=0;i<G[x].size();i++)
	{
		if(ff[G[x][i]]==0&&G[x][i]!=fa) dfs(G[x][i],x,op);
	}
}
int cmp(sd A,sd B)
{
	return A.w<B.w;
}
int find(int x)
{
	if(fg[x]==x) return x;
	else return fg[x]=find(fg[x]);
}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld%lld%lld",&c[i],&p[i][1],&p[i][2],&p[i][3],&p[i][4]);
		for(int j=1;j<=4;j++)
		{
			if(kk[p[i][j]]==1) 
			{
				p[i][j]+=2*n;
				G[p[i][j]].push_back(p[i][j]-2*n);
			}
			else 
			{
				kk[p[i][j]]=1;
				G[p[i][j]].push_back(p[i][j]+2*n);
			}
		}
		G[p[i][1]].push_back(p[i][2]);
		G[p[i][2]].push_back(p[i][1]);
		G[p[i][3]].push_back(p[i][4]);
		G[p[i][4]].push_back(p[i][3]);
	}
	for(int i=1;i<=4*n;i++)
	{
		if(ff[i]==0)
		{
			top++;
			dfs(i,0,top);
		}
	}
//	for(int i=1;i<=2*n;i++)
//	{
//		cout<<i<<":"<<endl;
//		for(int j=0;j<G[i].size();j++)
//		{
//			cout<<G[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	for(int i=1;i<=top;i++)
	{
		fg[i]=i;
	}
	for(int i=1;i<=n;i++)
	{
		bi[i].u=ff[p[i][1]];
		bi[i].v=ff[p[i][3]];
		bi[i].w=c[i];
	}
	sort(bi+1,bi+n+1,cmp);
	long long ar=0,aa,bb;
	for(int i=1;i<=n;i++)
	{
		aa=find(bi[i].u);
		bb=find(bi[i].v);
		if(aa!=bb)
		{
			ans+=bi[i].w;
			fg[aa]=bb;
			ar++;
			if(ar>=top-1) break;
		}
	}
	cout<<ans;
}
