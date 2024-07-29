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

const int MAXN = 1e5 + 5;
int n, m;
map <int, map <int, int> > G, T;
int low[MAXN], dfn[MAXN], stk[MAXN], top, cnt, tot;

void tarjan(int u, int fa) {
	low[u] = dfn[u] = ++cnt;
	stk[++top] = u;
	for (auto [v, ignore] : G[u]) {
		if (!dfn[v]) {
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] >= dfn[u]) {
				++tot;
				while (stk[top + 1] != v) {
					T[tot][stk[top]] = T[stk[top]][tot] = 1;
					top--;
				}
				T[tot][u] = T[u][tot] = 1;
			}
		}
		else if (v != fa) low[u] = min(low[u], low[v]);
	}
}

signed main() {
	n = read(), m = read();
	while (n || m) {
		tot = n;
		top = cnt = 0;
		map <int, map <int, int> >().swap(G);
		map <int, map <int, int> >().swap(T);
		rep (i, 1, m) {
			int u = read(), v = read();
			G[u][v] = 1;
		}
		n = read(), m = read();
		tarjan(1, 1);

	}
	return 0;
}
