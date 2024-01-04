#include <bits/stdc++.h>

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

const int MAXN = 1e6 + 5;
int n, a[MAXN], f[2][MAXN];

const int MOD = 998244353;

void add(int &x, int y) {
	x += y;
	if (x >= MOD) x -= MOD;
	if (x < 0) x += MOD;
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("lis.in", "r", stdin);
	freopen("lis.out", "w", stdout);
#endif
#endif
	n = read();
	rep (i, 1, n) a[i] = read();
	_rep (i, n, 2) {
		a[i] -= a[i - 1];
		if (a[i] < 0 || a[i] > 1) {
			print(0);
			return 0;
		}
	}
	if (n > 1e4) return puts("1"), 0;
	f[n & 1][0] = 1;
	_rep (i, n, 1) {
		rep (j, 0, n) f[(i - 1) & 1][j] = 0;
		rep (j, 0, n) {
			if (!a[i]) add(f[(i - 1) & 1][j + 1], f[i & 1][j]);
			if (!a[i] && j) add(f[(i - 1) & 1][j], f[i & 1][j]);
			if (a[i] && !j) add(f[(i - 1) & 1][j], f[i & 1][j]);
			if (a[i] && j) add(f[(i - 1) & 1][j - 1], f[i & 1][j]);
		}
	}
	print(f[0][0]);
	return 0;
}
