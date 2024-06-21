#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

#include <immintrin.h>
#include <emmintrin.h>

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

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)

const int MAXN = 1e5 + 25;
const int MOD = 998244353;
int w[MAXN];

namespace seg {
	int sum[MAXN << 2], mul[MAXN << 2], add[MAXN << 2];

	void pushup(int x) {
		sum[x] = sum[ls(x)] + sum[rs(x)];
	}

	void pushdown(int x, int L, int R) {
		if (mul[x] != 1) {
			sum[ls(x)] = 1ll * sum[ls(x)] * mul[x] % MOD;
			sum[rs(x)] = 1ll * sum[rs(x)] * mul[x] % MOD;
			mul[ls(x)] = 1ll * mul[ls(x)] * mul[x] % MOD;
			mul[rs(x)] = 1ll * mul[rs(x)] * mul[x] % MOD;
			add[ls(x)] = 1ll * add[ls(x)] * mul[x] % MOD;
			add[rs(x)] = 1ll * add[rs(x)] * mul[x] % MOD;
			mul[x] = 1;
		}
		if (add[x]) {
			sum[ls(x)] = (sum[ls(x)] + 1ll * add[x] * (mid - L + 1) % MOD) % MOD;
			sum[rs(x)] = (sum[rs(x)] + 1ll * add[x] * (R - mid) % MOD) % MOD;
			add[ls(x)] = (add[ls(x)] + add[x]) % MOD;
			add[rs(x)] = (add[rs(x)] + add[x]) % MOD;
			add[x] = 0;
		}
	}

	void build(int x, int L, int R) {
		mul[x] = 1, add[x] = 0;
		if (L == R) {
			sum[x] = w[L] % MOD;
			return;
		}
		build(ls(x), L, mid), build(rs(x), mid + 1, R);
		pushup(x);
	}

	void modify_mul(int x, int L, int R, int l, int r, int v) {
		if (l > r) return;
		v %= MOD;
		if (l <= L && R <= r) {
			sum[x] = 1ll * sum[x] * v % MOD;
			mul[x] = 1ll * mul[x] * v % MOD;
			add[x] = 1ll * add[x] * v % MOD;
			return;
		}
		pushdown(x, L, R);
		if (l <= mid) modify_mul(ls(x), L, mid, l, r, v);
		if (r > mid) modify_mul(rs(x), mid + 1, R, l, r, v);
		pushup(x);
	}

	void modify_add(int x, int L, int R, int l, int r, int v) {
		if (l > r) return;
		v %= MOD;
		if (l <= L && R <= r) {
			sum[x] = (sum[x] + 1ll * v * (R - L + 1) % MOD) % MOD;
			add[x] = (add[x] + v) % MOD;
			return;
		}
		pushdown(x, L, R);
		if (l <= mid) modify_add(ls(x), L, mid, l, r, v);
		if (r > mid) modify_add(rs(x), mid + 1, R, l, r, v);
		pushup(x);
	}

	int query(int x, int L, int R, int l, int r) {
		if (l > r) return 0;
		if (l <= L && R <= r) return sum[x] % MOD;
		pushdown(x, L, R);
		int res = 0;
		if (l <= mid) res += query(ls(x), L, mid, l, r);
		res %= MOD;
		if (r > mid) res += query(rs(x), mid + 1, R, l, r);
		res %= MOD;
		return res;
	}
} // namespace seg

int n, q;
const int K = 10;

vector <int> G[MAXN];
int _w[MAXN], fa[MAXN], kfa[MAXN], dep[MAXN], siz[MAXN];
int bfn[MAXN], khs[K + 1][MAXN];
vector <int> son[MAXN], kson[K + 1][MAXN];
int tdep[MAXN], st1[MAXN], st2[MAXN], ed2[MAXN], st3[MAXN], ed3[MAXN];
int dfn1, dfn2, dfn[MAXN], top[MAXN], minn[K + 1][MAXN], maxn[K + 1][MAXN];

void dfs1(int u) {
	if (u <= n) st2[u] = dfn1 + 1, dfn[u] = ++dfn2;
	if (tdep[u] >= K && u <= n) st1[u] = ++dfn1;
	for (auto v : son[u]) dfs1(v);
	if (u <= n) ed2[u] = dfn1;
}

void dfs2(int u) {
	for (auto v : kson[K][u]) {
		if (tdep[v] < K) st1[v] = ++dfn1;
	}
	if (u <= n) st3[u] = dfn1 + 1;
	for (auto v : son[u]) dfs2(v);
	if (u <= n) ed3[u] = dfn1;
}

void modify(int l, int r, int c, int d) {
	if (l > r) return;
	seg::modify_mul(1, 1, n, l, r, c);
	seg::modify_add(1, 1, n, l, r, d);
}

