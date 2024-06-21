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
const int BASE = 998244353;
const int MOD = 1e9 + 7;
const int LEN = 450;
int n, q, a[MAXN];
int pw[MAXN], prod[MAXN], inv[MAXN];
int L[LEN + 5], R[LEN + 5], id[MAXN], cnt;

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

namespace SUM {

	int pre0[LEN + 5], pre1[LEN + 5][MAXN];

	void init() {
		rep (i, 1, cnt) {
			pre0[i] = pre0[i - 1];
			rep (j, L[i], R[i]) pre0[i] = (pre0[i] + a[j] * pw[j - 1] % MOD) % MOD;
		}
		rep (i, 1, cnt) rep (j, L[i], R[i]) {
			pre1[i][j] = (pre1[i][j - 1] + a[j] * pw[j - 1] % MOD) % MOD;
		}
	}

	void update(int x) {
		rep (i, L[id[x]], R[id[x]]) pre1[id[x]][i] = (pre1[id[x]][i - 1] + a[i] * pw[i - 1] % MOD) % MOD;
		rep (i, 1, cnt) pre0[i] = (pre0[i - 1] + pre1[i][R[i]]) % MOD;
	}
} // namespace SUM

namespace HASH {

	int mul[LEN + 5][LEN + 5], hsh[LEN + 5][LEN + 5];

	void init() {
		rep (i, 1, LEN) {
			rep (j, 1, n) {
				mul[i][id[j]] = (mul[i][id[j]] + a[j] * (!(j % i))) % MOD;
				hsh[i][id[j]] = (hsh[i][id[j]] + a[j] * pw[j % i]) % MOD;
			}
		}
	}

	void update(int x, int nv) {
		rep (i, 1, LEN) {
			mul[i][id[x]] = (mul[i][id[x]] - a[x] * (!(x % i)) % MOD + nv * (!(x % i)) % MOD + MOD) % MOD;
			hsh[i][id[x]] = (hsh[i][id[x]] - a[x] * pw[x % i] % MOD + nv * pw[x % i] % MOD + MOD) % MOD;
		}
	}

	int qF(int l, int r, int k, int res = 0) {
		if (k <= LEN) {
			if (id[l] == id[r]) {
				rep (i, l, r) res = (res + a[i] * (!(i % k))) % MOD;
			}
			else {
				rep (i, l, R[id[l]]) res = (res + a[i] * (!(i % k))) % MOD;
				rep (i, L[id[r]], r) res = (res + a[i] * (!(i % k))) % MOD;
				rep (i, id[l] + 1, id[r] - 1) res = (res + mul[k][i]) % MOD;
			}
		}
		else {
			for (int i = 0; i <= n; i += k) res = (res + a[i] * (l <= i && i <= r) * (!(i % k))) % MOD;
		}
		return res;
	}

	int qH(int l, int r, int k, int res = 0) {
		if (k <= LEN) {
			if (id[l] == id[r]) rep (i, l, r) res = (res + a[i] * pw[i % k] % MOD) % MOD;
			else {
				rep (i, l, R[id[l]]) res = (res + a[i] * pw[i % k] % MOD) % MOD;
				rep (i, L[id[r]], r) res = (res + a[i] * pw[i % k] % MOD) % MOD;
				rep (i, id[l] + 1, id[r] - 1) res = (res + hsh[k][i]) % MOD;
			}
		}
		else {
			for (int i = 0; i <= n; i += k) {
				int lp = max(i, l), rp = min(i + k - 1, r);
				if (lp > rp) continue;
				if (id[lp] == id[rp]) {
					res = (res +
							((SUM::pre1[id[lp]][rp] - SUM::pre1[id[lp]][lp - 1] + MOD) % MOD) *
							(inv[lp - 1] * pw[lp - i] % MOD) % MOD
					) % MOD;
				}
				else {
					res = (res +
							(((SUM::pre0[id[rp] - 1] - SUM::pre0[id[lp]] + MOD) % MOD) +
							((SUM::pre1[id[lp]][R[id[lp]]] - SUM::pre1[id[lp]][lp - 1] + MOD) % MOD) +
							((SUM::pre1[id[rp]][rp] - SUM::pre1[id[rp]][L[id[rp]] - 1] + MOD) % MOD)) % MOD *
							(inv[lp - 1] * pw[lp - i] % MOD) % MOD) % MOD;
				}
			}
		}
		return res;
	}
} // namespace HASH

namespace DIV {

	void modify(int x, int val) {
		HASH::update(x, val);
		a[x] = (val % MOD + MOD) % MOD;
		SUM::update(x);
	}

	bool query(int l, int r, int k) {
		int sum0 = HASH::qH(l, r, k);
		int sum1 = HASH::qF(l, r, k) * prod[k - 1] % MOD;
		/* cout << sum0 << " " << sum1 << endl; */
		return sum0 == sum1;
	}

} // namespace DIV

signed main() {
	n = read(), q = read();
	rep (i, 1, n) a[i] = (read() % MOD + MOD) % MOD;
	rep (i, 1, n) assert(a[i] >= 0);
	pw[0] = prod[0] = 1;
	rep (i, 1, 2e5) pw[i] = pw[i - 1] * BASE % MOD;
	const int INV = qpow(BASE, MOD - 2);
	inv[0] = 1;
	rep (i, 1, 2e5) inv[i] = inv[i - 1] * INV % MOD;
	rep (i, 1, 2e5) prod[i] = (prod[i - 1] + pw[i]) % MOD;
	cnt = n / LEN + (!!n % LEN);
	rep (i, 1, cnt) L[i] = (i - 1) * LEN + 1, R[i] = min(n, i * LEN);
	rep (i, 1, cnt) rep (j, L[i], R[i]) id[j] = i;
	SUM::init();
	HASH::init();
	while (q --> 0) {
		int op = read();
		if (op == 1) {
			int x = read(), w = read();
			DIV::modify(x, (w % MOD + MOD) % MOD);
		}
		else {
			int l = read(), r = read(), m = read();
			int x = (r - l + 1);
			rep (i, 1, m) x = __gcd(x, read());
			if (DIV::query(l, r, x)) puts("YES");
			else puts("NO");
		}
	}
	return 0;
}
