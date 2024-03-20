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

const int MAXN = 5e3 + 5;
int n, x, y, m, a[MAXN], L[MAXN];
int ans, d, f[MAXN][MAXN];

inline int dec(int v) {
	return max(0ll, v % d - x);
}

inline int diff(int pre, int now) {
	int p = now - L[pre];
	return p / d * 2 + (p % d >= x);
}

inline int len(int pre, int now) {
	return L[pre] + now / 2 * d + (now & 1) * x;
}

void solve() {
	memset(a, 0, sizeof a);
	memset(L, 0, sizeof L);
	n = read(), x = read(), y = read(), m = read();
	rep (i, 1, n) a[i] = read();
	d = x + y;
	memset(f, 0x3f, sizeof f);
	f[0][0] = 0;
	rep (i, 1, n) {
		L[i] = L[i - 1] + a[i];
		if (dec(L[i])) L[i] -= dec(L[i]);
	}
	rep (i, 1, n) L[i] = L[i] / d * d;
	rep (i, 1, n) {
		int pt = i, ptx = i, t = a[i], tx = a[i] + x;
		while (pt < n && !dec(t)) t += a[++pt];
		while (ptx < n && !dec(tx)) tx += a[++ptx];
		rep (j, 0, (i - 1) << 1) {
			if (!(j & 1)) {
				if (t % d > x) {
					int y = diff(pt, len(i - 1, j) + (t + d - 1) / d * d);
					f[pt][y] = min(f[pt][y], f[i - 1][j]);
					f[pt][y - 1] = min(f[pt][y - 1], f[i - 1][j] + t % d - x);
				}
			}
			else {
				if (tx % d > x) {
					int y = diff(ptx, len(i - 1, j - 1) + (tx + d - 1) / d * d);
					f[ptx][y] = min(f[ptx][y], f[i - 1][j]);
					f[ptx][y - 1] = min(f[ptx][y - 1], f[i - 1][j] + tx % d - x);
				}
			}
		}
	}
	ans = 1e18;
	rep (i, 0, n) {
		int suf = 0, sufx = x, w = 0, wx = 0;
		rep (j, i + 1, n) {
			suf += a[j];
			int tp = dec(suf);
			if (j != n && tp) suf -= tp, w += tp;
			sufx += a[j];
			tp = dec(sufx);
			if (j != n && tp) sufx -= tp, wx += tp;
		}
		if (w <= m) {
			rep (j, 0, i << 1) {
				int l = len(i, j), r, rd;
				if (!(j & 1)) rd = m - w;
				else rd = m - wx;
				if (f[i][j] > rd) continue;
				if (!(j & 1)) r = suf - min(suf, rd - f[i][j]);
				else r = sufx - min(sufx, rd - f[i][j]);
				ans = min(ans, l + r + (dec(l + r) ? y - dec(l + r) : 0));
			}
		}
	}
	print(ans), puts("");
}

int o, T;

signed main() {
	o = read(), T = read();
	while (T --> 0) solve();
	return 0;
}
