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

const int MAXN = 1e5 + 5;
const int B = sqrt(2 * MAXN);
int n, q, c[MAXN], bel[MAXN << 1];
int euler[MAXN << 1], fst[MAXN];
vector <int> G[MAXN];

struct Query {
	int u, v, id;

	bool operator < (const Query &t) const {
		return bel[u] == bel[t.u] ? bel[v] < bel[t.v] : bel[u] < bel[t.u];
	}
} Q[MAXN];

void dfs(int u, int fa) {
	euler[++euler[0]] = u;
	fst[u] = euler[0];
	for (auto v : G[u]) if (v != fa) {
		dfs(v, u);
	}
	euler[++euler[0]] = u + n;
}

int cnt[MAXN], ans;

void upd(int x, int flg) {
	if (x > n) {
		x -= n;
		if (flg == 1) {
			cnt[c[x]]--;
			if (cnt[c[x]] == 0) ans--;
		}
		else {
			if (cnt[c[x]] == 0) ans++;
			cnt[c[x]]++;
		}
	}
	else {
		if (flg == 1) {
			if (cnt[c[x]] == 0) ans++;
			cnt[c[x]]++;
		}
		else {
			cnt[c[x]]--;
			if (cnt[c[x]] == 0) ans--;
		}
	}
}

int opt[MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("necklace.in", "r", stdin);
	freopen("necklace.out", "w", stdout);
#endif
#endif
	n = read(), q = read();
	rep (i, 1, 2 * n) bel[i] = (i - 1) / B + 1;
	rep (i, 1, n) c[i] = read();
	rep (i, 1, n - 1) {
		int u = read(), v = read();
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	dfs(1, 0);
	// rep (i, 1, 2 * n) cout << euler[i] << " ";
	// cout << endl;
	rep (i, 1, q) {
		Q[i].u = read(), Q[i].v = read();
		Q[i].u = fst[Q[i].u], Q[i].v = fst[Q[i].v];
		Q[i].id = i;
	}
	sort(Q + 1, Q + q + 1);
	int lcur = 1, rcur = 0;
	rep (i, 1, q) {
		int l = Q[i].u, r = Q[i].v;
		// cout << "que:" << l << " " << r << " " << Q[i].id << endl;
		while (lcur < l) upd(euler[lcur++], -1);
		while (lcur > l) upd(euler[--lcur], 1);
		while (rcur < r) upd(euler[++rcur], 1);
		while (rcur > r) upd(euler[rcur--], -1);
		opt[Q[i].id] = ans;
	}
	rep (i, 1, q) print(opt[i]), puts("");
	return 0;
}
