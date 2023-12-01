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
#define MAXP 100000

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

	void pushup(node* cur) {
		if (!cur) return;
		cur -> sum = (cur -> ls ? cur -> ls -> sum : 0) + (cur -> rs ? cur -> rs -> sum : 0);
	}

	void merge(node* cura, node* curb, int L, int R) {
		if (!cura) return;
		if (!curb) return;
		if (L == R) {
			cura -> sum += curb -> sum;
		}
		merge(cura -> ls, curb -> ls, L, mid);
		merge(cura -> rs, curb -> rs, mid + 1, R);
		pushup(cura);
	}

	void modify(node* cur, int L, int R, int pos, int val) {
		if (!cur) cur = newNode(0);
		if (L == R) cur -> sum += val, cur;
		if (pos <= mid) modify(cur -> ls, L, mid, pos, val);
		else modify(cur -> rs, mid + 1, R, pos, val);
		pushup(cur);
	}

	void split(node* cur, node* dst, int L, int R, int l, int r) {
		if (R < l || r < L) return;
		if (!cur) return;
		if (l <= L && R <= r) {
			merge(dst, cur, L, R);
			cur = nullptr;
			return;
		}
		dst = newNode(0);
		if (l <= mid) split(cur -> ls, dst -> ls, L, mid, l, r);
		if (r > mid) split(cur -> rs, dst -> rs, mid + 1, R, l, r);
		pushup(cur), pushup(dst);
	}

	int query(node* cur, int L, int R, int l, int r) {
		if (R < l || r < L) return 0;
		if (!cur) return 0;
		if (l <= L && R <= r) return cur -> sum;
		int ans = 0;
		if (l <= mid) ans += query(cur -> ls, L, mid, l, r);
		if (r > mid) ans += query(cur -> rs, mid + 1, R, l, r);
		return ans;
	}

	int kth(node* cur, int L, int R, int k) {
		if (!cur) return 0;
		if (L == R) return L;
		int lft = cur -> ls ? cur -> ls -> sum : 0;
		if (k <= lft) return kth(cur -> ls, L, mid, k);
		else return kth(cur -> rs, mid + 1, R, k - lft);
	}

public:

	SegmentTree() {
		root = newNode(0);
	}
	
	void merge(node* cur) {
		merge(root, cur, 1, MAXP);
	};

	void modify(int pos, int val) {
		modify(root, 1, 1e5, pos, val);
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
	
#undef mid
#undef MAXP
};

SegmentTree T[MAXN];

signed main() {
	read(n), read(m);

	return 0;
}
