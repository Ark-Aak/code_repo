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

signed main() {
	int n = read();
	rep (i, 1, n) {
		rep (j, 1, n + 1) f[i][j] = read();
	}
	int cnt = 1;
	rep (i, 1, n) {
		int r = cnt;
		rep (j, r, n) {
			if (fabs(f[r][i]) < fabs(f[j][i])) r = j;
		}
		if (fabs(f[r][i]) < eps) continue;
		rep (j, i, n + 1) swap(f[r][j], f[cnt][j]);
		_rep (j, n + 1, i) f[cnt][j] /= f[cnt][i];
		rep (j, cnt + 1, n) {
			if (fabs(f[j][i]) > eps) {
				_rep (k, n + 1, i) {
					f[j][k] -= f[cnt][k] * f[j][i];
				}
			}
		}
		++cnt;
	}
	_rep (i, n, 1) {
		rep (j, i + 1, n) f[i][n + 1] -= f[i][j] * f[j][n + 1];
	}
	if (cnt <= n) {
		rep (i, cnt, n) {
			if (fabs(f[i][n + 1]) > eps) return puts("-1"), 0;
		}
		return puts("0"), 0;
	}
	rep (i, 1, n) {
		printf("x%lld=%.2Lf\n", i, f[i][n + 1]);
	}
	return 0;
}
