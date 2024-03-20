// Shirasu Azusa 2024.03
#include <bits/stdc++.h>
#define fi first
#define se second
#define eb emplace_back
#define mp make_pair
using namespace std;
template<class T, class S>
bool chmax(T &a, const S b) { return (a < b ? a = b, 1 : 0); }
template<class T, class S>
bool chmin(T &a, const S b) { return (a > b ? a = b, 1 : 0); }

#define int long long
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define per(i, a, b) for (int i = (a); i >= (b); i--)

int read() {
	int x = 0, w = 1;
	char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') w = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = x * 10 + (c - '0');
		c = getchar();
	}
	return x * w;
}

const int N = 2005, inf = 0x3f3f3f3f3f3f3f3f;
int n, x, y, m, d, f[N][2 * N], g[N], ans = inf, a[N], b[N];

int calc(int t) {
	return max(0ll, t % d - x);
}

int J(int i, int t) {
	int p = t - g[i];
	assert(p >= 0);
	return p / d * 2 + (p % d >= x);
}

int T(int i, int j) {
	return g[i] + j / 2 * d + (j & 1) * x;
}

void work() {
	memset(g, 0, sizeof(g));
	ans = inf;
	memset(a, 0, sizeof(a));
	n = read(), x = read(), y = read(), m = read(), d = x + y;
	rep(i, 1, n) a[i] = read();
	memset(f, 0x3f, sizeof(f));
	f[0][0] = 0;
	rep(i, 1, n) {
		g[i] = g[i - 1] + a[i];
		if (calc(g[i])) g[i] -= calc(g[i]);
	}
	rep(i, 1, n) g[i] = g[i] / d * d;
	rep(i, 1, n) {
		int p0 = i, p1 = i, q0 = a[i], q1 = x + a[i];
		while (p0 < n && !calc(q0)) q0 += a[++p0];
		while (p1 < n && !calc(q1)) q1 += a[++p1];
		rep(j, 0, 2 * (i - 1)) {
			if (!(j & 1)) {
				if (q0 % d > x) {
					int y = J(p0, T(i - 1, j) + (q0 + d - 1) / d * d);
					chmin(f[p0][y], f[i - 1][j]);
					chmin(f[p0][y - 1], f[i - 1][j] + q0 % d - x);
				}
			} else {
				if (q1 % d > x) {
					int y = J(p1, T(i - 1, j - 1) + (q1 + d - 1) / d * d);
					chmin(f[p1][y], f[i - 1][j]);
					chmin(f[p1][y - 1], f[i - 1][j] + q1 % d - x);
				}
			}
		}
	}
	rep(i, 0, n) {
		int H = 0, W = 0, Hx = x, Wx = 0;
		rep(j, i + 1, n) {
			H += a[j];
			int z = calc(H);
			if (j != n && z) H -= z, W += z;
			Hx += a[j];
			z = calc(Hx);
			if (j != n && z) Hx -= z, Wx += z;
		}
		if (W <= m) {
			rep(j, 0, 2 * i) {
				int l = T(i, j), r, rem;
				if (j % 2 == 0) rem = m - W; else rem = m - Wx;
				if (f[i][j] > rem) continue;
				if (j % 2 == 0) r = H - min(H, rem - f[i][j]);
				else r = Hx - min(Hx, rem - f[i][j]);
				int res = l + r, z = calc(res); if (z) res += y - z;
				chmin(ans, res);
			}
		}
	}
	printf("%lld\n", ans);
}

signed main() {
	//freopen("ao.in", "r", stdin);
	//freopen("ao.out", "w", stdout);
	int o = read(), T = read();
	while (T--) work();
	return 0;
}
