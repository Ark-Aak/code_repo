#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[1005][1005];
signed main(){
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)cin>>a[0][i];
	for(int i=1;i<=n;i++)cin>>a[1][i];
	for(int i=2;i<=k;i++)
		for(int j=1;j<=n;j++)
			a[i][a[i-2][j]]=a[i-1][j];
	for(int i=1;i<=n;i++)cout<<a[k][i]<<" ";
} 
