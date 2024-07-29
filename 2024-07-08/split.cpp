#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

#define int ll

using namespace std;

typedef long long ll;
typedef __int128 i128;
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

int T;
int n, m;

void solve() {
	n = read(), m = read();
	if (m == 1) return print(n - 1), puts(""), void();
	if (int r = n % 3; m == 2) return print(2 * (n / 3) + (r == 2)), puts(""), void();
	if (int r = n % 8; m == 3) return print(4 * (n / 8) + (r > 1) * ((r - 1) / 2 + 1)), puts(""), void();
	int ans = 0;
	const int k = (m * m - 1);
	const int c = (2 * m - 2);
	ans += (n / k) * c;
	n %= k;
	int plow = n / m;
	int pnum = (plow + 1) * m - n;
	if (plow > m / 2) {
		ans += m + (plow + 1);
	}
	else {
	}
	print(ans), puts("");
}

signed main() {
#ifndef LOCAL
	ignore = freopen("split.in", "r", stdin);
	ignore = freopen("split.out", "w", stdout);
#endif
	T = read();
	while (T --> 0) solve();
	return 0;
}
