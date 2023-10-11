#include<bits/stdc++.h>
#define int long long
using namespace std;
struct node
{
	int p,h;
	int w;
}x[500005];
bool cmp(node x,node y)
{
	if(x.w==y.w)
		return x.h>y.h;
	return x.w<y.w;
}
int cnt;
int n,k;
int a[500005];
int sum[2000005];
priority_queue<pair<int,int> >q;
int ans;
int ans1;
int id[500005],cntid;
signed main()
{
	freopen("elevator.in","r",stdin);
	freopen("elevator.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]),++sum[a[i]];
	for(int i=1;i<=2e6;i++)
		if(sum[i])
		{
			for(int j=1;j<=sum[i]/k;j++)
			{
				x[++cnt].w=1ll*(i-1)*2*k;
				x[cnt].p=k;
				x[cnt].h=i;
			}		
			x[++cnt].w=1ll*(i-1)*2*(sum[i]%k);
			x[cnt].h=i;
			x[cnt].p=sum[i]%k;
			q.push(make_pair(x[cnt].w,cnt));
		}
	sort(x+1,x+cnt+1,cmp);
	for(int i=1;i<=n;i++)
	{
		if(!x[i].p)
			continue;
		if(k<x[i].p)
			x[i].p-=k,ans1+=2*(x[i].h-1),ans+=ans1;
		else
		{
			ans1+=2*(x[i].h-1)*x[i].p;
			int w=2*(x[i].h-1);
			ans+=ans1;
			int k1=k-x[i].p;
			x[i].p=0;
			cntid=0;
			while(k1&&!q.empty())
			{
				int p=q.top().second;
				q.pop();
				if(p<=i)
					continue;
				if(x[p].h>x[i].h)
				{
					id[++cntid]=p;
					continue;
				}
				if(k1>x[p].p)
				{
					ans+=w*x[p].p;
					k1-=x[p].p;
					x[p].p=0;
				}
				else
					ans+=w*k1,x[p].p-=k1,k1=0;
			}
			for(int j=1;j<=cntid;j++)
				q.push(make_pair(x[id[j]].w,id[j]));
		}
	}
	cout<<ans;
	return 0;
}
