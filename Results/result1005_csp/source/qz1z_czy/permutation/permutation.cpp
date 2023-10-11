#include<bits/stdc++.h>
#define rep(i,a,b) for(int (i)=(a);(i)<=(b);++(i))
using namespace std;
const int N=1e5+10;
#define int long long
int a[N],b[N],c[N];
int First[N],Second[N];
int n,k;
signed main(void)
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	scanf("%lld%lld",&n,&k);
	rep(i,1,n) scanf("%lld",&a[i]),First[i]=a[i];
	rep(i,1,n) scanf("%lld",&b[i]),Second[i]=b[i];
	if(n==1) return !(printf("%lld",n));
	int rd,i=0;
	while(1)
	{
		int flag=0;
		++i;
		rep(i,1,n) c[a[i]]=b[i];
		rep(i,1,n) a[i]=b[i],b[i]=c[i];
		if(i==k-1)
		{
			rep(j,1,n) printf("%d ",b[j]);
			exit(0);
		}
		rep(i,1,n)
		{
			if(First[i]==a[i]&&Second[i]==b[i])
				continue;
			else
			{
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			rd=i;
			break;
		}
	}
	k%=rd;
	printf("%d\n",k);
	rep(i,1,k-1)
	{
		rep(i,1,n) c[a[i]]=b[i];
		rep(i,1,n) a[i]=b[i],b[i]=c[i];
	}
	rep(i,1,n) printf("%d ",b[i]);
	return 0;
}
