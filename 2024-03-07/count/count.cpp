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

const int MOD = 998244353;
int n, k, x, ord[20], ch[20], ans;
int rord[20], sum;

void dfs(int step) {
	if (step > k) {
		/* sum++; */
		int minai = 1e9;
		rep (i, 1, ch[1]) minai = min(minai, rord[i]);
		rep (i, 2, k) {
			int minbi = 1e9;
			rep (j, 1, ch[i]) minbi = min(minbi, rord[j]);
			if (minbi != minai) return;
		}
		ans++;
		ans %= MOD;
		return;
	}
	rep (i, ch[step - 1], n) {
		ch[step] = i;
		dfs(step + 1);
	}
}

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

const int MAXN = 1e6 + 5;
int fac[MAXN], ifac[MAXN];

void init(int n) {
	fac[0] = 1;
	rep (i, 1, n) fac[i] = fac[i - 1] * i % MOD;
	ifac[n] = qpow(fac[n], MOD - 2);
	_rep (i, n, 1) ifac[i - 1] = ifac[i] * (i) % MOD;
}

int C(int n, int m) {
	if (n < 0 || m < 0) return 0;
	if (n < m) return 0;
	return fac[n] * ifac[n - m] % MOD * ifac[m] % MOD;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("count.in", "r", stdin);
	freopen("count.out", "w", stdout);
#endif
#endif
	init(1e6);
	n = read(), k = read(), x = read();
	if (x == 1) {
		int ans = 0;
		rep (i, 1, n) {
			ans = (ans + C(i + k - 2, i - 1)) % MOD;
		}
		print(ans * fac[n - 1] % MOD), putchar(10);
		return 0;
	}
	rep (i, 1, n - 1) ord[i] = i;
	ch[0] = 1;
	do {
		rord[1] = x;
		rep (i, 1, n - 1) rord[i + 1] = ord[i] < x ? ord[i] : ord[i] + 1;
		dfs(1);
		/* cout << sum << endl; */
		/* sum = 0; */
	} while (next_permutation(ord + 1, ord + n));
	print(ans);
	return 0;
}
