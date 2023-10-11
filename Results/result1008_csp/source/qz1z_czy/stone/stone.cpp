#include<bits/stdc++.h>
#define int long long
#define rp(i,a,b) for(int (i)=(a);(i)<=(b);(i)++)
#define lp(i,a,b) for(int (i)=(a);(i)>=(b);(i)--)
#define rpt(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define lpt(i,a,b) for(int (i)=(a);(i)>(b);(i)--)
using namespace std;
const int N=110;
int n,k;
int a[N];
int ans;
int mod=1e9+7;
inline int read()
{
	int p=0,q=1;
	char ch=getchar();
	while(!isdigit(ch)) q=(ch=='-')?-1:1,ch=getchar();
	while(isdigit(ch)) p=(p<<3)+(p<<1)+(ch^48),ch=getchar();
	return p*q;
}
void GetScore(int *c)
{
	rp(i,1,n)
	{
		if(c[i]==i)
		{
			c[i]=0;
			rp(j,1,i-1) c[j]++;
		}
	}
	rp(i,1,n)
	{
		ans+=c[i];
		if(ans>=mod) ans-=mod;
	}
}
void dfs(int step)
{
	if(step==n+1)
	{
		GetScore(a);
		return;
	}
	rp(i,0,k)
	{
		a[step]=i;
		dfs(step+1);
	}
}
signed main(void)
{
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	n=read(),k=read();
	dfs(1);
	printf("%d",ans);
	return 0;
}
