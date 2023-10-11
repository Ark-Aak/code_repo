#include <cstdio>
#include <algorithm>
using namespace std;
const int M = 4005;
int read()
{
	int x=0,f=1;char c;
	while((c=getchar())<'0' || c>'9') {if(c=='-') f=-1;}
	while(c>='0' && c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
int n,m,k,t,w,ans,b[M],c[M],nxt[M],dp[2][M][M];
struct node
{
	int x,id,fl;
	bool operator < (const node &b) const
	{
		return x<b.x;
	}
}a[2*M];
signed main()
{
	freopen("seal.in","r",stdin);
	freopen("seal.out","w",stdout);
	n=read();m=read();k=read();
	for(int i=1;i<=n;i++)
	{
		a[++t]=node{read(),i,0};
		a[++t]=node{read(),i,1};
	}
	sort(a+1,a+1+t);
	ans=a[1].x+m-a[t].x;
	for(int i=1;i<t;i++)
	{
		int w=a[i+1].x-a[i].x;
		if(a[i].fl && !a[i+1].fl) ans+=w;
		if(!a[i].fl && !a[i+1].fl) c[a[i].id]+=w;
		if(a[i].fl && a[i+1].fl) c[a[i+1].id]+=w;
		if(!a[i].fl && a[i+1].fl)
		{
			if(a[i].id==a[i+1].id) c[a[i].id]+=w;
			else nxt[a[i+1].id]=a[i].id,b[a[i].id]+=w;
		}
	}
	int pr=0; 
	for(int i=1;i<=n;i++)
		if(!b[i])
		{
			nxt[pr]=i;
			for(;nxt[pr];pr=nxt[pr]);
		}
	dp[0][0][0]=ans;
	for(int i=nxt[0];i;i=nxt[i])
	{
		w^=1;
		for(int j=0;j<=k;j++)
			for(int t=0;t<=1;t++)
			{
				if(!dp[w^1][j][t]) continue;//illegal states
				dp[w][j][0]=max(dp[w][j][0],dp[w^1][j][t]);
				dp[w][j+1][1]=max(dp[w][j+1][1],dp[w^1][j][t]+t*b[i]+c[i]);
				dp[w^1][j][t]=0;
			}
	}
	printf("%d\n",max(dp[w][k][0],dp[w][k][1]));
}

