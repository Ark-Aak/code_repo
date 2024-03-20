#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a); i <= b; i++)
#define _rep(i, a, b) for(int i = (a); i >= b; i--)

using namespace std;

typedef long long ll;

#define int ll

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 30;
int n, m;
int f[MAXN][MAXN], deg[MAXN], ansW, ans = 1e9;
int o[MAXN], ocnt;
bitset <MAXN> vis;

void dfs(int x, int sum) {
	if (x > ocnt) {
		ans = min(ans, sum);
		return;
	}
	if (vis[x]) {
		dfs(x + 1, sum);
		return;
	}
	vis[x] = 1;
	rep (i, 1, ocnt) {
		if (i != x && (!vis[i])) {
			vis[i] = 1;
			dfs(x + 1, sum + f[o[x]][o[i]]);
			vis[i] = 0;
		}
	}
	vis[x] = 0;
}

signed main() {
	cin >> n >> m;
	memset(f, 0x3f, sizeof f);
	rep (i, 1, m) {
		int u, v, w;
		cin >> u >> v >> w;
		f[u][v] = min(w, f[u][v]); f[v][u] = min(f[v][u], w);
		deg[u]++, deg[v]++;
		ansW += w;
	}
	rep (k, 1, n)
		rep (i, 1, n)
			rep (j, 1, n)
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
	rep (i, 2, n) if (deg[i] > 0 && f[1][i] >= 0x3f3f3f3f3f3f3f3f) {
		cout << -1;
		return 0;
	}
	rep (i, 1, n) {
		if (deg[i] & 1) o[++ocnt] = i;
	}
	dfs(1, 0);
	cout << ans + ansW;
	return 0; 
}
