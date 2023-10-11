#include<bits/stdc++.h>
using namespace std;
#define int long long
#define debug puts("IAKIOI")
struct abc{
	int v,val;
};
vector<abc>e1[200010],e2[200010];
int n,q;
int dep1[200010];
int f1[200010][20];
int s1[200010];
int dep2[200010];
int f2[200010][20];
int s2[200010];
void dfs1(int x,int fa)
{
	dep1[x]=dep1[fa]+1;
	for ( int i = 0 ; i < e1[x].size() ; i++ )
	{
		if(e1[x][i].v==fa)
		{
			continue;
		}
		int v=e1[x][i].v;
		f1[v][0]=x;
		s1[v]=s1[x]+e1[x][i].val;
		for ( int i = 1 ; i < 20 ; i++ )
		{
			f1[v][i]=f1[f1[v][i-1]][i-1];
		}
		dfs1(v,x);
	}
}
void dfs2(int x,int fa)
{
	dep2[x]=dep2[fa]+1;
	for ( int i = 0 ; i < e2[x].size() ; i++ )
	{
		if(e2[x][i].v==fa)
		{
			continue;
		}
		int v=e2[x][i].v;
		f2[v][0]=x;
		s2[v]=s2[x]+e2[x][i].val;
		for ( int i = 1 ; i < 20 ; i++ )
		{
			f2[v][i]=f2[f2[v][i-1]][i-1];
		}
		dfs2(v,x);
	}
}
void init()
{
	for ( int i = 0 ; i < 20 ; i++ )
	{
		f1[1][i]=f2[1][i]=1;
	}
	dfs1(1,0);
	dfs2(1,0);
}
int lca1(int x,int y)
{
	if(dep1[x]>dep1[y])
	{
		swap(x,y);
	}
	int k=19;
	while(dep1[x]<dep1[y])
	{
		if(dep1[f1[y][k]]>=dep1[x])
		{
//			cout << k << " " << y << " " << f1[y][k]<<endl;
			y=f1[y][k];
		}
		k--;
	}
//	cout << x << " " << y;
	if(x==y)
	{
		return x;
	}
	k=19;
	while(k!=0)
	{
		if(f1[x][k]!=f1[y][k])
		{
			x=f1[x][k];
			y=f1[y][k];
		}
		k--;
	}
	return f1[x][0];
}
int lca2(int x,int y)
{
	if(dep2[x]>dep2[y])
	{
		swap(x,y);
	}
	int k=19;
	while(dep2[x]<dep2[y])
	{
		if(dep2[f1[y][k]]>=dep2[x])
		{
//			cout << k << " " << y << " " << f1[y][k]<<endl;
			y=f2[y][k];
		}
		k--;
	}
//	cout << x << " " << y;
	if(x==y)
	{
		return x;
	}
	k=19;
	while(k!=0)
	{
		if(f2[x][k]!=f2[y][k])
		{
			x=f2[x][k];
			y=f2[y][k];
		}
		k--;
	}
	return f2[x][0];
}
signed main()
{
	freopen("double.in","r",stdin);
	freopen("double.out","w",stdout);
	cin >> n ;
	for ( int i = 1 ; i <= n ; i++ )
	{
		int x;
		cin >> x;
		e1[i*2].push_back({i*2-1,x});
		e1[i*2-1].push_back({i*2,x});
		e2[i*2].push_back({i*2-1,x});
		e2[i*2-1].push_back({i*2,x});
	}
	for ( int i = 1 ; i < n ; i++ )
	{
		int a,b,c,d;
		cin >> a>>b>>c>>d;
		e1[a*2-1].push_back({b*2-1,c});
		e1[b*2-1].push_back({a*2-1,c});
		e2[a*2].push_back({b*2,d});
		e2[b*2].push_back({a*2,d});
	}
	init();
	cin >> q;
	while(q--)
	{
		int x,y;
		cin >> x>>y;
		int l1=lca1(x,y);
		int l2=lca2(x,y);
//		cout << l1 << " " << l2 << endl;
		int ans1=s1[x]-s1[l1]+s1[y]-s1[l1];
		int ans2=s2[x]-s2[l2]+s2[y]-s2[l2];
//		cout << ans1 << " " << ans2 << endl;
		cout << min(ans1,ans2) <<endl;
	}
	return 0;
}
/*
5
3 6 15 4 8
1 2 5 4
2 3 5 7
1 4 1 5
1 5 2 1
3
1 2
5 6
1 10
*/
