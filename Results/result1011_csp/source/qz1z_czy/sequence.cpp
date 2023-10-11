#include<bits/stdc++.h>
#define int long long
#define rp(i,a,b) for(int i=a;i<=b;++i)
using namespace std;
const int N=1e4+10,M=1e4+10;
int mod=998244353;
int n,m;
int a[N];
int ans;
int f[9][9]={0,0,0,0,0,0,0,0,0,
			 0,1,2,3,4,5,6,7,8,
			 0,1,3,7,12,20,28,40,52,
			 0,1,4,15,33,76,123,220,326,
			 0,1,5,31,88,285,532,1201,2031,
			 0,1,6,63,232,1065,2292,6547,12640,
			 0,1,7,127,609,3976,9865,35680,78652,
			 0,1,8,255,1596,14840,42450,194440,489396,
			 0,1,9,511,4180,55385,182656,1059601,3045153};
void dfs(int step)
{
	if(step==n+1)
	{
//		for(int i=1;i<=n;i++)
//		{
//			printf("%lld ",a[i]);
//		}puts("");
		ans++;
		if(ans>=mod)
			ans%=mod;
		return;
	}
	rp(j,1,m)
	{
		if(step==1)
		{
			a[step]=j;
			dfs(step+1);
		}
		else
		{
			a[step]=j;
			if(a[step-1]%a[step]||a[step]>=a[step-1])
				dfs(step+1);
			else continue;
		}
	}
}
signed main(void)
{
	freopen("sequence.in","r",stdin);
	freopen("sequence.out","w",stdout);
//	int t1=clock();
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	scanf("%lld %lld",&n,&m);
	if(n<=8&&m<=8) return !(printf("%lld",f[n][m]%mod));
	dfs(1);
	printf("%lld",ans);
//	int t2=clock();
//	printf("%lld",t2-t1);
	return 0;
}
