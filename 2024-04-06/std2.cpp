#include <bits/stdc++.h>

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

const int MAXN = 3e5 + 5;
int n, a[MAXN];
int f[2005][4005], smin[2005][4005];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("seq.in", "r", stdin);
	freopen("seq.out", "w", stdout);
#endif
#endif
	n = read();
	rep (i, 1, n) a[i] = read();
	memset(f, 0x3f, sizeof f);
	memset(smin, 0x3f, sizeof smin);
	f[n][a[n]] = 0;
	rep (i, 1, a[n]) smin[n][i] = 0;
	_rep (i, n - 1, 1) {
		rep (k, 1, 2 * n) {
			/* rep (j, k + 1, 2 * n) { */
				/* f[i][k] = min(f[i][k], f[i + 1][j] + (k != a[i])); */
			/* } */
			f[i][k] = min(f[i][k], smin[i + 1][k + 1] + (k != a[i]));
		}
		_rep (k, 2 * n, 1) smin[i][k] = min(smin[i][k + 1], f[i][k]);
	}
	int ans = 1e9;
	rep (i, 1, 2 * n) ans = min(ans, f[1][i]);
	print(ans);
	return 0;
}
