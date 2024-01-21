#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

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

const int MAXN = 1005;
const int B = 250;
int n, a[MAXN][3];
int f[3][B + 5][B + 5], g[3][B + 5][B + 5];
int T;

void cmax(int &x, int y) { if (x < y) x = y; }

void solve() {
	n = read();
	const int TB = min(n, B);
	rep (i, 1, n) a[i][0] = read(), a[i][1] = read(), a[i][2] = read();
	rep (i, 1, n) {
		memcpy(g, f, sizeof f);
		memset(f, 0, sizeof f);
		rep (j, max(0ll, i - TB), i) rep (k, max(0ll, i - TB), i) {
			int u = i - j ? i - j + 1 : 0, v = i - k ? i - k + 1 : 0;
			cmax(f[0][u][v], g[0][i - j][i - k] + a[i][0]);
			cmax(f[1][1][v], g[0][i - j][i - k] + a[i][1]);
			cmax(f[2][1][u], g[0][i - j][i - k] + a[i][2]);
			cmax(f[0][1][v], g[1][i - j][i - k] + a[i][0]);
			cmax(f[1][u][v], g[1][i - j][i - k] + a[i][1]);
			cmax(f[2][u][1], g[1][i - j][i - k] + a[i][2]);
			cmax(f[0][v][1], g[2][i - j][i - k] + a[i][0]);
			cmax(f[1][u][1], g[2][i - j][i - k] + a[i][1]);
			cmax(f[2][u][v], g[2][i - j][i - k] + a[i][2]);
		}
		rep (j, 0, 2) {
			rep (k, 0, TB) {
				rep (l, 0, TB) {
					f[j][k][l] -= k + l;
				}
			}
		}
	}
	int ans = 0;
	rep (j, 0, 2) {
		rep (k, 0, TB) {
			rep (l, 0, TB) {
				ans = max(ans, f[j][k][l]);
			}
		}
	}
	print(ans), putchar(10);
	memset(f, 0, sizeof f);
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("codechef.in", "r", stdin);
	freopen("codechef.out", "w", stdout);
#endif
#endif
	T = read();
	while (T --> 0) solve();
	return 0;
}
