#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,k,res;
vector<int>V;
void dfs(int u)
{
	if(u==n+1)
	{
		vector<int>t=V;
		int flag=1;
		while(flag)
		{
			flag=0;
			for(int i=0;i<V.size();i++)
			{
				if(t[i]==i+1)
				{
					t[i]=0;
					for(int j=0;j<i;j++)t[j]++;
					flag=1;
				}
			}
		}
		for(int i=0;i<V.size();i++)res=(res+t[i])%mod;
		return;
	}
	for(int i=0;i<=k;i++)
	{
		V.push_back(i);
		dfs(u+1);
		V.pop_back();
	}
}
int main()
{
	freopen("stone.in","r",stdin);
	freopen("stone.out","w",stdout);
	scanf("%d%d",&n,&k);
	dfs(1);
	printf("%d",res);
	return 0;
} 
