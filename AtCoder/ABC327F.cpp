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

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)

const int MAXN = 8e5 + 5;
int mx[MAXN << 2], lazy[MAXN << 2];

void pushup(int x) {
	mx[x] = max(mx[ls(x)], mx[rs(x)]);
}

void pushdown(int x, int L, int R) {
	mx[ls(x)] += lazy[x];
	mx[rs(x)] += lazy[x];
	lazy[x] = 0;
}

void modify(int x, int L, int R, int l, int r, int val) {
	if (l <= L && R <= r) {
		mx[x] += val;
		lazy[x] += val;
		return;
	}
	if (L != R) pushdown(x, L, R);
	if (l <= mid) modify(ls(x), L, mid, l, r, val);
	if (r > mid) modify(rs(x), mid + 1, R, l, r, val);
	pushup(x);
}

int query(int x, int L, int R, int l, int r) {
	if (l <= L && R <= r) return mx[x];
	if (L != R) pushdown(x, L, R);
	int res = 0;
	if (l <= mid) res = max(res, query(ls(x), L, mid, l, r));
	if (r > mid) res = max(res, query(rs(x), mid + 1, R, l, r));
	pushup(x);
	return res;
}

int n, d, w;
struct node {
	int t, x;
	bool operator < (const node &tt) const {
		return t < tt.t;
	}
} ap[MAXN];

queue <node> q;

int main() {
	cin >> n >> d >> w;
	rep (i, 1, n) {
		cin >> ap[i].t >> ap[i].x;
	}
	sort(ap + 1, ap + 1 + n);
	int ans = 0;
	rep (i, 1, n) {
		q.push(ap[i]);
		modify(1, 1, n, max(1, ap[i].x - w + 1), ap[i].x, 1);
		while (q.size() && q.front().t + d <= ap[i].t) {
			node tp = q.front();
			modify(1, 1, n, max(1, tp.x - w + 1), tp.x, -1);
			q.pop();
		}
		ans = max(ans, query(1, 1, n, 1, n));
	}
	while (q.size()) {
		node tp = q.front();
		modify(1, 1, n, max(1, tp.x - w + 1), tp.x, -1);
		q.pop();
		ans = max(ans, query(1, 1, n, 1, n));
	}
	print(ans);
	return 0;
}
