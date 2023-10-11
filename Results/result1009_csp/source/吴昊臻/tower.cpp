#include<bits/stdc++.h>
using namespace std;
int n,m,k,top,top1,w[50005],a[5005][5005];
char x[55][55];
int main()
{
	freopen("tower.in","r",stdin);
	freopen("tower.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>w[i];
	for(int i=1;i<=k;i++)
		for(int j=1;j<=k;j++)
			cin>>x[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(x[w[i]][w[j]]=='1')
				a[i][j]=abs(i-j);
			else 
				a[i][j]=-1;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			for(int z=1;z<=n;z++)
				if((a[j][z]==-1||a[j][i]+a[i][z]<a[j][z])&&a[j][i]!=-1&&a[i][z]!=-1)
					a[j][z]=a[j][i]+a[i][z];
	cout<<a[1][n];
	return 0;	
}
/*
5 4
1 4 2 3 4
1010
0001
0110
0100
*/
