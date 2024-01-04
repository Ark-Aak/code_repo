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

const int MAXN = 1e6 + 5;
int n, k;
vector <int> G[MAXN];
const int MOD = 1e9 + 7;

int qpow(int a, int b, int p) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % p;
		a = a * a % p;
		b >>= 1;
	}
	return res;
}

class SegmentTree {

#define mid ((L + R) >> 1)
#define MAXP 1000000

	struct node {
		node *ls, *rs;
		int sum;

		node() {
			sum = 0;
			ls = nullptr, rs = nullptr;
		}
		node(int _sum) : sum(_sum) {
			ls = nullptr, rs = nullptr;
		}
	};

	node* root;
	node* newNode(int sum) {
		return new node(sum);
	};

	void pushup(node* cur) {
		if (!cur) return;
		if (!cur -> ls && !cur -> rs) return;
		cur -> sum = (cur -> ls ? cur -> ls -> sum : 0) + (cur -> rs ? cur -> rs -> sum : 0);
	}

	node* merge(node* cura, node* curb, int L, int R) {
		if (!cura) return curb;
		if (!curb) return cura;
		if (L == R) {
			cura -> sum = (cura -> sum || curb -> sum);
			return cura;
		}
		cura -> ls = merge(cura -> ls, curb -> ls, L, mid);
		cura -> rs = merge(cura -> rs, curb -> rs, mid + 1, R);
		pushup(cura);
		return cura;
	}

	node* modify(node* cur, int L, int R, int pos, int val) {
		if (!cur) cur = newNode(0);
		if (L == R) return cur -> sum = val, cur;
		if (pos <= mid) cur -> ls = modify(cur -> ls, L, mid, pos, val);
		else cur -> rs = modify(cur -> rs, mid + 1, R, pos, val);
		pushup(cur);
		return cur;
	}

public:

	SegmentTree() {
		root = newNode(0);
	}

	void merge(node* cur) {
		merge(root, cur, 1, MAXP);
	};

	void modify(int pos, int val) {
		modify(root, 1, MAXP, pos, val);
	};

	node* getRoot() {
		return root;
	};

#undef mid
#undef MAXP
};

typedef long double ld;

SegmentTree T[MAXN];
int siz[MAXN];
ld ans = 1e12;
ld eps = 1e-9;
int frac[2];

int cmp(ld a, ld b) {
	if (a - b > eps) return 1;
	if (b - a > eps) return -1;
	return 0;
}

void dfs(int u, int fa) {
	siz[u] = 1;
	for (auto v : G[u]) {
		if (v == fa) continue;
		dfs(v, u);
		siz[u] += siz[v];
		T[u].merge(T[v].getRoot());
	}
	ld val = T[u].getRoot() -> sum * 1.0 / siz[u] * 1.0;
	if (cmp(ans, val) == 1) {
		ans = val;
		frac[0] = T[u].getRoot() -> sum;
		frac[1] = siz[u];
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("tree.in", "r", stdin);
	freopen("tree.out", "w", stdout);
#endif
#endif
	read(n), read(k);
	rep (i, 1, n) {
		int a;
		read(a);
		T[i].modify(a, 1);
	}
	rep (i, 3, n + 1) {
		int u;
		read(u);
		G[u].emplace_back(i - 1);
		G[i - 1].emplace_back(u);
	}
	dfs(1, 0);
	cout << (frac[0] * qpow(frac[1], MOD - 2, MOD) % MOD);
	return 0;
}
