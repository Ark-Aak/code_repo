#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
#pragma GCC optimize(3)

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair

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

const int MAXN = 3e5 + 5;

#define mid ((L + R) >> 1)
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)

vector <int> G[MAXN];

int n, q;
int sum[MAXN << 2], tag[MAXN << 2], S;
int sz[MAXN], dep[MAXN], f[MAXN][19], top[MAXN];
int son[MAXN], lg[MAXN], xl[MAXN], idx, dfn[MAXN];

inline void pushdown(int x, int L, int R) {
    if (tag[x]) {
        tag[ls(x)] += tag[x];
        tag[rs(x)] += tag[x];
        sum[ls(x)] += tag[x] * (mid - L + 1);
        sum[rs(x)] += tag[x] * (R - mid);
        tag[x] = 0;
    }
}

void modify(int x, int L, int R, int l, int r, int val) {
    if (l <= L && R <= r) {
        tag[x] += val;
        sum[x] += 1ll * val * (R - L + 1);
        S += 1ll * val * (R - L + 1);
        return;
    }
    pushdown(x, L, R);
    if (l <= mid) modify(ls(x), L, mid, l, r, val);
    if (mid < r) modify(rs(x), mid + 1, R, l, r, val);
    sum[x] = sum[ls(x)] + sum[rs(x)];
}

int query(int x, int L, int R, int l, int r) {
    if (l <= L && R <= r)
        return sum[x];
    pushdown(x, L, R);
    int ans = 0;
    if (l <= mid) ans += query(ls(x), L, mid, l, r);
    if (mid < r) ans += query(rs(x), mid + 1, R, l, r);
    return ans;
}

int bound(int x, int L, int R, int val) {
    if (L == R) return L;
    pushdown(x, L, R);
    if (sum[ls(x)] >= val) return bound(ls(x), L, mid, val);
    return bound(rs(x), mid + 1, R, val - sum[ls(x)]);
}

void dfs1(int u, int fa) {
    dep[u] = dep[f[u][0] = fa] + 1;
    for (int i = 1; i <= lg[dep[u]]; ++i) f[u][i] = f[f[u][i - 1]][i - 1];
    sz[u] = 1;
    for (auto v : G[u]) {
        if (v ^ fa) {
            dfs1(v, u);
            sz[u] += sz[v];
            if (sz[v] > sz[son[u]]) son[u] = v;
        }
    }
}
void dfs2(int u, int topf) {
    top[u] = topf;
    xl[dfn[u] = ++idx] = u;
    if (!son[u]) return;
    dfs2(son[u], topf);
    for (auto v : G[u]) {
        if (v ^ son[u] && v ^ f[u][0]) {
            dfs2(v, v);
        }
    }
}

inline void solve(int x, int y, int val) {
    while (top[x] ^ top[y]) {
        if (dep[top[x]] < dep[top[y]]) swap(x, y);
        modify(1, 1, n, dfn[top[x]], dfn[x], val);
        x = f[top[x]][0];
    }
    if (dep[x] > dep[y]) swap(x, y);
    modify(1, 1, n, dfn[x], dfn[y], val);
}

inline int F(int p) { return query(1, 1, n, dfn[p], dfn[p] + sz[p] - 1); }

inline int Solve() {
    int p = xl[bound(1, 1, n, (S + 1) >> 1)];
    const int k = S >> 1;
    if (F(p) > k)
        return p;
    for (int i = lg[dep[p]]; ~i; --i)
        if (f[p][i] && F(f[p][i]) <= k)
            p = f[p][i];
    return f[p][0];
}

signed main() {

    /* freopen("yyl.in", "r", stdin); */
    /* freopen("yyl.out", "w", stdout); */

    n = read();
    for (int i = 2; i <= n; ++i) lg[i] = lg[i >> 1] + 1;
    for (int i = 1; i < n; ++i) {
        int u = read(), v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    dfs1(1, 0);
    dfs2(1, 1);
    q = read();
    while (q --> 0) {
        int opt = read(), u = read();
        if (opt == 1) {
            int c = read();
            modify(1, 1, n, dfn[u], dfn[u] + sz[u] - 1, c);
        }
        else {
            int v = read(), c = read();
            solve(u, v, c);
        }
        print(Solve()), putchar(10);
    }
    return 0;
}
