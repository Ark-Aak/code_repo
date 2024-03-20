#include <bits/stdc++.h>

#define int ull

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

using namespace std;

typedef unsigned long long ull;
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

const int MAXN = 1e6 + 5;
const int MOD = 998244353;

int s[MAXN], hs[MAXN], base[MAXN];
pair <int, int> R[MAXN];
int fa[MAXN], siz[MAXN];
bitset <MAXN> vis;

pair <int, int> mul(pair <int, int> x, pair <int, int> y) {
	if (x.first > y.first) swap(x, y);
	if (x.second < y.first) return make_pair(0, -1);
	else return make_pair(y.first, min(x.second, y.second));
}

int find(int x) {
	if (fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void merge(int x, int y) {
	int fx = find(x), fy = find(y);
	if (fx == fy) return;
	if (siz[fx] > siz[fy]) swap(fx, fy);
	fa[fx] = fy;
	siz[fy] += siz[fx];
	R[fy] = mul(R[fx], R[fy]);
}

void solve() {
	int n = read();
	rep (i, 1, n) siz[fa[i] = i] = 1;
	rep (i, 1, n) s[i] = read();
	rep (i, 1, n) R[i].first = read(), R[i].second = read();
	base[0] = 1;
	rep (i, 1, n) hs[i] = hs[i - 1] * 131ull + s[i];
	rep (i, 1, n) base[i] = base[i - 1] * 131ull;
	rep (k, 1, n >> 1) {
		rep (i, 1, n) vis[i] = 0;
		rep(i, 1,  n + 1 - (k << 1)) {
			if (hs[i + k - 1] - hs[i - 1] * base[k] != hs[i + 2 * k - 1] - hs[i + k - 1] * base[k])
				continue;
			_rep (j, i + (k << 1) - 1, i + k) {
				if (vis[j]) break;
				vis[j] = 1;
			}
		}
		rep (i, k + 1, n) if (vis[i]) merge(i, i - k);
		int ans = 1;
		rep (i, 1, n) if (fa[i] == i) ans = ans * (R[i].second - R[i].first + 1) % MOD;
		print(ans), putchar(32);
	}
	putchar(10);
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("yoimiya.in", "r", stdin);
	freopen("yoimiya.out", "w", stdout);
#endif
#endif
	int T = read();
	while (T --> 0) solve();
	return 0;
}
