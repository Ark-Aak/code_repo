#pragma GCC optimize("Ofast")
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
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 2e6 + 5, MAXM = 3e5 + 5;

bool stmem;

int n, m, q, a[MAXN], dep[MAXN];
int lg[MAXN];
vector <int> G[MAXN];

namespace LCA {

int dn, dfn[MAXN], st[22][MAXN];

inline int get(int x, int y) { return dfn[x] < dfn[y] ? x : y; }

void dfs(int id, int f) {
    st[0][dfn[id] = ++dn] = f;
    dep[id] = dep[f] + 1;
    for (int u : G[id]) dfs(u, id);
}

inline int lca(int u, int v) {
	if (u == 1 || v == 1) return 1;
    if (u == v) return u;
    if ((u = dfn[u]) > (v = dfn[v])) swap(u, v);
    int d = lg[v - u++];
    return get(st[d][u], st[d][v - (1 << d) + 1]);
}

void init() {
    dfs(1, 0);
    for (int i = 1; i <= lg[n]; i++)
        for (int j = 1; j + (1 << i) - 1 <= n; j++)
            st[i][j] = get(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
}

}

namespace ANC {
	int cnt;
	int hSon[MAXN], dfn[MAXN];
	int top[MAXN], down[MAXN], up[MAXN], siz[MAXN], fa[MAXN][22];

	void gsiz(int u) {
		for (auto v : G[u]) {
			fa[v][0] = u;
			rep (i, 1, 21) fa[v][i] = fa[fa[v][i - 1]][i - 1];
			gsiz(v); siz[u] = max(siz[u], siz[v] + 1);
			if (siz[v] > siz[hSon[u]]) hSon[u] = v;
		}
	}

	void gchain(int u, int tp, int p) {
		dfn[u] = ++cnt, top[u] = tp;
		down[cnt] = u, up[cnt] = p;
		if (!hSon[u]) return;
		gchain(hSon[u], tp, fa[p][0]);
		for (auto v : G[u]) {
			if (v == hSon[u]) continue;
			gchain(v, v, v);
		}
	}

	void init() {
		dep[1] = 1, gsiz(1), gchain(1, 1, 1);
		rep (i, 2, n) lg[i] = lg[i >> 1] + 1;
	}

	inline int kth(int u, int k) {
		if (!k) return u;
		if (dep[u] <= k) return 1;
		int x = fa[u][lg[k]], y = top[x], c = dep[x] - dep[y];
		k ^= 1 << lg[k];
		int p = (k <= c ? down[dfn[y] + c - k] : up[dfn[y] + k - c]);
		return p;
        /*

        rep (i, 1, k) u = fa[u][0];
        return u;

        */
	}
}

namespace seg {

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)

    int tp[MAXM << 2], LCA[MAXM << 2], mindep[MAXM << 2], who[MAXM << 2];
    int lazy[MAXM << 2];

    inline void pushup(int x, int L, int R) {
        if (L == R) return;
        LCA[x] = LCA::lca(LCA[ls(x)], LCA[rs(x)]);
        tp[x] = dep[LCA[x]];
        if (mindep[ls(x)] < mindep[rs(x)]) who[x] = who[ls(x)];
        else who[x] = who[rs(x)];
        mindep[x] = min(mindep[ls(x)], mindep[rs(x)]);
		assert(mindep[x] >= tp[x]);
    }

    void build(int x, int L, int R) {
        if (L == R) {
            tp[x] = dep[a[L]];
            LCA[x] = a[L];
            mindep[x] = dep[a[L]];
			assert(mindep[x] > 0);
            who[x] = a[L];
            return;
        }
        build(ls(x), L, mid);
        build(rs(x), mid + 1, R);
        pushup(x, L, R);
    }

    inline void pushdown(int x, int L, int R) {
        if (L == R) return;
        lazy[ls(x)] += lazy[x], lazy[rs(x)] += lazy[x];
        mindep[ls(x)] -= lazy[x], mindep[rs(x)] -= lazy[x];
        mindep[ls(x)] = max(mindep[ls(x)], 1);
        mindep[rs(x)] = max(mindep[rs(x)], 1);
		// cerr << who[ls(x)] << " -> " << lazy[x] << " -> " << ANC::kth(who[ls(x)], lazy[x]) << endl;
		// cerr << who[rs(x)] << " -> " << lazy[x] << " -> " << ANC::kth(who[rs(x)], lazy[x]) << endl;
        who[ls(x)] = ANC::kth(who[ls(x)], lazy[x]);
        who[rs(x)] = ANC::kth(who[rs(x)], lazy[x]);
        if (mindep[ls(x)] < tp[ls(x)]) {
            LCA[ls(x)] = who[ls(x)];
            tp[ls(x)] = mindep[ls(x)];
        }
        if (mindep[rs(x)] < tp[rs(x)]) {
            LCA[rs(x)] = who[rs(x)];
            tp[rs(x)] = mindep[rs(x)];
        }
        lazy[x] = 0;
    }

    void modify(int x, int L, int R, int l, int r) {
        if (l <= L && R <= r) {
            lazy[x]++;
            mindep[x]--;
			mindep[x] = max(mindep[x], 1);
            who[x] = ANC::kth(who[x], 1);
            if (tp[x] > mindep[x]) LCA[x] = who[x], tp[x] = mindep[x];
			assert(mindep[x] >= tp[x]);
            return;
        }
        if (lazy[x]) pushdown(x, L, R);
        if (l <= mid) modify(ls(x), L, mid, l, r);
        if (r > mid) modify(rs(x), mid + 1, R, l, r);
        pushup(x, L, R);
    }

    int query(int x, int L, int R, int l, int r) {
        if (l <= L && R <= r) {
            return LCA[x];
        }
        if (lazy[x]) pushdown(x, L, R);
        int lcaL = 0, lcaR = 0;
        if (l <= mid) lcaL = query(ls(x), L, mid, l, r);
        if (r > mid) lcaR = query(rs(x), mid + 1, R, l, r);
        if (lcaL && lcaR) return LCA::lca(lcaL, lcaR);
        else return lcaL | lcaR;
    }

} // namespace seg

bool edmem;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
    freopen("ac.in", "r", stdin);
    freopen("ac.out", "w", stdout);
#endif
#endif
    n = read(), m = read(), q = read();
	assert(n <= 2000000 && m <= 300000 && q <= 500000);
    rep (i, 2, n) {
        int fa = read();
        G[fa].push_back(i);
    }
    rep (i, 1, m) a[i] = read();
    ANC::init();
    LCA::init();
    seg::build(1, 1, m);
    while (q --> 0) {
        int op = read();
        if (op ^ 2) {
            int l = read(), r = read();
            seg::modify(1, 1, m, l, r);
        }
        else {
            int l = read(), r = read();
            print(seg::query(1, 1, m, l, r));
            puts("");
        }
    }
	return 0;
}