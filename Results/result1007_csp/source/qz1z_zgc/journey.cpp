#include<bits/stdc++.h>
using namespace std;
const int N=1005,M=4e5+5;
int n,m;
int h[N],e[M],ne[M],w[M],idx,st[N];
void add(int a,int b,int c){e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;}
int bfs(int l,int r,int S,int T)
{
	queue<pair<int,int> >q;
	memset(st,0,sizeof st);
	q.push({S,l});
	st[S]=1;
	while(q.size())
	{
		pair<int,int>u=q.front();
		q.pop();
		int cur=u.first,dist=u.second;
		if(cur==T)return 1;
		if(dist>r)continue;
		for(int i=h[cur];~i;i=ne[i])
		{
			int j=e[i];
			if(!st[j]&&dist<=w[i])
			{
				st[j]=1;
				q.push({j,w[i]});
			}
		}
	}
	return 0;
}
int main()
{
	freopen("journey.in","r",stdin);
	freopen("journey.out","w",stdout);
	int q;
	memset(h,-1,sizeof h);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=m;i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b,i);
		add(b,a,i);
	}
	while(q--)
	{
		int l,r,S,T;
		scanf("%d%d%d%d",&l,&r,&S,&T);
		puts(bfs(l,r,S,T)?"Yes":"No");
	}
	return 0;
}
