#include <bits/stdc++.h>
#define int long long
#define y1 __________ 
#define y2 ______________________
using namespace std;
const int N = 1e3+5,mod = 998244353;
int n,a[N][N],cnt,x1[N],y1[N],x2[N],y2[N],ans;
char ch[N][N];
bool vis[N][N];
void dfs(int x,int sum)
{
	if(x>cnt) return (ans+=sum)%=mod,void();
	dfs(x+1,sum);
	if(vis[x1[x]][y1[x]]==0&&vis[x2[x]][y2[x]]==0)
		vis[x1[x]][y1[x]] = vis[x2[x]][y2[x]] = 1,dfs(x+1,(sum+a[x1[x]][y1[x]]+a[x2[x]][y2[x]])%mod),vis[x1[x]][y1[x]] = vis[x2[x]][y2[x]] = 0;
}
signed main()
{
	freopen("cat.in","r",stdin);
	freopen("cat.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=n;j++)
			cin>>ch[i][j];
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=n;j++)
			cin>>a[i][j];
	for(int i = 1;i<=n;i++)
		for(int j1 = 1;j1<=n;j1++)
			for(int j2 = j1+1;j2<=n;j2++)
				if((ch[i][j1]=='R'&&ch[i][j2]=='L'))
					x1[++cnt] = i,y1[cnt] = j1,x2[cnt] = i,y2[cnt] = j2;
	for(int i1 = 1;i1<=n;i1++)
		for(int i2 = i1+1;i2<=n;i2++)
			for(int j = 1;j<=n;j++)
				if(ch[i1][j]=='D'&&ch[i2][j]=='U')
					x1[++cnt] = i1,y1[cnt] = j,x2[cnt] = i2,y2[cnt] = j;
//	for(int i = 1;i<=cnt;i++)
//		cout<<_i[i]<<' '<<_j1[i]<<' '<<_j2[i]<<'\n'; 
	dfs(1,0);
	cout<<ans;
	return 0;
}

