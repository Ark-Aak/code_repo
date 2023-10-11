#include<bits/stdc++.h>
using namespace std;
long long n,m,a[23][200005],ans=1145141919810,sum,h[23],num[200005],ls; 
char c;
void dfs(int k)
{
	if(k>=n)
	{
		for(int i=1;i<=n;i++)
		{
			
			for(int j=1;j<=m;j++)
			{
				if(i==1) num[j]=0;
				ls=(a[i][j]+h[i])%2;
				num[j]+=ls;
			}
		}
		sum=0;
		for(int i=1;i<=m;i++)
		{
			sum+=min(num[i],n-num[i]);
		}
		ans=min(ans,sum);
		return ;
	}
	k++;
	h[k]=1;
	dfs(k);
	h[k]=0;
	dfs(k);
}
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>c;;
			a[i][j]=c-'0';
		}
	}
	dfs(0);
	cout<<ans;
	return 0;
}

