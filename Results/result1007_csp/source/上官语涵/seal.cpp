#include<bits/stdc++.h>
#define int long long
using namespace std;

const int mxn = 2010;
const int mxt = 1e6 + 10;
struct node {
	int st, en;
} a[mxn];
int vis[mxn];
struct fff {
	int ti, op, p;
} b[mxn * 2];
bool cmp(fff x, fff y) {
	return x.ti < y.ti;
}
int count(int x) {
	int res = 0;
	for(int i = 20; i >= 0; i--) if((1ll << i) & x) ++res;
	return res;
}
void ff(int x) {
	for(int i = 20; i >= 0; i--) {
		if((1ll << i) & x) vis[i + 1] = 1;
	}
}
signed main() {
	freopen("seal.in", "r", stdin);
	freopen("seal.out", "w", stdout);
	int N, T, M, cnt = 0;
	cin >> N >> T >> M;
	for(int i = 1; i <= N; i++) {
		cin >> a[i].st >> a[i].en;
		b[++cnt].ti = a[i].st;
		b[cnt].op = 1;
		b[cnt].p = i;
		b[++cnt].ti = a[i].en;
		b[cnt].op = 2;
		b[cnt].p = i;
	}
	sort(b + 1, b + cnt + 1, cmp);

	int res = 0;
	for(int sub = 0; sub < (1ll << N); sub++) {
		if(count(sub) == M) {
			memset(vis, 0, sizeof(vis));
			ff(sub);
			int ans = T;
			int now = 1;
			for(int i = 1; i <= cnt; i++) {
				if(now == 0) ans -= (b[i].ti - b[i - 1].ti);
				if(vis[b[i].p]) {
					if(!vis[b[i + 1].p] && b[i + 1].op == 2) now = 0;
					else now = 1;
				}
				if(b[i].op == 1 && !vis[b[i].p]) now = 0;
			}
			res = max(res, ans);
		}
	}
	cout << res;
}
