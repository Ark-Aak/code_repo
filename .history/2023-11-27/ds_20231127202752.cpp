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

	node(int a, int b, int c) {
		mx = a;
		mn = b;
		sum = c;
	}

	node(int x = 0) {
		*this = node(max(0ll, x), min(0ll, x), x);
	}

	node operator + (const node &b) const {
		return node(max(mx, sum + b.mx), min(mn, sum + b.mn), sum + b.sum);
	}
} sum[MAXN << 2];

#define mid ((L + R) >> 1)
#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)

void modify(int x, int L, int R, int pos, int val) {
	if (L == R) {
		return (void) (sum[x] = node(sum[x]. sum + val));
	}

}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("ds.in", "r", stdin);
	freopen("ds.out", "w", stdout);
#endif
#endif
	read(n), read(m);
	rep (i, 1, n) read(t[i]);

	return 0;
}
