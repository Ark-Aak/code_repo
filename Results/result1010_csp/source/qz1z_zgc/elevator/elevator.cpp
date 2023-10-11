#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
typedef long long LL;
int n,m,cnt[N];
LL res=0; 
vector<int>V;
int cmp(int a,int b){return cnt[a]>cnt[b];}
int main()
{
	freopen("elevator.in","r",stdin);
	freopen("elevator.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int x;
		scanf("%d",&x);
		if((++cnt[x])==1)V.push_back(x);
	}
	sort(V.begin(),V.end(),cmp);
	LL time=0;
	for(int i=0;i<V.size();i++)
	{
		LL f=2*(V[i]-1);
		time+=f;
		res+=time*cnt[V[i]];
	}
	printf("%lld",res);
	return 0;
} 
