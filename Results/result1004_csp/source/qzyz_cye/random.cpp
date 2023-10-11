#include<bits/stdc++.h>
using namespace std;
long long n,aa,kl[1005],mod=998244353,ans,ls[4],a[1005][1005];
char c[1005][1005];
vector<int> G[1005];
void work(int x,int y,int z)
{
	ls[1]=x;
	ls[2]=y;
	ls[3]=z;
	for(int i=1;i<=3;++i)
	{
		for(int j=1;j<=3;++j)
		{
			for(int h=1;h<=3;++h)
			{
				if(i!=j&&i!=h&&j!=h)
				{
					if(a[ls[i]][ls[j]]==1&&a[ls[j]][ls[h]]==1&&a[ls[h]][ls[i]]==1)
					{
						ans=(ans+kl[aa])%mod;
						return ;
					}
				}
			}
		}
	}
	for(int i=1;i<=3;++i)
	{
		for(int j=1;j<=3;++j)
		{
			for(int h=1;h<=3;++h)
			{
				if(i!=j&&i!=h&&j!=h)
				{
					if(a[ls[i]][ls[j]]==1&&a[ls[j]][ls[h]]==1&&a[ls[h]][ls[i]]==0&&a[ls[i]][ls[h]]!=1)
					{
						ans=(ans+kl[aa-1])%mod;
						return ;
					}
				}
			}
		}
	}
	for(int i=1;i<=3;++i)
	{
		for(int j=1;j<=3;++j)
		{
			for(int h=1;h<=3;++h)
			{
				if(i!=j&&i!=h&&j!=h)
				{
					if(a[ls[i]][ls[j]]==1&&a[ls[j]][ls[h]]==0&&a[ls[h]][ls[i]]==0&&a[ls[i]][ls[h]]!=1&&a[ls[h]][ls[j]]!=1)
					{
						ans=(ans+kl[aa-2])%mod;
						return ;
					}
				}
			}
		}
	}
}
int main()
{
	freopen("random.in","r",stdin);
	freopen("random.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) 
		{
			cin>>c[i][j];
			a[i][j]=c[i][j]-'0';
			if(a[i][j]==1) G[i].push_back(j);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[i][j]==0&&a[j][i]==0) aa++;
		}
	}
	kl[0]=1;
	for(int i=1;i<=aa;i++)
	{
		kl[i]=(kl[i-1]*2)%mod;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int h=j+1;h<=n;h++)
			{
				work(i,j,h);
			}
		}
	}
	cout<<ans;
	return 0;
}
