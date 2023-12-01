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

#define int ll

const int MAXN = 2e5 + 5;
ll n, m, a[MAXN], t[MAXN];

struct node {
	int mx, mn, sum;

	node() {}

	node(int x) {
		mx = max(0ll, x);
		mn = min(0ll, x);
		sum = x;
	}

	node operator + (const node &b) const {
		node tmp = node(0);
		tmp.mx = max(mx, sum + b.mx);
		tmp.mn = min(mn, sum + b.mn);
		tmp.sum = sum + b.sum;
		return tmp;
	}
} sum[MAXN << 2];

#define mid ((L + R) >> 1)
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)

void pushup(int x) {
	sum[x] = sum[ls(x)] + sum[rs(x)];
}

void modify(int x, int L, int R, int pos, int val) {
	if (L == R) {
		return (void) (sum[x].sum += val);
	}
	if (pos <= mid) modify(ls(x), L, mid, pos, val);
	else modify(rs(x), mid + 1, R, pos, val);
	pushup(x);
}

int query(int x, int L, int R, int pos, node r) {
	if (L == R) {
		if (sum[x].sum <= 0) {
			if (r.mx > pos) return pos + r.mx - r.mn;
			else return r.mx - r.mn;
		}
		else {
			if (r.mn < -pos) return r.sum - r.mn;
			else return pos + r.sum - r.mx;
		}
	}
	else {
		node nw = r + sum[x];
		return nw.mx - nw.mn <= pos ? query(ls(x), L, mid, pos, nw) : query(rs(x), mid + 1, R, pos, r);
	}
}

vector <pair <int, int> > f[MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("ds.in", "r", stdin);
	freopen("ds.out", "w", stdout);
#endif
#endif
	cin >> n >> m;
	rep (i, 1, n) cin >> t[i];
	rep (i, 1, m) {
		char op;
		int l, r, v;
		cin >> op >> l >> r >> v;
		if (op == '-') v = -v;
		f[l].emplace_back(make_pair(i + 1, v));
		f[r + 1].emplace_back(make_pair(i + 1, -v));
	}
	rep (i, 1, n) {
		cout << query(1, 1, n, t[i], node(0)) << " ";
		for (auto x : f[i]) {
			modify(1, 1, m, x.first, x.second);
		}
	}
	return 0;
}
