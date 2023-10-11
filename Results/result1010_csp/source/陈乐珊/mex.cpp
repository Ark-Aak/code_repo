#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5005,mod=1e9+7;
ll n,b[N],ans,a[N],cnt,maxn;
bool p[N];
void dfs(int now) {
	if(now>n) {
		memset(p,0,sizeof(p));
		for(int i=1;i<=n;i++) {
			p[a[i]]=1;
		}
		int ret;
		for(int i=0;i<=maxn;i++) {
			if(!p[i]) {
				ret=i;
				break;
			}
		}
		ans=(ans+ret)%mod;
		return ;
	}
	for(int i=0;i<=b[now];i++) {
		a[now]=i;
		dfs(now+1);
	}
}
int main() {
	freopen("mex.in", "r", stdin);
	freopen("mex.out", "w", stdout);
	cin>>n;
	for(int i=1;i<=n;i++) {
		cin>>b[i];
		maxn=max(maxn,b[i]);
	}
	dfs(1);
	cout<<ans;
	return 0;
}

