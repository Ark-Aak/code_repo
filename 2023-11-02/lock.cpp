#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)
#define genshin_impact 1e5 + 5

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

const int MAXN = genshin_impact;
string s;
int Q;

int sum[MAXN << 2], a[MAXN];
int n, m;

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)

void pushup(int x) {
	sum[x] = max(sum[ls(x)], sum[rs(x)]);
}

void build(int x, int L, int R) {
	if (L == R) return (void) (sum[x] = a[L]);
	build(ls(x), L, mid);
	build(rs(x), mid + 1, R);
	pushup(x);
}

void modify(int x, int L, int R, int p, int val) {
	if (L == p && R == p) return (void) (sum[x] = val);
	if (p <= mid) modify(ls(x), L, mid, p, val);
	if (p > mid) modify(rs(x), mid + 1, R, p, val);
	pushup(x);
}

int query(int x, int L, int R, int l, int r) {
	if (l <= L && R <= r) return sum[x];
	int res = 0;
	if (l <= mid) res = max(res, query(ls(x), L, mid, l, r));
	if (r > mid) res = max(res, query(rs(x), mid + 1, R, l, r));
	pushup(x);
	return res;
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("lock.in", "r", stdin);
	freopen("lock.out", "w", stdout);
#endif
#endif
	cin >> s;
	cin >> Q;
	int n = s.size(), ans = 0;
	s = ' ' + s;
	int mx = s[1];
	rep (i, 2, n) {
		mx = max(mx, (int) s[i]);
		ans += mx - s[i];
	}
	print(ans), putchar(10);
	while (Q --> 0) {
		int i;
		char c;
		cin >> i >> c;
		s[i] = c;
		int mx = s[1], ans = 0;
		rep (i, 2, n) {
			mx = max(mx, (int) s[i]);
			ans += mx - s[i];
		}
		print(ans), putchar(10);
	}
	return 0;
}
