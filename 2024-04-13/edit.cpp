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

const int MAXN = 1e6 + 5, MAXM = 26;
int n, c, w[MAXM + 1][MAXM + 1], _w[MAXM + 1][MAXM + 1];
int mx[MAXM + 1], deg[MAXN], sol = 1;
int bel[MAXN];
ll f[MAXM + 1][1 << 13][2];
string s, t;

#define id(x) ((x) - 'a' + 1)

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("edit.in", "r", stdin);
	freopen("edit.out", "w", stdout);
#endif
#endif
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> c;
	cin >> s >> t;
	s = ' ' + s;
	t = ' ' + t;
	rep (i, 1, n) w[id(s[i])][id(t[i])]++;
	rep (i, 1, 26) {
		int tot = 0;
		_w[i][0] = 0x3f3f3f3f;
		rep (j, 1, 26) tot += w[i][j];
		rep (j, 1, 26) {
			_w[i][j] = tot - w[i][j];
			if (i != j) _w[i][j] += c;
			if (_w[i][j] < _w[i][mx[i]]) mx[i] = j;
		}
		deg[mx[i]]++;
	}
	queue <int> q;
	rep (i, 1, 26) if (!deg[i]) q.push(i), sol = 0;
	while (q.size()) {
		int tp = q.front();
		q.pop();
		deg[mx[tp]]--;
		if (!deg[mx[tp]]) q.push(mx[tp]);
	}
	int cnt = 0;
	rep (i, 1, 26) {
		if (deg[i] && mx[i] != i) {
			cnt++;
			int ch = i;
			while (deg[ch]) {
				bel[ch] = cnt;
				deg[ch] = 0;
				ch = mx[ch];
			}
		}
	}
	if (!cnt) {
		ll ans = 0;
		rep (i, 1, 26) ans += _w[i][mx[i]];
		print(ans);
		return 0;
	}
	memset(f, 0x3f, sizeof f);
	f[0][0][0] = 0;
	rep (i, 1, 26) {
		rep (stat, 0, (1 << cnt) - 1) {
			rep (t, 0, 1) {
				rep (j, 1, 26) {
					int tstat = stat;
					if (bel[i] && mx[i] != j) tstat |= (1 << (bel[i] - 1));
					if (bel[j] && (mx[i] != j || bel[i] != bel[j])) tstat |= (1 << (bel[j] - 1));
					f[i][tstat][t | (mx[i] != j)] = min(f[i][tstat][t | (mx[i] != j)],
														f[i - 1][stat][t] + _w[i][j]);
				}
			}
		}
	}
	ll ans = 1e18;
	rep (stat, 0, (1 << cnt) - 1) {
		rep (t, sol, 1) {
			ans = min(ans, f[26][stat][t] + 1ll * c * (cnt - __builtin_popcount(stat)));
		}
	}
	print(ans);
	return 0;
}
