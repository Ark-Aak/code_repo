#include<bits/stdc++.h>
#define int long long
using namespace std;
const int mod=1e9+7;
struct node
{
	char op;
	int x,y;
}q[1005];
bool cmp(node x,node y)
{
	return x.op<y.op;
}
int n,m;
int k;
int lazy[1000005],sum[1000005];
char op;
int x,y;
int add;
signed main()
{
	freopen("wisdom.in","r",stdin);
	freopen("wisdom.out","w",stdout);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		lazy[i]=1;
	for(int i=1;i<=k;i++)
		cin>>q[i].op,scanf("%lld%lld",&q[i].x,&q[i].y);
	sort(q+1,q+k+1,cmp);
	int last=0;
	for(int i=1;i<=k;i++)
	{
		if(q[i].op=='R')
			lazy[q[i].x]=lazy[q[i].x]*q[i].y%mod;
		else
		{
			last=i;
			break;
		}
	}
//	for(int i=1;i<=n;i++)
//		cout<<lazy[i]<<endl;
	for(int i=1;i<=n;i++)
		add=(add+lazy[i])%mod;
	for(int i=1;i<=n;i++)
		sum[1]=(sum[1]+((((i-1)*m+1))%mod*lazy[i])%mod)%mod;
	for(int i=2;i<=m;i++)
		sum[i]=(sum[i-1]+add)%mod;
	for(int i=last;i<=k;i++)
		sum[q[i].x]=sum[q[i].x]*q[i].y%mod;
	int ans=0;
	for(int i=1;i<=m;i++)
		ans=(ans+sum[i])%mod;
	cout<<ans;
	return 0;
}
