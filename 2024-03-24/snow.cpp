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

int n, m, a[505][505], oa[505][505];
int q[505][505], b[505][505], ans = 1e9;
unordered_map <int, int> mp[505];

void dfs(int step, int prc) {
	if (prc >= ans) return;
	if (step > n * m) {
		ans = min(ans, prc);
		return;
	}
	int i = (step - 1) / m + 1, j = (step - 1) % m + 1;
	/* cout << i << " " << j << endl; */
	int o = oa[i][j];
	if (o == 0) {
		a[i][j] = 0;
		q[i][j] = q[i][j - 1] + a[i][j];
		b[i][j] = b[i - 1][j] + a[i][j];
		dfs(step + 1, prc);
	}
	a[i][j] = 1;
	q[i][j] = q[i][j - 1] + a[i][j];
	b[i][j] = b[i - 1][j] + a[i][j];
	if (!mp[q[i][j]][b[i][j]]) {
		mp[q[i][j]][b[i][j]] = 1;
		dfs(step + 1, prc + (o != 1));
		mp[q[i][j]][b[i][j]] = 0;
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("snow.in", "r", stdin);
	freopen("snow.out", "w", stdout);
#endif
#endif
	n = read(), m = read();
	rep (i, 1, n) rep (j, 1, m) oa[i][j] = read();
	/* cout << endl; */
	dfs(1, 0);
	print(ans);
	return 0;
}
