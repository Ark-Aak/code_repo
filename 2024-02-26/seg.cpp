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

const int MAXN = 1e3 + 5;
int n, a[MAXN], K, g[MAXN][MAXN], f[MAXN][MAXN], st[MAXN][MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("seg.in", "r", stdin);
	freopen("seg.out", "w", stdout);
#endif
#endif
	memset(g, 0x3f, sizeof g);
	n = read();
	rep (i, 1, n) a[i] = read();
	K = read();
	rep (j, 0, K) g[0][j] = -1e9;
	rep (j, 0, K) {
		if (j == 0) {
			rep (i, 0, n) g[i][j] = 0;
			rep (i, 1, n) g[i][j] = max(g[i - 1][j] + a[i], a[i]);
			rep (i, 1, n) f[i][j] = max(f[i - 1][j], g[i][j]);
			continue;
		}
		rep (i, 1, n) {
			rep (k, 0, j) {
				int tval = g[i - 1][j - k] + a[i] - k;
				int bval = a[i] - k;
				if (tval >= bval) {
					st[i][j] = st[i - 1][j - k];
					g[i][j] = tval;
					f[i][j] = max(g[i][j], f[st[i][j] - 1][j - k]);
				}
				else {
					st[i][j] = i;
					g[i][j] = bval;
					f[i][j] = g[i][j];
				}
			}
			f[i][j] = max(f[i - 1][j], f[i][j]);
		}
	}
	rep (i, 0, K) {
		rep (j, 1, n) {
			cout << f[j][i] << " ";
		}
		cout << endl;
	}
	return 0;
}
