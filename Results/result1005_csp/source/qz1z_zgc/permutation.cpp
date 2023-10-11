#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+5; 
int n,k;
int f[2][N],t[N];
vector<vector<int> >P;
vector<int>tmp;
int main()
{
	freopen("permutation.in","r",stdin);
	freopen("permutation.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&f[0][i]);
	for(int i=1;i<=n;i++)scanf("%d",&f[1][i]);
	if(k==1)
	{
		for(int i=1;i<=n;i++)printf("%d ",f[1][i]);
		return 0;
	}
	for(int i=2;i<=k;i++)
	{
		for(int j=1;j<=n;j++)t[f[(i-2)&1][j]]=f[(i-1)&1][j];
		tmp.clear();
		for(int j=1;j<=n;j++)
		{
			f[i&1][j]=t[j];
			tmp.push_back(t[j]);
			if(i==k)printf("%d ",t[j]);
		}
		if(i==k)return 0;
		if(P.size()>2&&P[0]==P[P.size()-1]&&P[1]==tmp)break;
		P.push_back(tmp);
	}
	P.pop_back();
	for(int i=0;i<n;i++)printf("%d ",P[(k-2)%P.size()][i]);
	return 0;
}
