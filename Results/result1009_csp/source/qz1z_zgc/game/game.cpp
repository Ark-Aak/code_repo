#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5,Q=1e4+5,mod=1e9+7;
typedef long long LL;
int T,n,m,s[2][N],res[Q];
struct node
{
	int x,y,id;
}query[N];
int cmp(node a,node b)
{
	if(a.x==b.x)return a.y<b.y;
	else return a.x<b.x;
} 
int main()
{
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);	
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		scanf("%d%d",&query[i].x,&query[i].y);
		query[i].id=i;
		n=max(n,query[i].x);
		m=max(m,query[i].y);
	}
	sort(query+1,query+T+1,cmp);
	for(int i=1,k=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int gcd=__gcd(i,j);
			s[i&1][j]=((((LL)s[(i-1)&1][j]+(LL)s[i&1][j-1])%mod-(LL)s[(i-1)&1][j-1])%mod+(LL)(i/gcd)+(LL)(j/gcd)-2LL)%mod;
			s[i&1][j]=(s[i&1][j]%mod+mod)%mod;
			while(k<=T&&i==query[k].x&&j==query[k].y)res[query[k++].id]=s[i&1][j];
		}
	}
	for(int i=1;i<=T;i++)printf("%d\n",res[i]);
	return 0;
} 
