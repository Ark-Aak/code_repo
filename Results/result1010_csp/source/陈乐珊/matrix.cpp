#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
bool p[30][200005];
int w[200005],ans=1e9;
int e[30],c[30][30],tw[200005];
void dfs(int now) {
	if(now>n) {
		int sum=0;
		for(int i=0;i<=n;i++) {
			sum+=min(i,n-i)*e[i];
		}
		ans=min(ans,sum);
		return ;
	}
	dfs(now+1);
	for(int i=1;i<=m;i++) {
		e[w[i]]--;
		if(p[now][i]==1) {
			w[i]--;
		}
		if(p[now][i]==0) {
			w[i]++;
		}
		e[w[i]]++;
	}
	dfs(now+1);
	for(int i=1;i<=m;i++) {
		e[w[i]]--;
		if(p[now][i]==1) {
			w[i]++;
		}
		if(p[now][i]==0) {
			w[i]--;
		}
		e[w[i]]++;
	}
}
int main() {
	freopen("matrix.in", "r", stdin);
	freopen("matrix.out", "w", stdout);
	cin>>n>>m;
	char s;
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			cin>>s;
			if(s=='1') {
				p[i][j]=1;
				w[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++) e[w[i]]++;
//	for(int i=1;i<=n;i++) {
//		for(int j=1;j<=m;j++) tw[j]=w[j];
//		for(int j=1;j<=m;j++) {
//			c[i][tw[j]]--;
//			if(p[i][j]==1) {
//				tw[j]++;
//			} else {
//				tw[j]--;
//			}
//			c[i][tw[j]]++;
//		}
//	}
	dfs(1);
	cout<<ans;
	return 0;
}

