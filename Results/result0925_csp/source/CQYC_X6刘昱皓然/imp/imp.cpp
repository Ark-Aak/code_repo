#include<bits/stdc++.h>
using namespace std;
long long n,x[5005],y[5005],lsh[5005],c[5005],a[5005][5005],sum[5005][5005],ans=-1e15;
int main()
{
	freopen("imp.in","r",stdin);
	freopen("imp.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i]>>y[i]>>c[i];
		lsh[i*2-1]=x[i];
		lsh[i*2]=y[i];
	}
	sort(lsh+1,lsh+2*n+1);
	int id=unique(lsh+1,lsh+2*n+1)-lsh-1;
	for(int i=1;i<=n;i++)
	{
		a[lower_bound(lsh+1,lsh+id+1,x[i])-lsh][lower_bound(lsh+1,lsh+id+1,y[i])-lsh]=c[i];
	}
	for(int i=1;i<=id;i++)
	{
		for(int j=1;j<=id;j++)
		{
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+a[i][j];
		}
	}
	for(int i=1;i<=id;i++)
	{
		for(int j=i;j<=id;j++)
		{
			long long summ=sum[j][j]-sum[i-1][j]-sum[j][i-1]+sum[i-1][i-1];
			summ-=lsh[j]-lsh[i];
			ans=max(ans,summ);
		}
	}
	cout<<ans;
	return 0;
}
