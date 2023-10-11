#include<bits/stdc++.h>
#define int long long
#define inf 1e18
using namespace std;
vector<int>e[100010];
bool kh[100010];
int dep[100010];
int fa[100010];
bool xl[100010];
int dfs(int x,int f)
{
	dep[x]=dep[f]+1;
	fa[x]=f;
	for ( int i = 0 ; i < e[x].size() ; i++ )
	{
		if(e[x][i]==f)
		{
			continue;
		}
		dfs(e[x][i],x);
	}
}
signed main()
{
	freopen("loser.in","r",stdin);
	freopen("loser.out","w",stdout);
	int n,q;
	cin >> n >> q;
	for ( int i = 1 ; i < n ; i++ )
	{
		int u,v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for ( int i = 1 ; i <= n ; i++ )
	{
		cin >> kh[i];
	}
	dfs(1,0);
	while(q--)
	{
		int op,x,y;
		cin >> op >> x >> y;
		if(op==1)
		{
			while(dep[x]>dep[y])
			{
				kh[x]^=1;
				x=fa[x];
			}
			while(dep[y]>dep[x])
			{
				kh[y]^=1;
				y=fa[y];
			}
			while(x!=y)
			{
				kh[x]^=1;
				kh[y]^=1;
				x=fa[x];
				y=fa[y];
			}
			kh[x]^=1;
		}else{
			int xx=x,yy=y;
			while(dep[xx]>dep[yy])
			{
				xx=fa[xx];
			}
			while(dep[yy]>dep[xx])
			{
				yy=fa[yy];
			}
			while(xx!=yy)
			{
				xx=fa[xx];
				yy=fa[yy];
			}
			int l=xx,top=0;
			while(x!=l)
			{
				xl[top++]=kh[x];
				x=fa[x];
			}
			xl[top++]=kh[x];
			int lt=top+dep[y]-dep[l];
			while(y!=l)
			{
				xl[--lt]=kh[y];
				y=fa[y];
				top++;
			}
//			for ( int i = 0 ; i < top ; i++ )
//			{
//				cout << xl[i] << " ";
//			}
//			cout << endl;
			cout << top <<endl;
		}
	}
	return 0;
 }
