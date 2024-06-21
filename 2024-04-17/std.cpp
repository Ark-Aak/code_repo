#include<bits/stdc++.h>
#define int long long
using namespace std;
const int NN=1e7+4;
vector<pair<int,int> >g[NN];
int fa[NN],w[NN];
signed main()
{
	int k;
	scanf("%lld",&k);
	g[1].push_back({0,1});
	cout << "1 -> 0 w = 1" << endl;
	int u=1,p=0,t=1,s=0,val=1;
	while(!(k%2))
	{
		val*=2;
		k/=2;
	}
	if(k==1)
	{
		printf("-1");
		return 0;
	}
	while(s+t<=k)
	{
		s+=t;
		g[p].push_back({++u,k-t});
		cout << p << " -> " << u << " w = " << k - t << endl;
		fa[u]=p;
		g[p].push_back({++u,t});
		cout << p << " -> " << u << " w = " << t << endl;
		fa[u]=p;
		g[p].push_back({++u,k-t});
		cout << p << " -> " << u << " w = " << k - t << endl;
		fa[u]=p;
		g[p].push_back({++u,t});
		cout << p << " -> " << u << " w = " << t << endl;
		fa[u]=p;
		w[u-2]=t;
		t*=2;
		p=u-2;
	}
	t/=2;
	p=fa[p];
	cout << endl;
	while(s<k)
	{
		while(s+2*w[p]<=k)
		{
			s+=2*w[p];
			t+=w[p];
			g[fa[p]].push_back({++u,k-t});
			cout << fa[p] << " -> " << u << " w = " << k - t << endl;
			g[fa[p]].push_back({++u,t});
			cout << fa[p] << " -> " << u << " w = " << t << endl;
			t+=w[p];
			g[p].push_back({++u,k-t});
			cout << p << " -> " << u << " w = " << k - t << endl;
			g[p].push_back({++u,t});
			cout << p << " -> " << u << " w = " << t << endl;
		}
		t+=w[p];
		p=fa[p];
	}
	u++;
	printf("%lld\n",u);
	g[u]=g[0];
	for(int i=1;i<=u;i++)
		for(pair<int,int>v:g[i])
		{
			if(!v.first)
				v.first=u;
			printf("%lld %lld %lld\n",i,v.first,v.second*val);
		}
	return 0;
}
