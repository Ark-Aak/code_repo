#include <bits/stdc++.h>

/* #define int ll */

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

int n, p, fz, fm;

int prev(int x) { return x - 1 < 1 ? n : x - 1; }
int nxt(int x) { return x + 1 > n ? 1 : x + 1; }

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % p;
		a = 1ll * a * a % p;
		b >>= 1;
	}
	return res;
}

const int MAXN = 25;
int f[MAXN][1 << 20];

int nxtstat(int stat) {
	int stk[MAXN] = {0};
	rep (i, 1, n) stk[n - i + 1] = (stat >> (i - 1)) & 1;
	int res[MAXN] = {0};
	rep (i, 1, n) {
		if (stk[i]) res[i] = 1;
		else if (stk[prev(i)] || stk[nxt(i)]) res[i] = 1;
	}
	int R = 0;
	rep (i, 1, n) R <<= 1, R += res[i];
	return R;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("festival.in", "r", stdin);
	freopen("festival.out", "w", stdout);
#endif
#endif
	n = read(), p = read();
	const int inv = qpow(n, p - 2);
	f[0][0] = 1;
	rep (i, 1, n) {
		/* cout << i << endl; */
		rep (j, 0, (1 << n) - 2) {
			int ts = nxtstat(j);
			rep (k, 1, n) {
				int s = ts;
				s |= (1 << (k - 1));
				f[i][s] += 1ll * f[i - 1][j] * inv % p;
				/* f[i][s] %= p; */
				if (f[i][s] >= p) f[i][s] -= p;
				/* cout << i << " " << s << " " << f[i][s] << endl; */
			}
		}
	}
	ll ans = 0;
	rep (i, 1, n) {
		/* cout << f[i][(1 << n) - 1] << endl; */
		ans = (ans + 1ll * f[i][(1 << n) - 1] * i % p);
		if (ans >= p) ans -= p;
	}
	print(ans); puts("");
	/* cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl; */
	return 0;
}
