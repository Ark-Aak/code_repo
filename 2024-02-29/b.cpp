#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

int read() {
	int x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	return x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 5e5 + 5, MAXM = 2005, MOD = 1e9 + 7;
int n, m, T, ans;
map <int, int> e[MAXN];
int a[MAXM][MAXM], g[MAXN];
int deg[MAXN], pl[MAXM][MAXM], id[MAXM][MAXM], cnt;
int way[2][8] = {{1, 0, -1, 0, -1, 1, 1, -1}, {0, 1, 0, -1, 1, -1, 1, -1}};
int s, t;

int qpow(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return ans;
}

void dfs1(int x, int y) {
	id[x][y] = cnt;
	rep(i, 0, 7) {
		int xx = x + way[0][i], yy = y + way[1][i];
		if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
		if (!a[xx][yy] || id[xx][yy]) continue;
		dfs1(xx, yy);
	}
}

void dfs2(int x, int y, int val) {
	pl[x][y] += val;
	if (val == 1) {
		rep (i, 0, 1) {
			int xx = x + way[0][i], yy = y + way[1][i];
			if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
			if (pl[xx][yy] >= val || a[xx][yy]) continue;
			dfs2(xx, yy, val);
		}
	}
	else {
		rep (i, 2, 3) {
			int xx = x + way[0][i], yy = y + way[1][i];
			if (xx < 1 || xx > n || yy < 1 || yy > m) continue;
			if (pl[xx][yy] >= val || a[xx][yy]) continue;
			dfs2(xx, yy, val);
		}
	}
}

void topo() {
	queue <int> q;
	q.push(s);
	rep(i, 0, cnt) for (auto [u, _ig] : e[i]) deg[u]++;
	g[s] = 1;
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (auto [u, _ig] : e[x]) {
			deg[u]--;
			g[u] = (g[u] + g[x]) % MOD;
			if (!deg[u]) q.push(u);
		}
	}
}

void solve() {
	rep (i, 1, cnt) e[i].clear();
	cnt = 0;
	memset(pl, 0, sizeof pl);
	memset(id, 0, sizeof id);
	memset(deg, 0, sizeof deg);
	memset(g, 0, sizeof g);
	cin >> n >> m;
	rep(i, 1, n) rep(j, 1, m) {
		char ch;
		cin >> ch;
		if (ch == '-') a[i][j] = 0;
		else a[i][j] = 1;
	}
	dfs2(1, 1, 1);
	dfs2(n, m, 2);
	int tot = 0;
	rep (i, 1, n) {
		rep (j, 1, m) {
			if (!a[i][j] && pl[i][j] < 3) {
				a[i][j] = 1;
				tot++;
			}
		}
	}
	rep (i, 1, n) {
		rep (j, 1, m) {
			if (!a[i][j]) id[i][j] = ++cnt;
			else if (!id[i][j]) {
				++cnt;
				dfs1(i, j);
			}
		}
	}
	s = ++cnt, t = ++cnt;
	rep (i, 1, m) e[s][id[1][i]]++;
	rep (i, 2, n) e[s][id[i][m]]++;
	rep (i, 1, m) e[id[n][i]][t]++;
	rep (i, 1, n - 1) e[id[i][1]][t]++;
	rep (i, 1, n) {
		rep (j, 1, m) {
			if (a[i][j]) {
				if (i != n && j != m && !a[i + 1][j])
					e[id[i][j]][id[i + 1][j]]++;
				if (i != 1 && j != 1 && !a[i][j - 1])
					e[id[i][j]][id[i][j - 1]]++;
				if (i != n && j != 1 && !a[i + 1][j - 1])
					e[id[i][j]][id[i + 1][j - 1]]++;
			}
			else {
				int flag = 0;
				if (i != n && j != 1 && a[i + 1][j])
					e[id[i][j]][id[i + 1][j]]++, flag = 1;
				if (i != n && j != 1 && a[i][j - 1])
					e[id[i][j]][id[i][j - 1]]++, flag = 1;
				if (i != n && j != 1 && !flag)
					e[id[i][j]][id[i + 1][j - 1]]++;
			}
		}
	}
	topo();
	print(g[t] * qpow(2, tot) % MOD);
	putchar(10);
}

signed main() {
	cin >> T;
	while (T --> 0) solve();
	return 0;
}
