#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

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

const int MAXN = 1e6 + 5;
const int MOD = 1e9 + 7;
int T;
int n, m, Q;
int x[MAXN], y[MAXN], row[MAXN], col[MAXN];
int sum1[MAXN], sum2[MAXN], xx[MAXN], yy[MAXN];
int cnt1, cnt2, ans1, ans2;

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % MOD;
		a = 1ll * a * a % MOD;
		b >>= 1;
	}
	return res;
}

int dis[2010][2010], vis[2010][2010];
int way[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int s1[MAXN], s2[MAXN];

struct node {
	int x, y;
};

void bfs(int sx, int sy) {
	queue <node> q;
	rep (i, 1, cnt1) rep (j, 1, cnt2) dis[i][j] = -1;
	q.push((node) {sx, sy});
	dis[sx][sy] = 0;
	while (q.size()) {
		node tp = q.front();
		q.pop();
		const int x = tp.x, y = tp.y;
		rep (i, 0, 3) {
			const int nx = x + way[i][0];
			const int ny = y + way[i][1];
			if (nx < 1 || nx > cnt1 || ny < 1 || ny > cnt2) continue;
			if (dis[nx][ny] != -1 || vis[nx][ny]) continue;
			dis[nx][ny] = dis[x][y] + 1;
			q.push(node {nx, ny});
		}
	}
	rep (i, 1, cnt1) {
		rep (j, 1, cnt2) {
			if (dis[i][j] != -1) {
				int nw = s1[sx] * s2[sy] % MOD * s1[i] % MOD * s2[j] % MOD;
				ans2 += dis[i][j] * nw % MOD;
				ans2 %= MOD;
			}
		}
	}
}

void solve() {
	n = read(), m = read(), Q = read();
	cnt1 = cnt2 = ans1 = ans2 = 0;
	rep (i, 1, n) x[i] = row[i] = sum1[i] = 0;
	rep (i, 1, m) y[i] = col[i] = sum2[i] = 0;
	rep (i, 1, Q) {
		xx[i] = read(), yy[i] = read();
		x[xx[i]] = y[yy[i]] = 1;
		sum1[xx[i]]++, sum2[yy[i]]++;
	}
	rep (i, 1, n) sum1[i] += sum1[i - 1];
	rep (i, 1, m) sum2[i] += sum2[i - 1];
	for (int i = 1; i <= n; ) {
		if (x[i]) {
			row[i] = ++cnt1;
			i++, s1[cnt1] = 1;
		}
		else {
			row[i] = ++cnt1;
			int j = i - 1;
			while (!x[j + 1] && j < n) j++;
			s1[cnt1] = j - i + 1;
			rep (K, i, j - 1) {
				ans1 = (ans1 + (K * m % MOD - sum1[K] + MOD) % MOD *
						((n - K) * m % MOD - (sum1[n] - sum1[K]) + MOD) % MOD) % MOD;
			}
			i = j + 1;
		}
	}
	for (int i = 1; i <= m; ) {
		if (y[i]) {
			col[i] = ++cnt2;
			i++, s2[cnt2] = 1;
		}
		else {
			col[i] = ++cnt2;
			int j = i - 1;
			while (!y[j + 1] && j < m) j++;
			s2[cnt2] = j - i + 1;
			rep (K, i, j - 1) {
				ans1 = (ans1 + (K * n % MOD - sum2[K] + MOD) % MOD *
						((m - K) * n % MOD - (sum2[m] - sum2[K]) + MOD) % MOD) % MOD;
			}
			i = j + 1;
		}
	}
	rep (i, 1, cnt1) {
		rep (j, 1, cnt2) {
			vis[i][j] = 0;
		}
	}
	rep (i, 1, Q) vis[row[xx[i]]][col[yy[i]]] = 1;
	rep (i, 1, cnt1) {
		rep (j, 1, cnt2) {
			if (!vis[i][j]) bfs(i, j);
		}
	}
	print((ans1 + ans2 * qpow(2, MOD - 2) % MOD) % MOD), puts("");
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("dist.in", "r", stdin);
	freopen("dist.out", "w", stdout);
#endif
#endif
	/* freopen("data.in", "r", stdin); */
	/* freopen("test.out", "w", stdout); */
	T = read();
	while (T --> 0) solve();
	return 0;
}
