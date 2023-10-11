#include<bits/stdc++.h>
using namespace std;
int a[200010];
vector<int>e[200010];
void dfs(int x,int fa,int p)
{
	p=min(p,x);
	a[x]=min(a[x],p);
	for ( int i = 0 ; i < e[x].size() ; i++ )
	{
		if(e[x][i]==fa)
		{
			continue;
		}
		dfs(e[x][i],x,p);
	}
}
int main()
{
//	freopen("count.in","r",stdin);
//	freopen("count.out","w",stdout);
	int n,q;
	cin >> n >> q;
	memset(a,0x3f,sizeof(a));
	for ( int i = 1 ; i < n ; i++ )
	{
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	while(q--)
	{
		string op;
		int num;
		cin >> op >> num;
		if(op=="JC")
		{
			dfs(num,0,num);
		 } else{
		 	cout << a[num] << endl;
		 }
	}
	return 0;
}
