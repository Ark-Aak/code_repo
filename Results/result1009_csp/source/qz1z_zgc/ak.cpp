#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
typedef long long LL;
int n,m,a[N];
LL res=0,t=0;
vector<int>V;
int main()
{
	freopen("ak.in","r",stdin);
	freopen("ak.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		res+=(LL)a[i]; 
	}
	for(int i=1;i<=n;i++)
	{
		if((i-1)%m||(n-i)%m)continue;
		V.push_back(a[i]);
	}
	sort(V.begin(),V.end());
	printf("%lld",res-V[V.size()/2]);
	return 0;
}
