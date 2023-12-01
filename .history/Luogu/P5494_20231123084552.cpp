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

class SegmentTree {

#define mid ((L + R) >> 1)
#define MAXP 10

	struct node {
		node *ls, *rs;
		int sum;

		node() {sum = 0, ls = nullptr, rs = nullptr;}
		node(int _sum) : sum(_sum) {ls = nullptr, rs = nullptr;}
	};

	node* root;
	node* newNode(int sum) {
		return new node(sum);
	};

	void pushup(node* &cur) {
		if (!cur) return;
		cur -> sum = (cur -> ls ? cur -> ls -> sum : 0) + (cur -> rs ? cur -> rs -> sum : 0);
	}

	void merge(node* &cura, node* &curb, int L, int R) {
		if (!curb) return;
		if (!cura) {
			cura = newNode(0);
			cura -> sum = curb -> sum;
			cura -> ls = curb -> ls;
			cura -> rs = curb -> rs;
			delete curb;
			return;
		}
		if (L == R) {
			cura -> sum += curb -> sum;
		}
		merge(cura -> ls, curb -> ls, L, mid);
		merge(cura -> rs, curb -> rs, mid + 1, R);
		pushup(cura);
		delete curb;
	}

	void modify(node* &cur, int L, int R, int pos, int val) {
		if (!cur) cur = newNode(0);
		if (L == R) {
			cur -> sum += val;
			return;
		}
		if (pos <= mid) modify(cur -> ls, L, mid, pos, val);
		else modify(cur -> rs, mid + 1, R, pos, val);
		pushup(cur);
	}

	void split(node* &cur, node* &dst, int L, int R, int l, int r) {
		if (R < l || r < L) return;
		if (!cur) return;
		if (l <= L && R <= r) {
			merge(dst, cur, L, R);
			erase(cur);
			return;
		}
		dst = newNode(0);
		if (l <= mid) split(cur -> ls, dst -> ls, L, mid, l, r);
		if (r > mid) split(cur -> rs, dst -> rs, mid + 1, R, l, r);
		pushup(cur), pushup(dst);
	}

	int query(node* &cur, int L, int R, int l, int r) {
		if (R < l || r < L) return 0;
		if (!cur) return 0;
		if (l <= L && R <= r) return cur -> sum;
		int ans = 0;
		if (l <= mid) ans += query(cur -> ls, L, mid, l, r);
		if (r > mid) ans += query(cur -> rs, mid + 1, R, l, r);
		return ans;
	}

	int kth(node* &cur, int L, int R, int k) {
		if (!cur) return 0;
		if (L == R) return L;
		int lft = cur -> ls ? cur -> ls -> sum : 0;
		if (k <= lft) return kth(cur -> ls, L, mid, k);
		else return kth(cur -> rs, mid + 1, R, k - lft);
	}

	void erase(node* &cur) {
		if (!cur) return;
		erase(cur -> ls);
		erase(cur -> rs);
		delete cur;
		cur = nullptr;
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

	node* split(int l, int r) {
		node* cur = nullptr;
		split(root, cur, 1, MAXP, l, r);
		return cur;
	};

	int query(int l, int r) {
		return query(root, 1, MAXP, l, r);
	};

	int kth(int k) {
		return kth(root, 1, MAXP, k);
	};

	node* operator = (node* other) {
		erase(root);
		return root = other;
	}
	
#undef mid
#undef MAXP
};

SegmentTree T[MAXN];
int cnt = 1;

signed main() {
	//freopen("example.in", "r", stdin);
	read(n), read(m);
	rep (i, 1, n) {
		int tmp;
		read(tmp);
		T[1].modify(i, tmp);
	}
	while (m --> 0) {
		int opt, l, r, k;
		read(opt);
		if (opt == 0) {
			read(l), read(r), read(k);
			T[++cnt] = T[k].split(l, r);
		}
		else if (opt == 1) {
			read(l), read(r);
			T[l].merge(T[r].getRoot());
		}
		else if (opt == 2) {
			read(l), read(r), read(k);
			T[l].modify(k, r);
		}
		else if (opt == 3) {
			read(k), read(l), read(r);
			print(T[k].query(l, r)), putchar(10);
		}
		else if (opt == 4) {
			read(l), read(k);
			if (T[l].getRoot() -> sum < k) puts("-1");
			else print(T[l].kth(k)), putchar(10);
		}
	}
	return 0;
}