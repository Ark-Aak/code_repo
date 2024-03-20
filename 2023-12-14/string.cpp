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

#define int ll

int qpow(int a, int b, int p) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}

const int MAXN = 2e6 + 5;
const int MOD = 1e9 + 7;
int sigma, n, k, ans;
int f[MAXN], pw[MAXN], cnt, v[MAXN];
vector <int> fa, pre;
map <vector <int>, int> m;
int g[MAXN], h[MAXN], dp[MAXN];

int find(int x) {
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

vector <int> change(vector <int> p) {
	vector <int> nw(k - 1);
	rep (i, 1, k - 1) nw[i - 1] = p[i] - 1;
	rep (i, 0, k - 2) {
		if (nw[i] < 0) {
			rep (j, i, k - 2) nw[j] = (nw[j] < 0 ? i : nw[j]);
		}
	}
	return nw;
}

int dfs(vector <int> p) {
	if (m.count(p)) return m[p];
	int res = ++cnt;
	m[p] = res;
	vector <int> nxt = p;
	nxt.emplace_back(k - 1);
	fa[k - 1] = k - 1;
	rep (i, 0, k - 2) fa[i] = p[i];
	int lp = 0, rp = k - 1;
	while (lp < rp) {
		int fl = find(lp), fr = find(rp);
		if (fl == fr) {
			lp++, --rp;
			continue;
		}
		if (fl < fr) fa[fr] = fl;
		else fa[fl] = fr;
		v[res]++;
		lp++, --rp;
	}
	v[res] = MOD - pw[v[res]];
	h[res] = dfs(change(fa));
	g[res] = dfs(change(nxt));
	return res;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
#endif
#endif
	read(sigma), read(n), read(k);
	if (k > n) {
		int ans = 1;
		rep (i, 1, n) ans = (ans * sigma) % MOD;
		print(ans);
		return 0;
	}
	fa.resize(k);
	pw[0] = 1;
	const int inv_sigma = qpow(sigma, MOD - 2, MOD);
	rep (i, 1, n) pw[i] = pw[i - 1] * inv_sigma % MOD;
	rep (i, 0, k - 2) pre.emplace_back(i);
	f[dfs(pre)] = 1;
	_rep (i, n - k + 1, 1) {
		rep (j, 1, cnt) dp[j] = f[j], f[j] = 0;
		rep (j, 1, cnt) {
			if (dp[j]) {
				f[g[j]] = (f[g[j]] + dp[j]) % MOD;
				f[h[j]] = (f[h[j]] + dp[j] * v[j] % MOD + MOD) % MOD;
			}
		}
	}
	int ans = 0;
	rep (i, 1, cnt) ans = (ans + f[i] + MOD) % MOD;
	rep (i, 1, n) ans = (ans * sigma) % MOD;
	print(ans);
	return 0;
}