signed main() {
	n = read(), q = read();
	rep (i, 1, n - 1) {
		int u = read(), v = read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	rep (i, 1, n) _w[i] = read();
	G[1].push_back(n + 1);
	G[n + 1].push_back(1);
	rep (i, n + 1, n + K - 1) {
		G[i].push_back(i + 1);
		G[i + 1].push_back(i);
	}
	int n2 = n + K;
	queue <int> Q;
	dep[n2] = 1;
	Q.push(n2);
	int bcnt = 0;
	while (Q.size()) {
		int tp = Q.front();
		Q.pop();
		bfn[++bcnt] = tp;
		for (auto v : G[tp]) {
			if (v == fa[tp]) continue;
			fa[v] = tp;
			son[tp].push_back(v);
			dep[v] = dep[tp] + 1;
			Q.push(v);
		}
	}
	rep (i, 1, n2) {
		if (dep[i] < K) continue;
		kfa[i] = i;
		rep (j, 1, K) kfa[i] = fa[kfa[i]];
	}
	rep (i, 1, n2) kson[0][i].push_back(i);
	rep (i, 0, K - 1) {
		rep (j, 1, n2) {
			for (auto s : son[j]) {
				for (auto ks : kson[i][s]) {
					kson[i + 1][j].push_back(ks);
				}
			}
		}
	}
	reverse(bfn + 1, bfn + 1 + bcnt);
	rep (i, 1, n2) siz[i] = 1;
	rep (i, 1, bcnt) {
		const int u = bfn[i];
		for (auto &v : son[u]) {
			siz[u] += siz[v];
			if (siz[v] > siz[son[u][0]]) swap(v, son[u][0]);
		}
	}
	reverse(bfn + 1, bfn + 1 + bcnt);
	rep (i, 1, bcnt) {
		const int u = bfn[i];
		for (auto v : son[u]) {
			if (v == son[u][0]) tdep[v] = tdep[u] + 1;
			else tdep[v] = 0;
		}
	}
	memset(khs, -1, sizeof khs);
	rep (i, 1, n2) {
		khs[0][i] = i;
		rep (j, 0, K - 1) {
			if (~khs[j][i] && son[khs[j][i]].size()) {
				khs[j + 1][i] = son[khs[j][i]][0];
			}
		}
	}
	memset(st1, -1, sizeof st1);
	dfs1(n2);
	dfs2(n2);
	rep (i, 1, bcnt) {
		const int u = bfn[i];
		if (u > n) continue;
		if (tdep[u] > K) top[u] = top[fa[u]];
		else top[u] = u;
	}
	const int inf = 0x3f3f3f3f;
	memset(minn, 0x3f, sizeof minn);
	memset(maxn, -1, sizeof maxn);
	rep (i, 1, n) {
		int u = i;
		rep (j, 0, K) {
			if (tdep[i] < K) {
				minn[j][u] = min(minn[j][u], st1[i]);
				maxn[j][u] = max(maxn[j][u], st1[i]);
			}
			if (u == n2) break;
			u = fa[u];
		}
	}
	// rep (i, 1, n2) {
		// rep (j, 0, K) {
			// cout << i << " " << j << ":" << minn[j][i] << " " << maxn[j][i] << endl;
		// }
	// }
	rep (i, 1, n) {
		w[st1[i]] = _w[i];
	}
	seg::build(1, 1, n);
	while (q --> 0) {
		int op = read();
		if (op == 1) {
			int u = read();
			print(seg::query(1, 1, n, st1[u], st1[u])), putchar(10);
		}
		else if (op == 2) {
			int u = read(), k = read(), c = read(), d = read();
			rep (i, 0, k) {
				_rep (j, k - i, max(k - i - 1, 0)) {
					if (minn[j][u] != inf) {
						// cout << "modify:" << minn[j][u] << " " << maxn[j][u] << endl;
						// cout << "modifypos" << j << " " << u << " " << minn[j][u] << endl;
						modify(minn[j][u], maxn[j][u], c, d);
					}
					if (khs[j][u] != -1 && khs[j][u] <= n) {
						if (tdep[khs[j][u]] >= K) {
							// cout << "modifypos" << st1[khs[j][u]] << endl;
							modify(st1[khs[j][u]], st1[khs[j][u]], c, d);
						}
					}
				}
				u = fa[u];
			}
		}
		else if (op == 3) {
			int u = read(), c = read(), d = read();
			cout << "sb:" << st2[u] << " " << ed2[u] << endl;
			cout << "sb:" << st3[u] << " " << ed3[u] << endl;
			modify(st2[u], ed2[u], c, d);
			rep (i, 0, K) {
				if (minn[i][u] != inf) {
					cout << "sc:" << minn[i][u] << " " << maxn[i][u] << endl;
					modify(minn[i][u], maxn[i][u], c, d);
				}
			}
			modify(st3[u], ed3[u], c, d);
		}
		else {
			int u = read(), v = read(), c = read(), d = read();
			while (top[u] != top[v]) {
				if (dfn[u] > dfn[v]) swap(u, v);
				modify(st1[top[v]], st1[v], c, d);
				v = fa[top[v]];
			}
			if (dfn[u] > dfn[v]) swap(u, v);
			modify(st1[u], st1[v], c, d);
		}
	}
	return 0;
}
