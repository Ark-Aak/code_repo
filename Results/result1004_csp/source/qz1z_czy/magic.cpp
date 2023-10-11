#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define red(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
const int N=1e5+10;
int n;
int c[N];
struct Mp{
	int a,b,c,d;
}mp[N];
int cnt;
int k[N][10];
int f[N<<1];
int ans;
int pos[N<<1];
int fd(int x) { return x==f[x]?x:fd(f[x]); }
void merge(int x,int y)
{
	int x1=fd(x),y1=fd(y);
	if(x1!=y1) f[x1]=y1;
}
signed main(void)
{
	freopen("magic.in","r",stdin);
	freopen("magic.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	scanf("%d",&n);
	rep(i,1,n<<1) f[i]=i;
	rep(i,1,n)
	{
		scanf("%d",&c[i]);
		scanf("%d %d %d %d",&mp[i].a,&mp[i].b,&mp[i].c,&mp[i].d);
		merge(mp[i].a,mp[i].b),merge(mp[i].c,mp[i].d);
	}
	sort(c+1,c+1+n);
	rep(i,1,n<<1) if(f[i]==i) cnt++;
	cnt--;
	rep(i,1,cnt) ans+=c[i];
	printf("%d",ans);
	return 0;
}
