#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n,res,a[N],b[N],cnt[N];
int check(int x,int y,int z)
{
	memset(cnt,0,sizeof cnt);
	cnt[a[x]]++;
	cnt[b[x]]++;
	cnt[a[x]+n]++;
	cnt[b[x]+n]++;
	cnt[a[y]]++;
	cnt[b[y]]++;
	cnt[a[y]+n]++;
	cnt[b[y]+n]++;
	cnt[a[z]]++;
	cnt[b[z]]++;
	cnt[a[z]+n]++;
	cnt[b[z]+n]++;
	for(int i=1;i<=2*n;i++)cnt[i]+=cnt[i-1];
	int t1=min(abs(cnt[b[x]]-cnt[a[x]-1]),abs(cnt[a[x]+n]-cnt[b[x]-1]));
	int t2=min(abs(cnt[b[y]]-cnt[a[y]-1]),abs(cnt[a[y]+n]-cnt[b[y]-1]));
	int t3=min(abs(cnt[b[z]]-cnt[a[z]-1]),abs(cnt[a[z]+n]-cnt[b[z]-1]));
	if(t1==t2&&t2==t3)res++;
}
int main()
{
	freopen("explorer.in","r",stdin);
	freopen("explorer.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		a[i]=min(x,y);
		b[i]=max(x,y);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)check(i,j,k);
		}
	}
	printf("%d",res);
	return 0;
}
