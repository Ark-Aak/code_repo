#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,q,x[N],y[N],cnt[N];
struct node
{
	int x,y,id;
}sort_by_x[N],sort_by_y[N];
int cmp_x(node a,node b){return a.x<b.x;}
int cmp_y(node a,node b){return a.y<b.y;}
int find_x_d(int x)
{
	int l=1,r=n;
	while(l<r)
	{
		int mid=l+r>>1;
		if(sort_by_x[mid].x>=x)r=mid;
		else l=mid+1;
	}
	return l;
}
int find_x_u(int x)
{
	int l=1,r=n;
	while(l<r)
	{
		int mid=l+r+1>>1;
		if(sort_by_x[mid].x<=x)l=mid;
		else r=mid-1;
	}
	return l;
}
int find_y_l(int x)
{
	int l=1,r=n;
	while(l<r)
	{
		int mid=l+r>>1;
		if(sort_by_y[mid].y>=x)r=mid;
		else l=mid+1;
	}
	return l;
}
int find_y_r(int x)
{
	int l=1,r=n;
	while(l<r)
	{
		int mid=l+r+1>>1;
		if(sort_by_y[mid].y<=x)l=mid;
		else r=mid-1;
	}
	return l;
}
int main()
{
	freopen("ds.in","r",stdin);
	freopen("ds.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&x[i]);
	for(int i=1;i<=n;i++)scanf("%d",&y[i]);
	for(int i=1;i<=n;i++)
	{
		sort_by_x[i]={x[i],y[i],i};
		sort_by_y[i]={x[i],y[i],i};
	}
	sort(sort_by_x+1,sort_by_x+n+1,cmp_x);
	sort(sort_by_y+1,sort_by_y+n+1,cmp_y);
	while(q--)
	{
		memset(cnt,0,sizeof cnt);
		vector<int>V;
		int u,r,d,l,res=0;
		scanf("%d%d%d%d",&u,&r,&d,&l);
		u=find_x_u(u);
		d=find_x_d(d);
		l=find_y_l(l);
		r=find_y_r(r);
		for(int i=d;i<=u;i++)cnt[sort_by_x[i].id]++; 
		for(int i=l;i<=r;i++)cnt[sort_by_y[i].id]++;
		for(int i=1;i<=n;i++)
		{
			if(cnt[i]==2)V.push_back(i);
		}
		for(int i=0;i<V.size();i++)
		{
			int flag=1;
			for(int j=0;j<V.size();j++)
			{
				if(x[V[i]]<x[V[j]]&&y[V[i]]<y[V[j]])
				{
					flag=0;
					break;
				}
			}
			res+=flag;
		}
		printf("%d\n",res);
	}
	return 0;
}
