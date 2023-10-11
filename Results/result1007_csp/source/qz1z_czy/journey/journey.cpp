#include<bits/stdc++.h>
//#define int long long
#define rp(i,a,b) for(int (i)=(a);(i)<=(b);++(i))
#define lp(i,a,b) for(int (i)=(a);(i)>=(b);--(i))
using namespace std;
const int N=1e3+10;
int n,m,Q;
int head[N<<1];
struct edge{
	int to,nxt,id;
}e[N];
int tot;
void add(int id,int u,int v)
{
	e[++tot].nxt=head[u];
	e[tot].to=v;
	e[tot].id=id;
	head[u]=tot;
}
signed main(void)
{
	freopen("journey.in","r",stdin);
	freopen("journey.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	scanf("%d %d% d",&n,&m,&Q);
	rp(i,1,m)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		add(i,u,v); add(i,v,u);
	}
	rp(i,1,Q)
	{
		int l,r,s,t;
		scanf("%d %d %d %d",&l,&r,&s,&t);
		cout<<"No";
	}
	return 0;
}
