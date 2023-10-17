#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

int n, a[3005];
int f[3005][3005], g[3005][3005];

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("river.in", "r", stdin);
	freopen("river.out", "w", stdout);
#endif
#endif
	read(n);
	rep (i, 1, n) read(a[i]);
	memset(f, 0x7f, sizeof f);
	rep (i, 1, n) rep (j, i, n) {
		if (j == i) g[i][j] = a[i];
		else g[i][j] = __gcd(g[i][j - 1], a[j]);
	}
	rep (i, 1, n) f[i][i] = 0;
	rep (len, 1, n) {
		rep (i, 1, n) {
			int j = i + len - 1;
			if (j > n) break;
			f[i - 1][j] = min(f[i - 1][j], f[i][j] + g[i][j] + a[i - 1]);
			f[i][j + 1] = min(f[i][j + 1], f[i][j] + g[i][j] + a[j + 1]);
		}
	}
	cout << f[1][n];
	return 0;
}
