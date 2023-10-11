#include<bits/stdc++.h>
#define int long long
using namespace std;
int f[1005][10005],a[1005],maxn=0;
vector<int> q[1005];
signed main(){
	freopen("trade.in","r",stdin);
	freopen("trade.out","w",stdout);
	int n,m,c;
	scanf("%lld %lld %lld",&n,&m,&c);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=m;i++) {
		int x,y;
		scanf("%lld %lld",&x,&y);
		q[x].push_back(y);
	}
	memset(f,-0x3f,sizeof f);
	f[1][0]=0;
	for(int dep=1;dep<=10000;dep++) {
		for(int i=1;i<=n;i++) {
			for(int j=0;j<q[i].size();j++) {
				f[q[i][j]][dep]=max(f[q[i][j]][dep],f[i][dep-1]+a[q[i][j]]);
			}
		}
		maxn=max(maxn,f[1][dep]-c*(dep)*(dep));
	}
	printf("%lld",maxn);
	return 0;
}

