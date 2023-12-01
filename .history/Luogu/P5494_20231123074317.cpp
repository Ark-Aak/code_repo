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
		if (!cur) cur = newNode(0);
		if (L == R) cur -> sum += val, cur;
		if (pos <= mid) cur -> ls = modify(cur -> ls, L, mid, pos, val);
		else cur -> rs = modify(cur -> rs, mid + 1, R, pos, val);
		pushup(cur);
	}

	void printTree(int step, node* x, int L, int R) {
		if (!x) return;
		cerr << "step = " << step << endl;
		cerr << "L = " << L << " R = " << R << endl;
		cerr << "sum = " << x -> sum << endl;
		cerr << endl;
		printTree(step + 1, x -> ls, L, mid);
		printTree(step + 1, x -> rs, mid + 1, R);
	}

	node* split(node* cur, 

public:

	SegmentTree() {
		root = newNode(0);
	}
	
	void merge(node* cur) {
		root = merge(root, cur, 1, MAXP);
	};

	void modify(int pos, int val) {
		root = modify(root, 1, 1e5, pos, val);
	};

	node* getRoot() {
		return root;
	};

	void print() {
		printTree(1, root, 1, MAXP);
	}
	
#undef mid
#undef MAXP
};

SegmentTree T[MAXN];

signed main() {
	read(n), read(m);

	return 0;
}
