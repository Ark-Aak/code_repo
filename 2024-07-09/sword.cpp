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

const int MAXN = 3e5 + 5;
int n;
int k[MAXN], b[MAXN], a[MAXN];
int f[1 << 20];

signed main() {
#ifndef LOCAL
	ignore = freopen("sword.in", "r", stdin);
	ignore = freopen("sword.out", "w", stdout);
#endif
	n = read();
	rep (i, 1, n) k[i] = read(), b[i] = read(), a[i] = read();
	if (n <= 20) {
		rep (i, 1, n) {
			rep (j, 0, (1 << n) - 1) {
				if (__builtin_popcount(j) != i - 1) continue;
				const int pst = __builtin_popcount(j) + 1;
				rep (d, 1, n) {
					if (j & (1 << (d - 1))) continue;
					const int fce = max(a[d], b[d] - k[d] * pst);
					f[j | (1 << (d - 1))] = max(f[j | (1 << (d - 1))], f[j] + fce);
				}
			}
		}
		print(f[(1 << n) - 1]), puts("");
	}
	else {
		int ans = 0;
		rep (i, 1, n) ans += b[i];
		print(ans), puts("");
	}
	return 0;
}
