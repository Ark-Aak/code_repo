#include<bits/stdc++.h>
using namespace std;
int a[200005][2][2],n,f[200005][2][3],vc,x,y,b[200005][2],colour,bv[200005][2],tp;
int ansn[200005],vt[200005];
long long int ans;
bool v[200005][2];
queue<int>A;
queue<int>B;
int find(int in)
{
	if(vt[in]==in)
	{
		return in;
	}
	else
	vt[in]=find(vt[in]);
	return vt[in];
}
struct tni
{
	int c,num;
};
tni s[100005];
int cmp(tni aa,tni bb)
{
	return aa.c<bb.c;
}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	cin>>n;
//	cout<<"-1"<<endl;
	for(int i=1;i<=n;i++)
	{
//		cout<<i<<endl;
		cin>>s[i].c>>a[i][0][0]>>a[i][0][1];
		cin>>a[i][1][0]>>a[i][1][1];
		s[i].num=i;
		if(s[i].c!=1)
		{
			vc=1;
		}
//		cout<<"-------"<<endl;
		if(f[a[i][0][0]][0][0]==0)
		{
			f[a[i][0][0]][0][0]=i;
			f[a[i][0][0]][0][1]=0;
			f[a[i][0][0]][0][2]=0;
		}
		else
		{
			f[a[i][0][0]][1][0]=i;
			f[a[i][0][0]][1][1]=0;
			f[a[i][0][0]][1][2]=0;
		}
//		cout<<"============"<<endl;
		if(f[a[i][0][1]][0][0]==0)
		{
			f[a[i][0][1]][0][0]=i;
			f[a[i][0][1]][0][1]=0;
			f[a[i][0][1]][0][2]=1;
		}
		else
		{
			f[a[i][0][1]][1][0]=i;
			f[a[i][0][1]][1][1]=0;
			f[a[i][0][1]][1][2]=1;
		}
//		cout<<"|||||||||||||||"<<endl;
		if(f[a[i][1][0]][0][0]==0)
		{
			f[a[i][1][0]][0][0]=i;
			f[a[i][1][0]][0][1]=1;
			f[a[i][1][0]][0][2]=0;
		}
		else
		{
			f[a[i][1][0]][1][0]=i;
			f[a[i][1][0]][1][1]=1;
			f[a[i][1][0]][1][2]=0;
		}
//		cout<<"++++++++++++"<<endl;
		if(f[a[i][1][1]][0][0]==0)
		{
			f[a[i][1][1]][0][0]=i;
			f[a[i][1][1]][0][1]=1;
			f[a[i][1][1]][0][2]=1;
		}
		else
		{
			f[a[i][1][1]][1][0]=i;
			f[a[i][1][1]][1][1]=1;
			f[a[i][1][1]][1][2]=1;
		}
//		cout<<"_______"<<endl;
	}
//	cout<<"1"<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=1;j++)
		{
			if(b[i][j]==0)
			{
				colour++;
				v[i][j]=1;
				b[i][j]=colour;
				bv[i][j]=colour;
				A.push(i);
				B.push(j);
				while(!A.empty())
				{
					x=A.front();
					y=B.front();
					A.pop();
					B.pop();
					for(int k=0;k<=1;k++)
					{
						for(int kk=0;kk<=1;kk++)
						{
							if(b[f[a[x][y][k]][kk][0]][f[a[x][y][k]][kk][1]]==0)
							{
								A.push(f[a[x][y][k]][kk][0]);
								B.push(f[a[x][y][k]][kk][1]);
								b[f[a[x][y][k]][kk][0]][f[a[x][y][k]][kk][1]]=colour;
								bv[f[a[x][y][k]][kk][0]][f[a[x][y][k]][kk][1]]=colour;
							}
						}						
					}
				}
			}
		}
	}
//	cout<<"2"<<endl;
//	for(int i=1;i<=n;i++)
//	{
//		cout<<bv[i][0]<<" "<<bv[i][1]<<endl;
//	}
	if(vc==0)
	{
		cout<<colour-1<<endl;
	}
	else
	{
		sort(s+1,s+n+1,cmp);
		for(int i=1;i<=n;i++)
		{
			vt[i]=i;
		}
		for(int i=1;i<=n;i++)
		{
//			cout<<find(b[s[i].num][0])<<"      "<<find(b[s[i].num][1])<<"  ||  "<<b[s[i].num][0]<<" "<<b[s[i].num][1]<<endl;
			if(find(b[s[i].num][0])!=find(b[s[i].num][1]))
			{
				ans+=s[i].c;
				vt[b[s[i].num][0]]=find(b[s[i].num][1]);
//				find(b[s[i].num][0]);
				tp++;
			}
//			else
//			{
//				cout<<"-1"<<endl;
//			}
			if(tp>=colour-1)
			{
				break;
			}
		}
		cout<<ans<<endl;
	}
}
