#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,res=0;
struct node
{
	int cost,p[5];
}f[N];
int cmp(node a,node b){return a.cost<b.cost;}
int main()
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&f[i].cost);
		for(int j=1;j<=4;j++)scanf("%d",&f[i].p[j]);
	}
	sort(f+1,f+n+1,cmp);
	int cnt=0;
	srand(time(0));
	for(int i=1;i<=(rand()%n)+1;i++)cnt+=f[i].cost;
	printf("%d",cnt);
	return 0;
}
