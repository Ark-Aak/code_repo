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

const int MAXN = 105;
long double f[MAXN][MAXN], ans[MAXN];
const long double eps = 1e-12;

int cmp(long double a, long double b) {
	if (a + eps < b) return -1;
	if (fabs(b - a) <= eps) return 0;
	return 1;
}

signed main() {
	int n = read();
	rep (i, 1, n) {
		rep (j, 1, n + 1) f[i][j] = read();
	}
	rep (i, 1, n) {
		int r = i;
		rep (j, r + 1, n) {
			if (fabs(f[r][i]) < fabs(f[j][i])) r = j;
		}
		if (!cmp(f[r][i], 0)) return puts("No Solution"), 0;
		rep (j, 1, n + 1) swap(f[i][j], f[r][j]);
		long double dif = f[i][i];
		rep (j, i, n + 1) f[i][j] /= dif;
		rep (j, i + 1, n) {
			dif = f[j][i];
			rep (k, i, n + 1)
				f[j][k] -= f[i][k] * dif;
		}
	}
	ans[n] = f[n][n + 1];
	_rep (i, n - 1, 1) {
		ans[i] = f[i][n + 1];
		rep (j, i + 1, n) ans[i] -= (f[i][j] * ans[j]);
	}
	rep (i, 1, n) {
		printf("%.2Lf\n", ans[i]);
	}
	return 0;
}
