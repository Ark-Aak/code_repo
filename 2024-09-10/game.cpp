#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define de(val) cerr << #val << " = " << (val) << endl

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

const int MAXN = 2e5 + 5;
int n, m, q;
bitset <MAXN> a, f;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);
#endif
#endif
	n = read(), m = read(), q = read();
	rep (i, 1, n) a[i] = (read() + 1) & 1;
	while (q --> 0) {
		int op = read();
		int l = read(), r = read();
		if (op == 1) {
			int d = read() & 1;
			if (!d) continue;
			rep (i, l, r) a[i] = !a[i];
		}
		else {
			if (a[l]) {
				puts("1");
				continue;
			}
			f[r] = a[r];
			_rep (i, r - 1, l) {
				bool res = 0;
				res |= a[i];
				if (!res) {
					rep (j, i + 1, min(i + m, r)) {
						res |= !f[j];
					}
				}
				f[i] = res;
			}
			print(2 - f[l]), puts("");
		}
	}
	return 0;
}
