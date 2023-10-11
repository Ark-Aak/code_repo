#include<bits/stdc++.h>
using namespace std;
const int N=2005;
int n,T,m,res,st[N];
struct node
{
	int times,id,op;
};
vector<node>operators;
int cmp(node a,node b){return a.times<b.times;}
pair<int,int>q[N];
void dfs(int u,int t)
{
	if(u==n+1)
	{
		int ans=0;
		for(int i=1;i<operators.size();i++)
		{
			if(operators[i-1].op==-1&&!st[operators[i-1].id])ans+=(operators[i].times-operators[i-1].times);
			else if(operators[i-1].op==1&&!st[operators[i].id]&&operators[i].op==1)ans+=(operators[i].times-operators[i-1].times);
		}
		res=max(res,T-ans-1); 
		return;
	}
	if(t)
	{
		st[u]=1;
		dfs(u+1,t-1);
		st[u]=0;
	}
	else dfs(u+1,t);
}
int main()
{
	freopen("seal.in","r",stdin);
	freopen("seal.out","w",stdout);
	scanf("%d%d%d",&n,&T,&m);
	for(int i=1;i<=n;i++)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		operators.push_back({l,i,-1});
		operators.push_back({r,i,1});
	}
	sort(operators.begin(),operators.end(),cmp);
	dfs(1,m);
	printf("%d",res);
	return 0;
}
