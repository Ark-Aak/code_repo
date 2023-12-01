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

#define int ll
#define mid ((L + R) >> 1)
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)

const int MAXN = 1e5 + 5;
int n, m;
vector <int> G[MAXN];

namespace TCS {

	int dfn[MAXN], wSon[MAXN], hSon[MAXN];
	int cnt, fa[MAXN], dep[MAXN], top[MAXN];

	void getSize(int step, int u, int f) {
		wSon[u] = 1; fa[u] = f; dep[u] = step;
		for (auto v : G[u]) {
			if (v == f) continue;
			getSize(step + 1, v, u);
			wSon[u] += wSon[v];
			if (wSon[v] > wSon[hSon[u]]) hSon[u] = v;
		}
	}

	void getDFN(int u, int header) {
		dfn[u] = ++cnt, top[u] = header;
		if (!hSon[u]) return;
		getDFN(hSon[u], header);
		for (auto v : G[u]) {
			if (v == fa[u] || v == hSon[u]) continue;
			getDFN(v, v);
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
}

class SegmentTree {

#define mid ((L + R) >> 1)

	struct node {
		node *ls, *rs;
		int res, sum;

		node() {res = 0, sum = 0, ls = nullptr, rs = nullptr;}
		node(int _res, int _sum) : res(_res), sum(_sum) {ls = nullptr, rs = nullptr;}
	};

	node* root;
	node* newNode(int res, int sum) {
		return new node(res, sum);
	};

	void pushup(node* cur) {
		if (!cur) return;
		if (!cur -> ls && !cur -> rs) return;
		if (cur -> rs != nullptr && (cur -> ls == nullptr || cur -> ls -> sum  < cur -> rs -> sum)) {
			cur -> res = cur -> rs -> res;
			cur -> sum = cur -> rs -> sum;
		}
		else if (cur -> ls != nullptr && (cur -> rs == nullptr || cur -> ls -> sum >= cur -> rs -> sum)) {
			cur -> res = cur -> ls -> res;
			cur -> sum = cur -> ls -> sum;
		}
	}

	node* merge(node* cura, node* curb, int L, int R) {
		if (!cura) return curb;
		if (!curb) return cura;
		if (L == R) {
			cura -> sum += curb -> sum;
			return cura;
		}
		cura -> ls = merge(cura -> ls, curb -> ls, L, mid);
		cura -> rs = merge(cura -> rs, curb -> rs, mid + 1, R);
		pushup(cura);
		return cura;
	}

	node* modify(node* cur, int L, int R, int pos, int val) {
		if (!cur) cur = newNode(0, 0);
		if (L == R) return cur -> sum += val, cur -> res = pos, cur;
		if (pos <= mid) cur -> ls = modify(cur -> ls, L, mid, pos, val);
		else cur -> rs = modify(cur -> rs, mid + 1, R, pos, val);
		pushup(cur);
		return cur;
	}

#undef mid

public:

	SegmentTree() {
		root = newNode(0, 0);
	}
	
	void merge(node* cur) {
		root = merge(root, cur, 1, 1e5);
	};

	void modify(int pos, int val) {
		root = modify(root, 1, 1e5, pos, val);
	};

	node* getRoot() {
		return root;
	};
};

SegmentTree T[MAXN];

using TCS::getSize;
using TCS::getDFN;

namespace Solution {
	int ans[MAXN];

	function <void (int)> dfs = [](int u) {
		for (auto v : G[u]) {
			if (v == TCS::fa[u]) continue;
			dfs(v);
			T[u].merge(T[v].getRoot());
		}
		ans[u] = T[u].getRoot() -> res;
		cerr << "node = " << u << " " << T[u].getRoot() -> res << " " << T[u].getRoot() -> sum << endl;
		if (T[u].getRoot() -> sum == 0) ans[u] = 0;
	};
}

signed main() {
	read(n), read(m);
	rep (i, 1, n - 1) {
		int u, v;
		read(u), read(v);
		G[u].emplace_back(v);
		G[v].emplace_back(u);
	}
	getSize(1, 1, 1);
	getDFN(1, 1);
	rep (i, 1, m) {
		int a, b, c, lca;
		read(a), read(b), read(c);
		T[a].modify(c, 1);
		T[b].modify(c, 1);
		T[lca = TCS::LCA(a, b)].modify(c, -1);
		T[TCS::fa[lca]].modify(c, -1);
	}
	Solution::dfs(1);
	rep (i, 1, n) print(Solution::ans[i]), putchar(10);
	return 0;
}
