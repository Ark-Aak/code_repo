#include<bits/stdc++.h>
using namespace std;
const int N=15,M=1e4+5;
typedef long long LL;
int n,mod,res;
int pos[N],f[N];
vector<int>V;
void dfs(int u)
{
	if(u==n)
	{
		int flag=0;
		for(int i=0;i<n;i++)
		{
			int k=pos[i];
			int a=V[((k-1)%n+n)%n],b=V[((k+1)%n+n)%n];
			if(min(a,b)<i&&i<max(a,b))
			{
				flag=1;
				break;
			}
		} 
		res+=flag;
		if(res>=mod)res-=mod;
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(pos[i]==-1)
		{
			pos[i]=u;
			V.push_back(i);
			dfs(u+1);
			V.pop_back();
			pos[i]=-1;
		}
	}
}
void work1()
{
	memset(pos,-1,sizeof pos);
	res=0;
	dfs(0);
	printf("%d",res);
}
void work2()
{
	res=1;
	for(int i=1;i<=n;i++)res=1LL*res*i%mod;
	printf("%d",res);
}
void work3()
{
	LL t=1;
	for(int i=1;i<=n;i++)
	{
		t=1LL*t*i%mod;
		if(i%2)f[i]=t;
		else f[i]=1LL*(f[i-1]-f[i-2])%mod*i%mod;
		f[i]=(1LL*f[i]+1LL*mod)%mod;
	}
	printf("%d\n",f[n]);
}
int main()
{
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	scanf("%d%d",&n,&mod);
	if(n<=10)work1();
	else if(n%2)work2();
	else work3();
	return 0;
}
