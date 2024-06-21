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

const int MOD = 1e9 + 7;
const int MAXN = 32;

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

int T, n, m, k, a[MAXN];
int seq[MAXN], ta[MAXN], ans;

int dfs2(int step, int n, int ch) {
	int tta[MAXN] = {0};
	rep (i, 1, n) tta[i] = ta[i];
	if (step > k) {
		return seq[tta[1]];
	}
	if (!ch) {
		int ra = dfs2(step + 1, n / 2, ch ^ 1);
		rep (i, 1, n / 2) ta[i] = ta[i + n / 2];
		int rb = dfs2(step + 1, n / 2, ch ^ 1);
		rep (i, 1, n) ta[i] = tta[i];
		return max(ra, rb);
	}
	else {
		int ra = dfs2(step + 1, n / 2, ch ^ 1);
		rep (i, 1, n / 2) ta[i] = ta[i + n / 2];
		int rb = dfs2(step + 1, n / 2, ch ^ 1);
		rep (i, 1, n) ta[i] = tta[i];
		return min(ra, rb);
	}
}

void dfs(int step) {
	if (step > n) {
		memset(ta, 0, sizeof ta);
		rep (i, 1, (1 << k)) {
			ta[i] = a[i];
		}
		ans += dfs2(1, 1 << k, 0);
		return;
	}
	rep (i, 1, m) seq[step] = i, dfs(step + 1);
}

void solve() {
	n = read(), m = read(), k = read();
	rep (i, 1, (1 << k)) a[i] = read();
	ans = 0;
	dfs(1);
	print(ans), puts("");
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("beitobear.in", "r", stdin);
	freopen("beitobear.out", "w", stdout);
#endif
#endif
	T = read();
	while (T --> 0) solve();
	return 0;
}
