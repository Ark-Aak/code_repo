#include<bits/stdc++.h>
using namespace std;
int n,k;
int f[100005][4],b[100005][2],v[100005],t;
int main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>f[i][1];
		b[i][0]=f[i][1];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>f[i][2];
		b[i][1]=f[i][2];
	}
	if(k==0)
	{
		for(int i=1;i<=n;i++)
		{
			cout<<f[i][1]<<" ";
		}
		return 0;
	}
	if(k==1)
	{
		for(int i=1;i<=n;i++)
		{
			cout<<f[i][2]<<" ";
		}
		return 0;
	}
	if(k>1000)
	{
		for(int i=0;i<k-1;i++)
		{
			if(i%3==0)
			{
				for(int j=1;j<=n;j++)
				{
					f[f[j][1]][0]=f[j][2];
				}
			}
			if(i%3==1)
			{
				for(int j=1;j<=n;j++)
				{
					f[f[j][2]][1]=f[j][0];
				}
			}
			if(i%3==2)
			{
				for(int j=1;j<=n;j++)
				{
					f[f[j][0]][2]=f[j][1];
				}
			}
			t++;
			if(i==0)
			{
				for(int j=1;j<=n;j++)
				{
					v[j]=f[j][i%3];
				}
			}
			int p=1;
			for(int j=1;j<=n;j++)
			{
//				cout<<v[j]<<" "<<f[j][i%3]<<" "<<i<<endl;
				if(v[j]!=f[j][i%3])
				{
					p=0;
					break;
				}
			}
			if(p&&i!=0)
			{
				k%=(t-1);
				break;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		f[i][1]=b[i][0];
		f[i][2]=b[i][1];
	}
//	cout<<k<<" "<<t<<endl;
	for(int i=0;i<k-1;i++)
	{
		if(i%3==0)
		{
			for(int j=1;j<=n;j++)
			{
				f[f[j][1]][0]=f[j][2];
			}
		}
		if(i%3==1)
		{
			for(int j=1;j<=n;j++)
			{
				f[f[j][2]][1]=f[j][0];
			}
		}
		if(i%3==2)
		{
			for(int j=1;j<=n;j++)
			{
				f[f[j][0]][2]=f[j][1];
			}
		}
//		t++;
//		if(i==0)
//		{
//			for(int j=1;j<=n;j++)
//			{
//				v[j]=f[j][i%3];
//			}
//		}
//		int p=1;
//		for(int j=1;j<=n;j++)
//		{
//			if(v[j]!=f[j][i%3])
//			{
//				p=0;
//				break;
//			}
//		}
//		if(p)
//		{
//			t=1;
//		}
//		cout<<i<<"  ->  ";
//		for(int j=1;j<=n;j++)
//		{
//			cout<<f[j][i%3]<<" ";
//		}
//		cout<<"     "<<t<<endl;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<f[i][(k-2)%3]<<" ";
	}
}
