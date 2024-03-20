#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

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

vector <int> H;

void init() {
	sort(H.begin(), H.end());
	H.erase(unique(H.begin(), H.end()), H.end());
}

int find(int x) {
	return lower_bound(H.begin(), H.end(), x) - H.begin() + 1;
}

const int MAXN = 2e5 + 5, MAXM = MAXN << 5;
int n, m, cnt;
int a[MAXN];

struct node {
	node *ls, *rs;
	int sum;

	node() {ls = nullptr, rs = nullptr, sum = 0;}
};

node *root[MAXN];

#define mid ((L + R) >> 1)

node* build(int L, int R) {
	node* rt = new node();
	if (L < R) {
		rt -> ls = build(L, mid);
		rt -> rs = build(mid + 1, R);
	}
	return rt;
}

node* update(node* cur, int L, int R, int val) {
	node* rt = new node();
	rt -> ls = cur -> ls, rt -> rs = cur -> rs;
	rt -> sum = cur -> sum + 1;
	if (L < R) {
		if (val <= mid) rt -> ls = update(cur -> ls, L, mid, val);
		else rt -> rs = update(cur -> rs, mid + 1, R, val);
	}
	return rt;
}

int query(node* u, node* v, int L, int R, int k) {
	if (L == R) return L;
	int x = (v -> ls -> sum) - (u -> ls -> sum);
	if (x >= k) return query(u -> ls, v -> ls, L, mid, k);
	else return query(u -> rs, v -> rs, mid + 1, R, k - x);
}

int main() {
	read(n), read(m);
	rep (i, 1, n) {
		read(a[i]);
		H.emplace_back(a[i]);
	}
	init();
	rep (i, 1, n) a[i] = find(a[i]);
	root[0] = build(1, H.size());
	rep (i, 1, n) root[i] = update(root[i - 1], 1, H.size(), a[i]);
	rep (i, 1, m) {
		int l, r, k;
		read(l), read(r), read(k);
		print(H[query(root[l - 1], root[r], 1, H.size(), k) - 1]), putchar(10);
	}
	return 0;
}
