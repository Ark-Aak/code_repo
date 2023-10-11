#include<bits/stdc++.h>
using namespace std;
int n,m,q,x,y,l,r,w[1005][1005],ans,nowx,nowy;
struct node{
	int l,r,id,x,y;
}a[200005],b[1000005];
string p[1000005];
bool cmp(node i, node j)
{
	if(i.l==j.l) return i.r<j.r;
	return i.l<j.l;
}
int main()
{
	freopen("journey.in","r",stdin);
	freopen("journey.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(i!=j)
				w[i][j]=INT_MAX;
	for(int i=1;i<=m;i++) cin>>a[i].l>>a[i].r;
	for(int i=1;i<=q;i++)
		cin>>b[i].l>>b[i].r>>b[i].x>>b[i].y,b[i].id=i;
	sort(b+1,b+q+1,cmp);
	for(int i=1;i<=q;i++)
	{
		if(b[i].l==b[i].r)	{p[b[i].id]="Yes"; continue;}
		if(nowx!=b[i].l) 
		{
			nowx=b[i].l,nowy=b[i].l;
			for(int z=1;z<=n;z++)
				for(int j=1;j<=n;j++)
					if(i!=j)
						w[z][j]=INT_MAX;
		}
		while(b[i].r!=nowy-1){
			w[a[nowy].l][a[nowy].r]=w[a[nowy].r][a[nowy].l]=1;
			for(int j=1;j<=n;j++)
				if(w[j][a[nowy].l]==1)
					w[j][a[nowy].r]=1;
			for(int j=1;j<=n;j++)
				if(w[j][a[nowy].r]==1)
					w[j][a[nowy].l]=1;
			nowy++;
		}
		if(w[b[i].x][b[i].y]<=1) p[b[i].id]="Yes";
		else p[b[i].id]="No";
	}
	for(int i=1;i<=q;i++)
		cout<<p[i]<<endl;
	return 0;
 } 
/*
5 4 6
1 2
2 3
3 4
3 5
1 3 1 4
1 3 2 4
1 4 4 5
1 4 4 1
2 3 1 4
2 2 2 3
*/
