#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,y;
}a[1000005];
bool cmp(node x,node y)
{
	if(x.x==y.x)
		return x.y>y.y;
	return x.x<y.x;
}
int n,q;
int main()
{
	freopen("ds.in","r",stdin);
	freopen("ds.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].x);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i].y);
	sort(a+1,a+n+1,cmp);
	while(q--)
	{
		int maxn=0,ans=0;
		int u,r,d,l;
		scanf("%d%d%d%d",&u,&r,&d,&l);
		for(int i=n;i>=1;i--)
		{
			if(a[i].x>=d&&a[i].x<=u)
			{
				if(a[i].y>r||a[i].y<l)
					continue;
				if(a[maxn].y<a[i].y)
					maxn=i;
				if(a[maxn].y<=a[i].y||a[maxn].x==a[i].x)
					++ans;
//				cout<<a[i].x<<" "<<a[i].y<<endl;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
