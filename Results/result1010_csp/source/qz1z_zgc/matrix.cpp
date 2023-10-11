#include<bits/stdc++.h>
using namespace std;
const int N=25,M=2e5+5;
int n,m,res=1e9,sth[N],stl[M];
char str[N][M];
void dfs(int u)
{
	if(!u)
	{
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(str[i][j]=='1')ans++;
			}
		}
		res=min(res,ans);
		return;
	}
	dfs(u-1);
	for(int i=1;i<=n;i++)
	{
		if(!sth[i])
		{
			sth[i]=1;
			for(int j=1;j<=m;j++)str[i][j]=('1'-str[i][j])+'0';
			dfs(u-1);
			for(int j=1;j<=m;j++)str[i][j]=('1'-str[i][j])+'0';
			sth[i]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		if(!stl[i])
		{
			stl[i]=1;
			for(int j=1;j<=n;j++)str[j][i]=('1'-str[j][i])+'0';
			dfs(u-1);
			for(int j=1;j<=n;j++)str[j][i]=('1'-str[j][i])+'0';
			stl[i]=0;
		}
	}
}
int main()
{
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%s",str[i]+1);
	dfs(n+m);
	printf("%d",res);
	return 0;
} 
