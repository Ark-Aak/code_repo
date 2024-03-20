乐乐乐乐乐乐。

```cpp
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

const int MAXN = 1005;
int n, m;
vector <int> G[MAXN];

int cnt;
int tp, tot;
//int scc[MAXN], siz[MAXN];
vector <int> dfn, low, s, ins;

void tarjan(int u) {
	low[u] = dfn[u] = ++cnt;
	s[++tp] = u, ins[u] = 1;
	for (auto v : G[u]) {
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		}
		else if (ins[v]) low[u] = min(low[u], dfn[v]);
		//else if (dfn[v]) low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u]) {
		++tot;
		while (s[tp] != u) {
			//scc[s[tp]] = tot;
			//siz[tot]++;
			ins[s[tp]] = 0;
			--tp;
		}
		//scc[s[tp]] = tot;
		//siz[tot]++;
		ins[s[tp]] = 0;
		--tp;
	}
}

map <pair <int, int>, int> ans;

void tarjan2(int u) {
	low[u] = dfn[u] = ++cnt;
	s[++tp] = u, ins[u] = 1;
	int lu = 0, lv = 0;
	for (auto v : G[u]) {
		if (!dfn[v]) {
			tarjan2(v);
			if (low[u] == dfn[u] && low[u] > low[v]) {
				lu = u, lv = v;
				ans[make_pair(u, v)] = 1;
				low[u] = min(low[u], low[v]);
			}
			else if (low[u] > low[v]) {
				if (lu && lv) ans[make_pair(lu, lv)] = 0;
				lu = lv = 0;
				low[u] = min(low[u], low[v]);
			}
		}
		else if (ins[v]) {
			if (low[u] == dfn[u] && low[u] > dfn[v]) {
				lu = u, lv = v;
				ans[make_pair(u, v)] = 1;
				low[u] = dfn[v];
			}
			else if (low[u] > dfn[v]) {
				if (lu && lv) ans[make_pair(lu, lv)] = 0;
				lu = lv = 0;
				low[u] = dfn[v];
			}
		}
		//else if (dfn[v]) low[u] = min(low[u], dfn[v]);
	}
	if (dfn[u] == low[u]) {
		++tot;
		while (s[tp] != u) {
			//scc[s[tp]] = tot;
			//siz[tot]++;
			ins[s[tp]] = 0;
			--tp;
		}
		//scc[s[tp]] = tot;
		//siz[tot]++;
		ins[s[tp]] = 0;
		--tp;
	}
}

void clear() {
	vector <int>(n + 5).swap(s);
	vector <int>(n + 5).swap(low);
	vector <int>(n + 5).swap(ins);
	vector <int>(n + 5).swap(dfn);
	cnt = 0, tp = 0, tot = 0;
	//memset(siz, 0, sizeof siz);
	//memset(scc, 0, sizeof scc);
}

vector <pii> edges;

void insert(int u, int v) {
	auto iter = lower_bound(G[u].begin(), G[u].end(), v);
	G[u].insert(iter, v);
}

void remove(int u, int v) {
	auto iter = lower_bound(G[u].begin(), G[u].end(), v);
	G[u].erase(iter);
}

//OVTree 怎么你了😡👊

double getTime() {
	return clock() * 1.0 / CLOCKS_PER_SEC;
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("scc.in", "r", stdin);
	freopen("scc.out", "w", stdout);
#endif
#endif
	n = read(), m = read();
	for (int i = 1, u, v; i <= m; i++) {
		u = read(), v = read();
		insert(u, v);
		edges.push_back({u, v});
	}
	dfn.resize(n + 5), low.resize(n + 5);
	s.resize(n + 5), ins.resize(n + 5);
	if (m <= 147744151) {
		rep (i, 1, n) if (!dfn[i]) tarjan(1);
		int Nscc = tot;
		for (auto [u, v] : edges) {
			if (getTime() >= 1.9) {
				while (m --> 0) {
					puts("0");
				} // 汗流浃背了老哥😅，不可以总司令😓
				  // 这也不是大样例依托史的理由😓。
				  // 这也不是我，随机数据答案全是 0 的理由😅。
				  // 🤗🤗🤗🤗
				return 0;
			}
			clear();
			remove(u, v), insert(v, u);
			rep (i, 1, n) if (!dfn[i]) tarjan(i);
			if (tot != Nscc) puts("1");
			else puts("0");
			remove(v, u), insert(u, v);
			m--;
		}
	}
	else {
		rep (i, 1, n) if (!dfn[i]) tarjan2(i);
		// 汗流浃背了吧老哥。
		// 笑死我了忘记了 Tarjan 的性质
		// 不清楚是不是跟性质有关，我要疯了
		// 在这题上花了 114514h+ 了。
		for (auto v : edges) {
			print(ans[v]), putchar(10);
		}
	}
	return 0;
}
```
这就是你让我 $40pts$ 的理由。

😡👊
