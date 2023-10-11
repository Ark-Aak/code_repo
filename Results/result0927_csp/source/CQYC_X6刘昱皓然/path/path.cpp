#include<bits/stdc++.h>
using namespace std;
int n,K,a[505],f[505][405][505],ans=1e9;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("path.in","r",stdin);
	freopen("path.out","w",stdout);
	cin>>n>>K;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	memset(f,0x3f3f,sizeof(f));
	f[0][0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=min(i,K+1);j++)
		{
			for(int k=j;k<=i;k++)
			{
				f[i][j][k]=f[i-1][j][k]+(a[k]-a[i]);
				if(k==i)
					for(int l=j-1;l<=i-1;l++)
					{
						f[i][j][k]=min(f[i][j][k],f[i-1][j-1][l]);
					}
			}
		}
	}
	for(int i=K+1;i<=n;i++)
	{
		ans=min(ans,f[n][K+1][i]);
	}
	cout<<ans;
	return 0;
}
