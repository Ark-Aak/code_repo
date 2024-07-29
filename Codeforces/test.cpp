#include <bits/stdc++.h>

#define rep(i, a, b) for (auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for (auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 1e6 + 5;
int n, m, root;
int dfn[MAXN], low[MAXN], cnt, ans, stk[MAXN], top;
vector <int> dcc[MAXN], G[MAXN];

void tarjan(int u, int fa) {
	dfn[u] = low[u] = ++cnt;
	stk[++top] = u;
	int son = 0;
	for (auto v : G[u]) {
		if (!dfn[v]) {
			son++;
			tarjan(v, u);
			low[u] = min(low[u], low[v]);
			if (low[v] >= dfn[u]) {
				int t = 0; ++ans;
				while (stk[top + 1] != v) dcc[ans].emplace_back(stk[top--]);
				dcc[ans].emplace_back(u);
			}
		}
		else if (v != fa) low[u] = min(low[u], dfn[v]);
	}
	if (u == fa && son == 0) {
		dcc[++ans].emplace_back(u);
		top--;
	}
}

signed main() {
	cin >> n >> m;
	rep (i, 1, m) {
		int u, v;
		cin >> u >> v;
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	rep (i, 1, n) {
		if (!dfn[i]) root = i, tarjan(i, i);
	}
	cout << ans << endl;
	rep (i, 1, ans) {
		cout << dcc[i].size() << " ";
		for (auto x : dcc[i]) cout << x << " ";
		cout << "\n";
	}
	return 0;
}
