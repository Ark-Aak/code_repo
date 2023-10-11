#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=3e7+1e4; 
int T,limit,n,primes[N],cnt;
int st[N],res[N];
int main()
{
	freopen("casio.in","r",stdin);
	freopen("casio.out","w",stdout);
	scanf("%d%d",&T,&limit);
	for(int i=2;i<N;i++)
	{
		if(!st[i])
		{
			primes[cnt++]=i;
			if(i<=limit)
			{
				for(int j=i+i;j<N;j+=i)st[j]=1;
			}
		}
	}
	int ans=0;
	for(int i=N-1;i>=2;i--)
	{
		if(!st[i])ans=i;
		res[i]=ans;
	}
	while(T--)
	{
		int x;
		scanf("%d",&x);
		printf("%d\n",res[x]);
	}
	return 0;
} 
