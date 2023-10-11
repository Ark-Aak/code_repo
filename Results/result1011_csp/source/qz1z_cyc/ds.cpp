#include<bits/stdc++.h>
using namespace std;
int n,q,U,R,D,L,top,dl[1000005];
struct sb
{
	int x,y;
}a[100005];
bool cmp(sb xx,sb yy)
{
	if(xx.x==yy.x) return xx.y<yy.y;
	return xx.x<yy.x;
}
int check(int x,int y)
{
	if(x<=U&&x>=D&&y<=R&&y>=L) return 1;
	return 0;
}
int main()
{
	freopen("ds.in","r",stdin);
	freopen("ds.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) scanf("%d",&a[i].x);
	for(int i=1;i<=n;i++) scanf("%d",&a[i].y);
	sort(a+1,a+1+n,cmp);
	while(q--)
	{
		scanf("%d%d%d%d",&U,&R,&D,&L);
		top=0;
		for(int i=1;i<=n;i++)
		{
			if(check(a[i].x,a[i].y)==1)
			{
				while(a[i].y>dl[top]&&top>1) top--;
				top++;
				dl[top]=a[i].y;
			}
		}
		cout<<top<<endl;
	}
	return 0;
}
