#include <bits/stdc++.h>

#define rep(i, a, b) for(ll i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(ll i = (a), i##end = (b); i >= i##end; i--)
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

const int MAXN = 2e7 + 5;
const int MOD = 998244353;
const int PRE = 2e7;
bitset <MAXN> vis;
vector <int> p;
int f[MAXN];
int sumf[MAXN], sumik[MAXN], sumi2k[MAXN];
int valik[305], vali2k[305];
ll T, n, k, len;
ll fac[305], ifac[305], invb[305];
ll pre[305], suf[305];

ll qpow(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a % MOD;
		a = 1ll * a * a % MOD;
		b >>= 1;
	}
	return res;
}

void Sieve(int n) {
	vis[1] = f[1] = 1;
	rep (i, 2, n) {
		if (!vis[i]) {
			p.emplace_back(i);
			int ik = qpow(i, k);
			f[i] = (1ll - ik + MOD) % MOD;
		}
		for (auto j : p) {
			if (1ll * i * j > n) break;
			vis[1ll*i * j] = 1;
			if (i % j == 0) {
				f[i * j] = f[i];
				break;
			}
			f[1ll * i * j] = 1ll * f[i] * f[j] % MOD;
		}
	}
	/* cerr << "sb" << endl; */
	rep (i, 1, n) {
		int ik = qpow(i, k);
		sumf[i] = (sumf[i - 1] + 1ll * 1ll * ik % MOD * f[i] % MOD) % MOD;
		sumik[i] = ((1ll * sumik[i - 1] + ik) % MOD) % MOD;
		sumi2k[i] = (sumi2k[i - 1] + 1ll * ik * 1ll * ik % MOD) % MOD;
		if (i <= len) {
			valik[i] = sumik[i];
			vali2k[i] = sumi2k[i];
		}
	}
	/* cerr << "sb" << endl; */
}

void init(int n) {
	/* cerr << "sb" << endl; */
	Sieve(n);
	fac[0] = 1;
	rep (i, 1, len) fac[i] = 1ll * fac[i - 1] * i % MOD;
	ifac[len] = qpow(fac[len], MOD - 2);
	_rep (i, len - 1, 0) ifac[i] = 1ll * ifac[i + 1] * (1ll * i + 1 % MOD) % MOD;
	_rep (i, len, 0) {
		invb[i] = 1ll * ifac[i - 1] * ifac[len - i] % MOD;
		if ((len - i) & 1) invb[i] = (1ll * MOD - invb[i] + MOD) % MOD;
	}
	pre[0] = 1, suf[len + 1] = 1;
}

ll Sk(ll x, bool flg) {
	if (x <= PRE) return flg ? sumi2k[x] : sumik[x];
	rep (i, 1, len) pre[i] = 1ll * pre[i - 1] * (x - i) % MOD;
	_rep (i, len, 0) suf[i] = 1ll * suf[i + 1] * (x - i) % MOD;
	ll res = 0;
	rep (i, 1, len) {
		ll r = 1ll * (flg ? vali2k[i] : valik[i]) % MOD * pre[i - 1] % MOD * suf[i + 1] % MOD;
		res = (res + r * invb[i] % MOD) % MOD;
	}
	return res;
}

unordered_map <int, int> mem;

ll dsieve(ll x) {
	/* cout << x << endl; */
	if (x <= PRE) return sumf[x];
	if (mem.count(x)) return mem[x];
	ll res = Sk(x, 0);
	for (ll l = 2, r; l <= x; l = r + 1) {
		r = x / (x / l);
		res = (1ll * res + 1ll * (1ll * MOD - 1ll * (1ll * Sk(r, 1) - 1ll * Sk(l - 1, 1) + 1ll * MOD) % MOD * 1ll * dsieve(1ll * x / l) % MOD) % MOD) % MOD;
	}
	return mem[x] = res%MOD;
}

void solve() {
	n = read();
	ll ans = 0;
	for (ll l = 1, r; l <= n; l = r + 1) {
		r = n / (n / l);
		ll tp = Sk(n / l, 0);
		/* cerr << "1:" << l << " " << r << endl; */
		ans = (ans + 1ll * tp * tp % MOD * 1ll * (1ll * dsieve(r) - dsieve(l - 1) + MOD) % MOD) % MOD;
		/* cerr << "2:" << l << " " << r << endl; */
	}
	print(ans);
	puts("");
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("lcm.in", "r", stdin);
	freopen("lcm.out", "w", stdout);
#endif
#endif
	T = read(), k = read();
	len = 2 * k + 2;
	init(PRE);
	while (T --> 0) solve();
	//cerr << mem.size() << endl;
	return 0;
}
