#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

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

const int MAXN = 1e6 + 5;
const int BLK = 300;
int n, m, q;
int a[MAXN], bel[MAXN], pos[MAXN];
int tran[MAXN], f[MAXN], cnt[MAXN], dis[MAXN];
int id[MAXN], key[MAXN], btn[MAXN], fp[MAXN], way[MAXN];
int tmp[MAXN], val[MAXN], lg[MAXN];
vector <int> v[BLK + 5];
vector <int> G[MAXN];

struct query {
	int x, l, r;
} Q[MAXN];

namespace TCS {
	int cnt;
	int dep[MAXN], hSon[MAXN], dfn[MAXN];
	int top[MAXN], down[MAXN], up[MAXN], siz[MAXN], fa[MAXN][20];

	void gsiz(int u) {
		for (auto v : G[u]) {
			dep[v] = dep[u] + 1;
			fa[v][0] = u;
			rep (i, 1, 16) fa[v][i] = fa[fa[v][i - 1]][i - 1];
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

	int kth(int u, int k) {
		if (!k) return u;
		int x = fa[u][lg[k]], y = top[x], c = dep[x] - dep[y];
		k ^= 1 << lg[k];
		return k <= c ? down[dfn[y] + c - k] : up[dfn[y] + k - c];
	}

	void move(int &x, int u, int tmp = 0) {
		x == u ? 0 : x = (x != fa[tmp = (dep[u] > dep[x] ? kth(u, dep[u] - dep[x] - 1) : 0)][0] ? fa[x][0] : tmp);
	}
} // namespace TCS

int mem[MAXN];

class List {
	int h, siz;
	int* frt;
	int nxt(int x, int y) {if ((x += y) >= siz) x -= siz; return x;}
public:
	int& operator[] (const int idx) {return frt[nxt(h, idx - 1)];}
	int& front() {return frt[h];}
	int& back() {return frt[nxt(h, siz - 1)];}
	int pop_front(int res = 0) {return res = frt[h], frt[h] = 0, h = nxt(h, 1), res;}
	int pop_back(int res = 0) {return h = nxt(h, siz - 1), res = frt[h], frt[h] = 0, res;}
	int& size() {return siz;}
	List(int h, int siz, int* ptr): h(h), siz(siz), frt(ptr) {}
	List() {}
} t[MAXN];

int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}
void merge(int &x, int y) {(!x) ? x = y : y ? f[find(y)] = find(x) : 0;}

signed main() {
	n = read(), q = read();
	rep (i, 2, n) G[read()].emplace_back(i);
	rep (i, 1, n) a[i] = read(), bel[i] = (i - 1) / BLK + 1;
	rep (i, 1, q) Q[i].x = read(), Q[i].l = read(), Q[i].r = read();
	TCS::init();
	rep (i, 1, bel[n]) {
		int st = (i - 1) * BLK + 1, ed = min(i * BLK, n), len = ed - st + 1;
		rep (j, 1, n) f[j] = pos[j] = j, cnt[j] = dis[j] = 0;
		cnt[1] = 1e9;
		rep (j, st, ed) cnt[a[j]] = 1e9;
		_rep (j, n, 1) cnt[TCS::fa[j][0]] += cnt[j] != 0;
		rep (j, 1, len) vector <int> ().swap(v[j]);
		id[1] = 0, key[m = 0] = val[0] = 1;
		for (int j = 2, now = 1; j <= n; j++) {
			if (cnt[j] >= 2) {
				id[j] = ++m, key[m] = val[m] = j, t[m] = {0, 0, mem + now};
				int k = TCS::fa[j][0];
				while (cnt[k] == 1) mem[now++] = k, btn[k] = j, k = TCS::fa[k][0];
				fp[m] = id[k], t[m].size() = TCS::dep[j] - TCS::dep[k] - 1;
			}
			else if (cnt[j] == 0) {
				dis[j] = dis[TCS::fa[j][0]] + 1, pos[j] = pos[TCS::fa[j][0]];
				dis[j] <= len ? (void) (v[dis[j]].emplace_back(j)) : (void) (tran[j] = TCS::kth(j, len));
			}
		}
		rep (j, st, ed) {
			for (int k = id[a[j]]; k; k = fp[k]) way[k] = j;
			for (int k = 0, t; k <= m; k++) tmp[k] = k != id[a[j]] ? t = val[k], val[k] = 0, t : tmp[k];
#define cond (way[k] == j)
			rep (k, 1, m) t[k].size() ? merge(cond ? val[k] : val[fp[k]], cond ? t[k].pop_front() : t[k].pop_back()) : (void) 0;
#define icond (key[fp[k]] == TCS::fa[key[k]][0])
			rep (k, 1, m) merge(cond ? icond ? val[k] : t[k].back() : icond ? val[fp[k]] : t[k].front(), cond ? tmp[fp[k]] : tmp[k]);
#undef icond
#undef cond
			for (auto u : v[j - st + 1]) {
				int v = pos[u], x = btn[v];
				merge(cnt[v] >= 2 ? val[id[v]] : t[id[x]][TCS::dep[x] - TCS::dep[v]], u);
			}
		}
		rep (j, 0, m) {
			tran[val[j]] = key[j];
			for (int k = 1, u = TCS::fa[key[j]][0]; k <= t[j].size(); k++, u = TCS::fa[u][0]) tran[t[j][k]] = u;
		}
		rep (j, 1, n) if (find(j) != j) tran[j] = tran[find(j)];
		rep (j, 1, q)
			if (Q[j].l <= st && Q[j].r >= ed) Q[j].x = tran[Q[j].x];
			else rep (k, max(st, Q[j].l), min(ed, Q[j].r)) TCS::move(Q[j].x, a[k]);
	}
	rep (i, 1, q) print(Q[i].x), putchar(10);
}
