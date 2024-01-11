#include <bits/stdc++.h>

#define int ll

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

int qpow(int a, int b, int p) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % p;
		a = a * a % p, b >>= 1;
	}
	return res;
}

const int MAXN = 2e5 + 5, MOD = 998244353;
int n, a[MAXN], mxa, ans, mm;
const int MX = 1 << 22;
int f[MX + 5], conn[22][22], cnt[MX + 5];

class union_find {
public:
	int fa[22];

	void init() {
		rep (i, 0, mm - 1) fa[i] = i;
	}

	int find(int x) {
		return fa[x] == x ? x : fa[x] = find(fa[x]);
	}

	void merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return;
		fa[y] = x;
	}
} uf[MX + 5];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("or.in", "r", stdin);
	freopen("or.out", "w", stdout);
#endif
#endif
	n = read();
	rep	(i, 1, n) a[i] = read(), mxa |= a[i];
	mm = log2(mxa) + 1;
	if (!mxa) {
		print(qpow(2, n, MOD) - 2);
		return 0;
	}
	rep (i, 1, n) f[a[i]]++;
	rep (i, 0, (1 << mm) - 1) uf[i].init();
	rep (i, 0, mm - 1) {
	   	rep(j, 0, (1 << mm) - 1) {
			if (j & (1 << i)) f[j] += f[j ^ (1 << i)];
		}
	}
	rep (k, 1, n) {
		rep (i, 0, mm - 1) {
			rep (j, 0, mm - 1) {
				conn[i][j] |= ((a[k] >> i) & 1) & ((a[k] >> j) & 1);
			}
		}
	}
	const int qz = (1 << mm) - 1;
	cnt[0] = f[qz];
	rep (i, 1, (1 << mm) - 1) {
		int _id = i & -i, k = log2(_id);
		uf[i] = uf[i ^ _id];
		rep (j, k + 1, mm - 1)
			if (((i >> j) & 1) && conn[k][j]) uf[i].merge(k, j);
		cnt[i] = f[qz ^ i];
	}
	ll ans = 0;
	rep (i, 0, (1 << mm) - 1) {
		int t = __builtin_popcount(i) & 1 ? -1 : 1;
		int cnt = 0;
		rep (j, 0, mm - 1) if (((i >> j) & 1) && uf[i].find(j) == j) cnt++;
		ans = (ans + t * qpow(2, cnt, MOD) % MOD * qpow(2, ::cnt[i], MOD)) % MOD;
	}
	print((ans + MOD) % MOD);
	return 0;
}
