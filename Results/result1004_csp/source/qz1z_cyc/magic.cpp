#include<bits/stdc++.h>
using namespace std;
long long n,c[100005],p[100005][5],kk[400005],o[400005],tot,fg[400005];
vector<int> q[400005];
struct sb
{
	int u,v,w;
}kw[400005];
void work(int yy,int x,int fa)
{
	o[x]=yy;
	for(int i=0;i<q[x].size();i++)
	{
		if(q[x][i]!=fa&&o[q[x][i]]==0) work(yy,q[x][i],x);
	}
	return;
}
bool cmp(sb x,sb y)
{
	return x.w<y.w;
}
int find(int x)
{
	if(fg[x]==x) return x;
	else return fg[x]=find(fg[x]);
}
int main() 
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		fg[i]=i;
		scanf("%d%d%d%d%d",&c[i],&p[i][1],&p[i][2],&p[i][3],&p[i][4]);
		for(int j=1; j<=4; j++) 
		{
			if(kk[p[i][j]]==1) 
			{
				p[i][j]+=2*n;q[p[i][j]].push_back(p[i][j]-2*n);
			} 
			else 
			{
				kk[p[i][j]]=1;q[p[i][j]].push_back(p[i][j]+2*n);
			}
		}
		q[p[i][1]].push_back(p[i][2]);
		q[p[i][2]].push_back(p[i][1]);
		q[p[i][3]].push_back(p[i][4]);
		q[p[i][4]].push_back(p[i][3]);
	}
	for(int i=1;i<=4*n;i++)
	{
		if(o[i]==0)
		{
			tot++;
			work(tot,i,0);
		}
	}
	for(int i=1;i<=n;i++)
	{
		kw[i].u=o[p[i][1]];kw[i].v=o[p[i][3]];
		kw[i].w=c[i];
	}
	long long tot2=0,ans=0;
	sort(kw+1,kw+1+n,cmp);
	for(int i=1;i<=n;i++)
	{
		int l=find(kw[i].u),r=find(kw[i].v);
		if(l!=r)
		{
			fg[l]=r;
			tot2++;
			ans+=kw[i].w;
		}
		if(tot2>=tot-1) break;
	}
	cout<<ans;
	return 0;
}
