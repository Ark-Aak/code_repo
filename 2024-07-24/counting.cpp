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

#define int ll

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
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 1e5 + 5;
const int MOD = 65536;

int C[51][51];

int qpow(int a, int b) {
	/* if (!(a & 1) && b >= 16) return 0; */
	int res = 1;
	while (b) {
		if (b & 1) res = 1ll * res * a & (MOD - 1);
		a = 1ll * a * a & (MOD - 1);
		b >>= 1;
	}
	return res;
}

int c(int n, int m) {
	return C[n + 1][m + 1];
}

struct Poly {

	int a[16];

	Poly() { memset(a, 0, sizeof a); }

	Poly operator*(const Poly &t) {
		Poly res;
		rep (i, 0, 15) {
			rep (j, 0, 15) {
				if (i + j > 15) break;
				res.a[i + j] = (res.a[i + j] + ((1ll * a[i] * t.a[j]) & (MOD - 1))) & (MOD - 1);
			}
		}
		return res;
	}

	Poly operator*(const int k) {
		// x <- (x + k)
		Poly res;
		res = *this;
		/* cout << "ppre: k = " << k << endl; */
		/* rep (i, 0, 15) cout << a[i] << " "; */
		/* cout << endl; */
		rep (i, 1, 15) {
			rep (j, 0, i - 1) {
				res.a[j] = (res.a[j] + ((1ll * c(i, i - j) * qpow(k, i - j) * a[i]) & (MOD - 1))) & (MOD - 1);
			}
		}
		/* cout << "paft:" << endl; */
		/* rep (i, 0, 15) cout << res.a[i] << " "; */
		/* cout << endl; */
		return res;
	}
};

vector <int> G[MAXN];
int n, tot = 1, cnt = 1;
unordered_map <int, int> vis;
set <tuple <int, int, int> > s;

namespace seg {

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)

	Poly val[MAXN << 2];
	int lazy[MAXN << 2];

	void pushup(int x) { val[x] = val[ls(x)] * val[rs(x)]; }

	void pushdown(int x) {
		val[ls(x)] = val[ls(x)] * lazy[x];
		val[rs(x)] = val[rs(x)] * lazy[x];
		lazy[ls(x)] = (lazy[ls(x)] + lazy[x]) & (MOD - 1);
		lazy[rs(x)] = (lazy[rs(x)] + lazy[x]) & (MOD - 1);
		lazy[x] = 0;
	}

	void build(int x, int L, int R) {
		if (L == R) return void(val[x].a[0] = val[x].a[1] = 1);
		build(ls(x), L, mid);
		build(rs(x), mid + 1, R);
		pushup(x);
	}

	void modify(int x, int L, int R, int l, int r, int k) {
		if (x == 0) return;
		if (l <= L && R <= r) {
			val[x] = val[x] * k;
			lazy[x] += k;
			return;
		}
		if (L != R && lazy[x]) pushdown(x);
		if (l <= mid) modify(ls(x), L, mid, l, r, k);
		if (r > mid) modify(rs(x), mid + 1, R, l, r, k);
		pushup(x);
	}

#undef ls
#undef rs
#undef mid
} // namespace seg

int dfn[MAXN], son[MAXN], siz[MAXN];
int f[MAXN], top[MAXN], _dfn;

void dfs0(int u, int fa) {
	siz[u] = 1;
	f[u] = fa;
	for (auto v : G[u]) {
		if (v == fa) continue;
		dfs0(v, u);
		siz[u] += siz[v];
		if (siz[v] > siz[son[u]]) son[u] = v;
	}
}

void dfs1(int u, int h) {
	dfn[u] = ++_dfn;
	top[u] = h;
	if (!son[u]) return;
	dfs1(son[u], h);
	for (auto v : G[u]) {
		if (v == f[u] || v == son[u]) continue;
		dfs1(v, v);
	}
}

void modify(int u, int k) {
	/* cout << u << " " << k << endl; */
	while (top[u] != 1) {
		seg::modify(1, 1, cnt, dfn[top[u]], dfn[u], k);
		u = f[top[u]];
	}
	seg::modify(1, 1, cnt, 1, dfn[u], k);
}

vector <pii> ques;

signed main() {
	rep (i, 1, 50) C[i][1] = C[i][i] = 1;
	rep (i, 3, 50) rep (j, 2, i - 1)
		C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) & (MOD - 1);
	n = read();
	vis[1] = 1;
	rep (i, 1, n) {
		int x = read(), k = read();
		if (!vis[x]) {
			vis[x] = ++cnt;
			int fa = get<2>(*s.lower_bound(dk(x, 0, 0)));
			G[fa].push_back(cnt);
			G[cnt].push_back(fa);
			/* cout << x << " => " << cnt << endl; */
			/* cout << fa << " <-> " << cnt << endl; */
		}
		// tot + 1 ~ tot + k
		x = vis[x];
		/* cout << tot + 1 << "~" << tot + k << " -> " << x << endl; */
		s.insert(dk(tot + k, tot + 1, x));
		tot = tot + k;
		ques.emplace_back(x, k);
	}
	dfs0(1, 0), dfs1(1, 1);
	seg::build(1, 1, cnt);
	for (auto [x, k] : ques) {
		modify(x, k);
		print(seg::val[1].a[0]), puts("");
	}
	return 0;
}
