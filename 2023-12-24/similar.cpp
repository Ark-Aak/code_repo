#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

using namespace std;

#define int ll

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

const int MAXN = 1e5 + 10, MAXM = MAXN << 5;
int a[MAXN], pw[MAXN];

struct node {
	node *ls, *rs;
	int sum, h;

	node() {ls = nullptr, rs = nullptr, sum = 0, h = 0;}
};

node *root[MAXN];
node *null;

#define mid ((L + R) >> 1)
const int base = 147744151, MOD = 1e9 + 7;

node* newNode() {
	node* res = new node();
	res -> ls = null, res -> rs = null;
	return res;
}

node* build(int L, int R) {
	node* rt = newNode();
	if (L < R) {
		rt -> ls = build(L, mid);
		rt -> rs = build(mid + 1, R);
	}
	return rt;
}

node* update(node* cur, int L, int R, int val, int f) {
	node* rt = newNode();
	rt -> ls = cur -> ls, rt -> rs = cur -> rs;
	rt -> sum = (cur -> sum + 1 * f);
	rt -> h = (cur -> h + pw[val] * f + MOD) % MOD;
	if (L < R) {
		if (val <= mid) rt -> ls = update(cur -> ls, L, mid, val, f);
		else rt -> rs = update(cur -> rs, mid + 1, R, val, f);
	}
	return rt;
}

int kth(node* u, node* v, int L, int R, int k) {
	if (L == R) return L;
	int x = (v -> ls -> sum) - (u -> ls -> sum);
	if (x >= k) return kth(u -> ls, v -> ls, L, mid, k);
	else return kth(u -> rs, v -> rs, mid + 1, R, k - x);
}

int rnk(node* u, node* v, int L, int R, int val) {
	if (L == R) return 1;
	if (val <= mid) return rnk(u -> ls, v -> ls, L, mid, val);
	else return v -> ls -> sum - u -> ls -> sum + rnk(u -> rs, v -> rs, mid + 1, R, val);
}

int h(node* l, node* r) {
	return (r -> h - l -> h + MOD) % MOD;
}

int query(node* ul, node* ur, node* vl, node* vr, int L, int R) {
	if (L == R) return h(ul, ur) == h(vl, vr) ? 0 : L;
	if (h(ul -> ls, ur -> ls) == h(vl -> ls, vr -> ls))
		return query(ul -> rs, ur -> rs, vl -> rs, vr -> rs, mid + 1, R);
	else return query(ul -> ls, ur -> ls, vl -> ls, vr -> ls, L, mid);
}

int get(node* u, node* v, int L, int R, int pos) {
	if (L == R) return v -> sum - u -> sum;
	if (pos <= mid) return get(u -> ls, v -> ls, L, mid, pos);
	else return get(u -> rs, v -> rs, mid + 1, R, pos);
}

int n, q;

int qpow(int a, int b) {
	int res = 1;
	for (; b; b >>= 1) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
	}
	return res;
}

int inv(int a) {
	return qpow(a, MOD - 2);
}

const int N = 1e5;

int Get(int l, int r, int pos) {
	return get(root[l - 1], root[r], 1, N, pos);
}

signed main() {
	null = new node();
	null -> ls = null, null -> rs = null;
	n = read(), q = read();
	rep (i, 1, n) a[i] = read();
	pw[0] = 1;
	rep (i, 1, N) pw[i] = pw[i - 1] * base % MOD;
	root[0] = build(1, N);
	rep (i, 1, n) root[i] = update(root[i - 1], 1, N, a[i], 1);
	rep (i, 1, q) {
		int l = read(), r = read(), L = read(), R = read();
		int diff = query(root[l - 1], root[r], root[L - 1], root[R], 1, N);
		if (!diff) {
			puts("YES");
			continue;
		}
		int sl = Get(l, r, diff), sr = Get(L, R, diff);
		if (sl > sr) {
			int rk = rnk(root[l - 1], root[r], 1, N, diff + 1) - 1;
			int nx = kth(root[L - 1], root[R], 1, N, rk);
			if (Get(1, L - 1, nx) == Get(1, R, nx)) root[N + 2] = update(root[L - 1], 1, N, nx, -1), L = N + 3;
			root[N + 3] = update(root[R], 1, N, nx, -1);
			R = N + 3;
			if (Get(1, l - 1, diff) == Get(1, r, diff)) root[N + 4] = update(root[l - 1], 1, N, diff, -1), L = N + 5;
			root[N + 5] = update(root[r], 1, N, diff, -1);
			r = N + 5;
			if (h(root[L - 1], root[R]) != h(root[l - 1], root[r])) puts("NO");
			else puts("YES");
		}
		else {
			int rk = rnk(root[L - 1], root[R], 1, N, diff + 1) - 1;
			int nx = kth(root[l - 1], root[r], 1, N, rk);
			if (Get(1, L - 1, diff) == Get(1, R, diff)) root[N + 2] = update(root[L - 1], 1, N, diff, -1), L = N + 3;
			root[N + 3] = update(root[R], 1, N, diff, -1);
			R = N + 3;
			if (Get(1, l - 1, nx) == Get(1, r, nx)) root[N + 4] = update(root[l - 1], 1, N, nx, -1), L = N + 5;
			root[N + 5] = update(root[r], 1, N, nx, -1);
			r = N + 5;
			if (h(root[L - 1], root[R]) != h(root[l - 1], root[r])) puts("NO");
			else puts("YES");
		}
	}
	return 0;
}
