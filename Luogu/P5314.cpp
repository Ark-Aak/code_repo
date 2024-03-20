#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 1e6 + 5;

int n, m;
int val[MAXN];
vector <int> G[MAXN];

struct node {
	int val, id;

	bool operator < (const node &t) const {
		return (val == t.val ? id < t.id : val < t.val);
	}
};

tree <node, null_type,
	 less <node>,
	 rb_tree_tag,
	 tree_order_statistics_node_update
> tr[MAXN];

#define lowbit(x) ((x) & -(x))

namespace BIT {
	int sum[MAXN];

	void add(int x, int val) {
		if (!x) return;
		for (int j = x; j <= n; j += lowbit(j))
			sum[j] += val;
	}

	int query(int x) {
		int res = 0;
		for (int j = x; j; j -= lowbit(j))
			res += sum[j];
		return res;
	}

	void modify(int l, int r, int val) {
		add(l, val), add(r + 1, -val);
	}
}

#define MAXH 7

namespace TCS {

	int dfn[MAXN], hSon[MAXN][10], siz[MAXN], hCnt[MAXN];
	int fa[MAXN], top[MAXN], cnt, dep[MAXN];

	void getSiz(int step, int u, int fa) {
		siz[u] = 1; TCS::fa[u] = fa;
		dep[u] = step;
		for (auto v : G[u]) {
			if (v == fa) continue;
			getSiz(step + 1, v, u);
			siz[u] += siz[v];
			hSon[u][++hCnt[u]] = v;
			int ptr = hCnt[u];
			if (hCnt[u] > MAXH) hCnt[u] = MAXH;
			while (ptr > 1 && siz[hSon[u][ptr]] > siz[hSon[u][ptr - 1]])
				swap(hSon[u][ptr], hSon[u][ptr - 1]), ptr--;
		}
	}

	void getDFN(int u, int h) {
		top[u] = h, dfn[u] = ++cnt;
		BIT::modify(cnt, cnt, val[u]);
		if (!hCnt[u]) return;
		rep (i, 1, hCnt[u]) getDFN(hSon[u][i], h);
		for (auto v : G[u]) {
			if (v == fa[u]) continue;
			bool flg = 0;
			rep (i, 1, hCnt[u]) if (v == hSon[u][i]) flg = 1;
			if (flg) continue;
			getDFN(v, v);
			tr[u].insert({val[v], v});
		}
	}

	void modify(int x, int y, int k) {
		while (top[x] != top[y]) {
			if (dep[top[x]] < dep[top[y]]) swap(x, y);
			int tp = top[x];
			tr[fa[tp]].erase({val[tp], tp});
			BIT::modify(dfn[tp], dfn[x], k);
			val[tp] = BIT::query(dfn[tp]);
			tr[fa[tp]].insert({val[tp], tp});
			x = fa[tp];
		}
		if (dep[x] > dep[y]) swap(x, y);
		BIT::modify(dfn[x], dfn[y], k);
		if (!fa[x] || dep[x] != dep[top[x]]) return;
		tr[fa[x]].erase({val[x], x});
		val[x] = BIT::query(dfn[x]), tr[fa[x]].insert({val[x], x});
	}
}

void insert(int x, int y) {
	if (!y) return;
	tr[x].insert({BIT::query(TCS::dfn[y]), y});
}

void remove(int x, int y) {
	if (!y) return;
	tr[x].erase({BIT::query(TCS::dfn[y]), y});
}

int main() {
	read(n), read(m);
	rep (i, 1, n) read(val[i]);
	rep (i, 1, n - 1) {
		int u, v;
		read(u), read(v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	TCS::getSiz(1, 1, 0);
	TCS::getDFN(1, 1);
	while (m --> 0) {
		int op, x, y, k;
		read(op);
		read(x), read(y);
		if (op == 1) {
			read(k);
			TCS::modify(x, y, k);
			continue;
		}
		cout << "debug:" << endl;
		rep (i, 1, n) cout << TCS::dfn[i] << " ";
		cout << endl;
		rep (i, 1, n) cout << BIT::query(i) << " ";
		cout << endl;
		cout << "-----------" << endl;
		insert(x, x);
		rep (i, 1, TCS::hCnt[x]) insert(x, TCS::hSon[x][i]);
		insert(x, TCS::fa[x]);
		print(tr[x].find_by_order(y - 1) -> val), putchar(10);
		remove(x, x);
		rep (i, 1, TCS::hCnt[x]) remove(x, TCS::hSon[x][i]);
		remove(x, TCS::fa[x]);
	}
	return 0;
}
