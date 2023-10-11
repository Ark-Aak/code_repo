#include<bits/stdc++.h>
using namespace std;
int n,q,u,r,d,l,ss[10005];
int pa[1000005],pb[1000005],tp,qx,qy;
struct tni
{
	int x,y;
};
tni a[1000005],b[1000005];
int cmp(tni aaa,tni bbb)
{
//	cout<<aaa.x<<" "<<bbb.x<<endl;
	if(aaa.x<bbb.x)
	{
//		cout<<(aaa.x<bbb.x)<<endl;
		return aaa.x<bbb.x;
	}
	else
	{
		if(aaa.x==bbb.x)
		return aaa.y<bbb.y;
	}
//	cout<<(aaa.x<bbb.x)<<endl;
	return aaa.x<bbb.x;
}
int cmpb(tni aa,tni bb)
{
	if(aa.y<bb.y)
	{
		return 1;
	}
	else
	{
		if(aa.y=bb.y)
		return aa.x<bb.x;
	}
}
int main()
{
	freopen("ds.in","r",stdin);
	freopen("ds.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].x;
		ss[i]=a[i].x;
		b[i].x=a[i].x;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].y;
		b[i].y=a[i].y;
	}
//	sort(ss+1,ss+n+1);
	sort(a+1,a+n+1,cmp);
	sort(b+1,b+n+1,cmpb);
	for(int i=1;i<=n;i++)
	{
		cout<<a[i].x<<" ";
	}
	cout<<endl<<endl;
	for(int i=1;i<=n;i++)
	{
		pa[a[i].x]=i;
	}
	for(int i=1;i<=n;i++)
	{
		if(pa[i]!=0)
		{
			tp=0;
		}
		else
		{
			tp--;
			pa[i]=tp;
		}
		
	}
	for(int i=1;i<=n;i++)
	{
		pb[b[i].y]=i;
	}
	tp=0;
	for(int i=1;i<=n;i++)
	{
		if(pb[i]!=0)
		{
			tp=0;
		}
		else
		{
			tp--;
			pb[i]=tp;
		}
		
	}
	
	for(int i=1;i<=n;i++)
	{
		cout<<pa[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<=n;i++)
	{
		cout<<pb[i]<<" ";
	}
	cout<<endl;
	for(int ii=1;ii<=q;ii++)
	{
		cin>>u>>r>>d>>l;//ud->x     rl->y
		if(pa[u]>0)
		{
			qx=u;
		}
		else
		{
			if(u+pa[u]>=d)
			{
//				cout<<u+pa[u]<<"  "<<ii<<endl;
				qx=u+pa[u];
			}
			else
			{
				cout<<"0"<<endl;
				continue;
			}
		}
		for(int i=pa[qx];i>=1;i--)
		{
			if(a[i].y<l)
			{
				break;
			}
			if(a[i].y<=r)
			{
				qy=a[i].y;
				break;
			}
		}
		int ans=0;
		for(int i=qy;i>=1;i--)
		{
			if(b[i].x>=d)
			{
				ans++;
			}
			else
			{
				break;
			}
		}
		for(int i=qx;i>=1;i--)
		{
			if(a[i].y>=l)
			{
				ans++;
			}
			else
			{
				break;
			}
		}
		ans--;
		cout<<ans<<endl;
	}
}
