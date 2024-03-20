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

const int MAXN = 1e5 + 5, MAXM = 26;
int n, m, ans;
int a[MAXN][MAXM], b[1 << MAXM], p[MAXM];
int f[1 << MAXM];

signed main() {
	n = read(), m = read();
	rep (i, 1, n) rep (j, 1, m) a[i][j] = read();
	rep (i, 1, m) b[1 << (i - 1)] = read();
	rep (i, 1, n) {
		rep (j, 1, m) p[j] = j;
		sort(p + 1, p + m + 1, [&](int x, int y) { return a[i][x] < a[i][y]; });
		int S = 0;
		ans += a[i][p[1]];
		rep (j, 2, m) f[S |= (1 << (p[j - 1] - 1))] += a[i][p[j]] - a[i][p[j - 1]];
	}
	for (int i = 0; i < m; i++) {
		for (int S = 0; S < (1 << m); S++) {
			if (S & (1 << i)) f[S] += f[S ^ (1 << i)];
		}
	}
	int minx = 1e18;
	rep (S, 1, (1 << m) - 1) {
		b[S] = b[S & -S] + b[S ^ (S & -S)];
		minx = min(minx, b[S] + f[((1 << m) - 1) ^ S]);
	}
	print(ans + minx);
	return 0;
}
