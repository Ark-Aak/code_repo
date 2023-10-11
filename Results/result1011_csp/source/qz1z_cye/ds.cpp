#include<bits/stdc++.h>
using namespace std;
long long n,U,D,R,L,q,dl[10005],top=0;
struct sd
{
	long long x,y;
}g[10005];
int cmp(sd A,sd B)
{
	if(A.x!=B.x) return A.x<B.x;
	else return A.y>B.y;
}
int check(long long xx,long long yy)
{
	if(xx<=U&&xx>=D&&yy>=L&&yy<=R) return 1;
	else return 0;
}
int main()
{
	freopen("ds.in","r",stdin);
	freopen("ds.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&g[i].x);
	}
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&g[i].y);
	}
	sort(g+1,g+n+1,cmp);
	for(int i=1;i<=q;i++)
	{
		scanf("%lld%lld%lld%lld",&U,&R,&D,&L);
		top=0;
		for(int j=1;j<=n;j++)
		{
			if(check(g[j].x,g[j].y)==1)
			{
			//	cout<<g[j].x<<" "<<g[j].y<<" "<<L<<" "<<endl;
				while(g[j].y>dl[top]&&top>=1) top--;
				top++;
				dl[top]=g[j].y;
			}
		}
		printf("%lld\n",top);
	}
	return 0;
 } 
