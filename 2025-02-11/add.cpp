#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define de(val) cerr << #val << " = " << (val) << endl

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
	if (x < 0) putchar('-'), x = -x;
	static int sta[40];
	int top = 0;
	do sta[top++] = x % 10, x /= 10; while (x);
	while (top) putchar(sta[--top] + 48);
}

const int MAXN = 3e6 + 5;
int n, m, p[MAXN];
vector <pii> G[MAXN];
int k[MAXN], b[MAXN], a[MAXN];
int cer, maxl, minr;
bool flg = 0;
vector <int> pt;

void dfs(int u, int fa) {
	if (k[u] == 1) {
		maxl = max(maxl, -b[u]);
		minr = min(minr, p[u] - b[u]);
	}
	else {
		maxl = max(maxl, b[u] - p[u]);
		minr = min(minr, b[u]);
	}
	pt.push_back(u);
	for (auto [v, w] : G[u]) {
		if (v == fa) continue;
		if (k[v]) {
			if (k[v] == -k[u]) { if (b[v] != w - b[u]) exit((puts("NIE"), 0)); }
			else {
				int nb = b[u] + b[v] - w;
				int nk = -(k[u] + k[v]);
				if (nk * nb < 0) exit((puts("NIE"), 0));
				nb = abs(nb), nk = abs(nk);
				if (nb % nk) exit((puts("NIE"), 0));
				cer = nb / nk;
				flg = 1;
				return;
			}
			continue;
		}
		k[v] = -k[u];
		b[v] = w - b[u];
		dfs(v, u);
		if (flg) return;
	}
}

int ansmax, ansmin;

void solve(int u) {
	ansmax += p[u] - a[u];
	ansmin += p[u] - a[u];
	k[u] = 1;
	for (auto [v, w] : G[u]) {
		if (~a[v]) {
			if (a[v] != w - a[u]) exit((puts("NIE"), 0));
			continue;
		}
		a[v] = w - a[u];
		if (a[v] < 0 || a[v] > p[v]) exit((puts("NIE"), 0));
		solve(v);
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("add.in", "r", stdin);
	freopen("add.out", "w", stdout);
#endif
#endif
	memset(a, -1, sizeof a);
	n = read(), m = read();
	rep (i, 1, n) p[i] = read();
	rep (i, 1, m) {
		int u = read(), v = read(), w = read();
		G[u].push_back(dl(v, w));
		G[v].push_back(dl(u, w));
	}
	rep (i, 1, n) {
		if (k[i]) continue;
		k[i] = 1, b[i] = 0;
		cer = 0, flg = 0;
		maxl = 0, minr = 1e9;
		pt.clear();
		dfs(i, 0);
		if (flg) {
			a[i] = cer;
			if (cer < 0 || cer > p[i]) return puts("NIE"), 0;
			solve(i);
		}
		else {
			maxl = max(0ll, maxl);
			minr = min(minr, p[i]);
			if (maxl > minr) return puts("NIE"), 0;
			int fk = 0, fb = 0;
			for (auto v : pt) fk += -k[v], fb += p[v] - b[v];
			int pl = maxl * fk + fb;
			int pr = minr * fk + fb;
			ansmax += max(pl, pr);
			ansmin += min(pl, pr);
		}
	}
	print(ansmin), putchar(32), print(ansmax), puts("");
	return 0;
}
