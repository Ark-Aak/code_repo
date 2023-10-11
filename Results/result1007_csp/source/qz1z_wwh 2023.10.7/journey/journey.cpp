#include<bits/stdc++.h>
using namespace std;
int n,m,q,a[1005][1005],f[1005][1005],fv[1005],u,v,ve[1005],pt;
int l,r,s,t,now,ed;
queue<int>A;
queue<int>E;
int main()
{
	freopen("journey.in","r",stdin);
	freopen("journey.out","w",stdout);
	cin>>n>>m>>q;
	if(n>2000)
	{
		for(int i=1;i<=m;i++)
		{
			cin>>u>>v;		
		}
		for(int i=1;i<=q;i++)
		{
			cin>>l>>r>>s>>t;
			if(s!=t)
			{
				cout<<"No"<<endl;
			}
			else
			{
				cout<<"Yes"<<endl;
			}
		}
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>u>>v;
		a[u][v]=i;
		a[v][u]=i;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(a[i][j]!=0)
			{
				fv[i]++;
				f[i][fv[i]]=j;
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>l>>r>>s>>t;
		for(int j=1;j<=1000;j++)
		{
			ve[j]=0;
		}
		A.push(s);
		E.push(l);
		pt=0;
		while(!A.empty())
		{
			now=A.front();
//			cout<<"                  "<<now<<endl;
			ed=E.front();
			if(now==t)
			{
				pt=1;
				break;
			}
			A.pop();
			E.pop();
			for(int j=1;j<=fv[now];j++)
			{
				int te=a[now][f[now][j]];
//				cout<<te<<endl;
				if(ed<=te&&ve[te]==0&&te<=r)
				{
					ve[te]=1;
					A.push(f[now][j]);
					E.push(te);
				}
			}
		}
		if(pt==1)
		{
			cout<<"Yes"<<endl;
			while(!A.empty())
			{
				A.pop();
				E.pop();
			}
		}
		else
		{
			cout<<"No"<<endl;
		}
	}
}
