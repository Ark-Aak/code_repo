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

const int MAXN = 5e5 + 5;
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
		tmp.mx = max(0ll, tmp.mx);
		tmp.mn = min(0ll, tmp.mn);
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
		return (void) (sum[x] = node(sum[x].sum + val));
	}
	if (pos <= mid) modify(ls(x), L, mid, pos, val);
	else modify(rs(x), mid + 1, R, pos, val);
	pushup(x);
}

int query(int x, int L, int R, int pos, node r) {
	if (L == R) {
		if (sum[x].sum <= 0) {
			if (r.mx > pos) return pos + r.sum - r.mx;
			else return r.sum - r.mn;
		}
		else {
			if (r.mn < -pos) return r.sum - r.mn;
			else return pos + r.sum - r.mx;
		}
	}
	else {
		node nw = sum[rs(x)] + r;
		return nw.mx - nw.mn <= pos ? query(ls(x), L, mid, pos, nw) : query(rs(x), mid + 1, R, pos, r);
	}
}

vector <pair <int, int> > f[MAXN];

#undef int

std::vector<int> distribute_candies(
  	std::vector<int> c, std::vector<int> l, 
  	std::vector<int> r, std::vector<int> v) {
	n = c.size(); m = l.size();
	rep (i, 0, n - 1) t[i] = c[i];
	rep (i, 0, m - 1) {
		f[l[i]].emplace_back(make_pair(i + 1, v[i]));
		f[r[i] + 1].emplace_back(make_pair(i + 1, -v[i]));
	}
	vector <int> res;
	rep (i, 0, n - 1) {
		for (auto x : f[i]) {
			modify(1, 0, m, x.first, x.second);
		}
		res.emplace_back(query(1, 0, m, t[i], 0));
	}
	return res;
}