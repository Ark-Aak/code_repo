#include <bits/stdc++.h>

#define int __int128

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

typedef long double ld;

const int MAXN = 2e7 + 5;
int n, l;
int a[MAXN], v[MAXN], w[MAXN];
int cnt = 1;
int ch[MAXN][2], sum[MAXN], ans;

void exgcd(int a, int b, int &x, int &y) {
	if (!b) return x = 1, y = 0, void();
	exgcd(b, a % b, y, x), y -= a / b * x;
}

int inv(int x, int mod) {
	int p, q;
	exgcd(x, mod, p, q);
	return p & (mod - 1);
}

void dfs(int u) {
	/* assert(cnt <= 2e6); */
	ans = max(ans, sum[u]);
	if (ch[u][0]) sum[ch[u][0]] += sum[u], dfs(ch[u][0]);
	if (ch[u][1]) sum[ch[u][1]] += sum[u], dfs(ch[u][1]);
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("gift.in", "r", stdin);
	freopen("gift.out", "w", stdout);
#endif
#endif
	n = read();
	l = read();
	rep (i, 1, n) a[i] = read(), v[i] = read(), w[i] = read();
	rep (i, 1, n) a[i] = ((1ll << l) - a[i]) & ((1ll << l) - 1);
	rep (i, 1, n) {
		int k = __builtin_ctzll(v[i]);
		v[i] >>= k;
		int x = inv(v[i], (1ll << ((l << 1) - k)));
		x = (a[i] * x) & ((1ll << ((l << 1) - k)) - 1);
		rep (j, 1, l - k) x = (x << 1) & ((1ll << ((l << 1) - k)) - 1);
		int u = 1;
		rep (j, 0, (l << 1) - k - 1) {
			if (!ch[u][x >> j & 1]) ch[u][x >> j & 1] = ++cnt;
			u = ch[u][x >> j & 1];
		}
    	sum[u] += w[i];
	}
	dfs(1);
	print(ans);
	return 0;
}
