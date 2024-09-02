#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <bits/extc++.h>
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

namespace IO {
const int MAXSIZE = 1 << 21;
char buf[MAXSIZE], *p1, *p2;
#define gc()                                                               \
  (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, MAXSIZE, stdin), p1 == p2) \
       ? EOF                                                               \
       : *p1++)

int rd() {
  int x = 0, f = 1;
  char c = gc();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = gc();
  }
  while (isdigit(c)) x = x * 10 + (c ^ 48), c = gc();
  return x * f;
}

char pbuf[1 << 20], *pp = pbuf;

void push(const char &c) {
  if (pp - pbuf == 1 << 20) fwrite(pbuf, 1, 1 << 20, stdout), pp = pbuf;
  *pp++ = c;
}

void write(int x) {
  static int sta[35];
  int top = 0;
  do {
    sta[top++] = x % 10, x /= 10;
  } while (x);
  while (top) push(sta[--top] + '0');
}
}  // namespace IO

const int MAXN = 1e6 + 5;
int T, n;
vector <int> G[MAXN];
vector <pii> edges;
int fa[MAXN], son[MAXN], top[MAXN], siz[MAXN];
int dep[MAXN];
unordered_map <int, int> id[MAXN];

void dfs0(int u, int f) {
	siz[u] = 1, fa[u] = f;
	for (auto v : G[u]) {
		if (v ^ f) {
			dep[v] = dep[u] + 1, dfs0(v, u);
			siz[u] += siz[v];
			if (siz[son[u]] < siz[v]) son[u] = v;
		}
	}
}

void dfs1(int u, int tp) {
	top[u] = tp;
	if (!son[u]) return;
	dfs1(son[u], tp);
	for (auto v : G[u]) {
		if (v == son[u] || v == fa[u]) continue;
		dfs1(v, v);
	}
}

inline int LCA(int u, int v) {
	while (top[u] != top[v]) {
		if (dep[top[u]] < dep[top[v]]) swap(u, v);
		u = fa[top[u]];
	}
	return dep[u] < dep[v] ? u : v;
}

int ufa[MAXN], ans[MAXN], fans[MAXN];

int find(int u) { return ufa[u] == u ? u : (ufa[u] = find(ufa[u])); }

void solve() {
	edges.clear();
	n = IO::rd();
	rep (i, 1, n) G[i].clear();
	rep (i, 1, n) dep[i] = top[i] = son[i] = fa[i] = siz[i] = 0;
	rep (i, 1, n) ufa[i] = i, ans[i] = 0, fans[i] = 0;
	rep (i, 1, n) id[i].clear();
	rep (i, 1, n - 1) {
		int u = IO::rd(), v = IO::rd();
		id[u][v] = id[v][u] = i;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs0(1, 1), dfs1(1, 1);
	_rep (i, n / 2, 1) {
		int lca = i;
		for (int j = i * 2; j <= n; j += i) {
			lca = LCA(lca, j);
		}
		for (int j = i; j <= n; j += i) {
			int tp = find(j);
			while (dep[tp] > dep[lca]) {
				ans[tp] = i;
				tp = find(fa[tp]);
			}
			ufa[find(j)] = find(lca);
		}
	}
	rep (i, 1, n) {
		if (ans[i]) {
			fans[id[i][fa[i]]] = ans[i];
		}
	}
	rep (i, 1, n - 1) IO::write(fans[i]), putchar(32);
	puts("");
}

signed main() {
	int size(256 << 20);
	__asm__ ( "movq %0, %%rsp\n"::"r"((char*) malloc(size) + size));
	T = IO::rd();
	while (T --> 0) solve();
	exit(0);
}
