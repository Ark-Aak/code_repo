#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,sse2,sse3,sse4")

#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for (int i = (a), i##end = (b); i >= i##end; i--)

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll read() {
	ll x = 0, f = 1;
	char c = getchar();
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
	if (x < 0)
		x = (~x + 1), putchar('-');
	if (x > 9)
		print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 1010;
const int MAXM = 210;

int T, n, ans, m;
int a[MAXN], b[MAXN], c[MAXN];
int f[MAXN][MAXM][MAXM];
int g[MAXN][MAXM][MAXM], h[MAXN][MAXM][MAXM];

inline void upd(int &x, int y) {
	if (y > x) x = y;
}

inline int Min(int x, int y) {
	return x < y ? x : y;
}

void solve() {
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
	memset(c, 0, sizeof(c));
	memset(f, 0, sizeof(f));
	memset(g, 0, sizeof(g));
	memset(h, 0, sizeof(h));
	n = read();
	m = Min(sqrt(10000) * 2 + 5, n);
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		b[i] = read();
		c[i] = read();
	}
	ans = 0;
	f[1][0][0] = a[1];
	g[1][0][0] = b[1];
	h[1][0][0] = c[1];
	rep(i, 1, n - 1) {
		rep(j, 0, m) {
			rep(k, 0, m) {
				int nj = j == 0 ? 0 : j + 1, nk = k == 0 ? 0 : k + 1;
				upd(f[i + 1][nj][nk], f[i][j][k] + a[i + 1] - nj - nk);
				upd(g[i + 1][1][nk], f[i][j][k] + b[i + 1] - 1 - nk);
				upd(h[i + 1][1][nj], f[i][j][k] + c[i + 1] - 1 - nj);
				upd(f[i + 1][1][nk], g[i][j][k] + a[i + 1] - 1 - nk);
				upd(g[i + 1][nj][nk], g[i][j][k] + b[i + 1] - nj - nk);
				upd(h[i + 1][nj][1], g[i][j][k] + c[i + 1] - nj - 1);
				upd(f[i + 1][nk][1], h[i][j][k] + a[i + 1] - nk - 1);
				upd(g[i + 1][nj][1], h[i][j][k] + b[i + 1] - nj - 1);
				upd(h[i + 1][nj][nk], h[i][j][k] + c[i + 1] - nj - nk);
			}
		}
	}
	rep(j, 0, m) {
		rep(k, 0, m) {
			ans = max(ans, max(f[n][j][k], max(g[n][j][k], h[n][j][k])));
		}
	}
	print(ans); putchar(10);
}

signed main() {
	T = read();
	while (T--) solve();
	return 0;
}