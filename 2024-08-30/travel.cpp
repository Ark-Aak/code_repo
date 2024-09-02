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
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 1e5 + 5;
const int B = 300;
int n, q;
int a[MAXN], val[MAXN], prot[MAXN], f[MAXN];
int now, lst[MAXN];
vector <int> G[MAXN];

void dfs0(int u, int fa) {
    val[u] = prot[u] ? 0 : max(0, a[u] - (now - lst[u]));
    for (auto v : G[u]) {
        if (v ^ fa) {
            dfs0(v, u);
            val[u] = max(val[u], val[v] - 1);
        }
    }
}

void dfs1(int u, int fa, int top) {
    f[u] = max(val[u], top);
	int max1 = 0, max2 = 0;
	for (auto v : G[u]) {
		if (v ^ fa) {
			if (val[v] - 1 > max1) {
				max2 = max1;
				max1 = val[v] - 1;
			}
			else max2 = max(max2, val[v] - 1);
		}
	}
    for (auto v : G[u]) {
        if (v ^ fa) {
			top = max(top, prot[u] ? 0 : max(0, a[u] - (now - lst[u])));
			dfs1(v, u, max(top, val[v] - 1 == max1 ? max2 : max1) - 1);
        }
    }
}

namespace LCA {

	int dfn[MAXN], wSon[MAXN], hSon[MAXN];
	int cnt, fa[MAXN], dep[MAXN], top[MAXN];

	void dfs0(int step, int u, int f) {
		wSon[u] = 1; fa[u] = f; dep[u] = step;
		for (auto v : G[u]) {
			if (v == f) continue;
			dfs0(step + 1, v, u);
			wSon[u] += wSon[v];
			if (wSon[v] > wSon[hSon[u]]) hSon[u] = v;
		}
	}

	void dfs1(int u, int header) {
		dfn[u] = ++cnt, top[u] = header;
		if (!hSon[u]) return;
		dfs1(hSon[u], header);
		for (auto v : G[u]) {
			if (v == fa[u] || v == hSon[u]) continue;
			dfs1(v, v);
		}
	}

	int LCA(int x, int y) {
		while (top[x] != top[y]) {
			if (dep[top[x]] < dep[top[y]]) swap(x, y);
			x = fa[top[x]];
		}
		if (dep[x] > dep[y]) swap(x, y);
		return x;
	}
} // namespace LCA

inline int dis(int u, int v) {
    return LCA::dep[u] + LCA::dep[v] - 2 * LCA::dep[LCA::LCA(u, v)];
}

vector <tuple <int, int, int> > s;
multiset <int> pt;

int lst_rebuild = 0;

inline void rebuild(bool flg) {
    if (s.size() < B && !flg) return;
    lst_rebuild = now;
    dfs0(1, 0);
    dfs1(1, 0, 0);
    s.clear();
}

int work(int u) {
    int ans = max(0, pt.size() ? *pt.rbegin() : 0);
    ans = max(ans, f[u] - (now - lst_rebuild));
    for (tuple <int, int, int> res : s) {
        int x = get<0>(res), y = get<1>(res), v = get<2>(res);
        ans = max(ans, y - (now - x) - dis(u, v));
    }
    return ans;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
#endif
#endif
    n = read(), q = read();
    rep (i, 1, n) a[i] = read();
    rep (i, 1, n - 1) {
        int u = read(), v = read();
        G[u].push_back(v);
        G[v].push_back(u);
    }
    LCA::dfs0(1, 1, 1);
    LCA::dfs1(1, 1);
    rebuild(true);
    while (q --> 0) {
        int op = read(), t = read(), x = read();
        now = t;
        rebuild(false);
        if (op == 1) {
            prot[x] = 1;
            a[x] -= now - lst[x];
			a[x] = max(a[x], 0);
            pt.insert(a[x]);
        }
        else if (op == 2) {
            prot[x] = 0;
            pt.erase(pt.find(a[x]));
            lst[x] = now;
            s.push_back(dk(now, a[x], x));
        }
        else {
            print(work(x)), puts("");
        }
    }
    cerr << clock() * 1.0 / CLOCKS_PER_SEC << " sec";
	return 0;
}
