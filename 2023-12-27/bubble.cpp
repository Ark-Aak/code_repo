#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

using namespace std;

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

const int MAXN = 2e5 + 5;
int n, m, T;
map <int, vector <int> > p;

struct query {
	int l, r, s;
	bool operator < (const query &t) const {
		return r < t.r;
	}
} q[MAXN];

int sum[MAXN << 2], lazy[MAXN << 2];

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)

void pushdown(int x, int L, int R) {
	sum[x] += lazy[x];
	if (L != R) lazy[ls(x)] += lazy[x], lazy[rs(x)] += lazy[x];
	lazy[x] = 0;
}

bool modify(int x, int L, int R, int pos, int val) {
	pushdown(x, L, R);
	if (L > pos) return 0;
	if (R <= pos) {
		lazy[x] += val, pushdown(x, L, R);
		return sum[x] < 0;
	}
	int res = modify(ls(x), L, mid, pos, val) || modify(rs(x), mid + 1, R, pos, val);
	sum[x] = min(sum[ls(x)], sum[rs(x)]);
	return res;
}

int main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("bubble.in", "r", stdin);
	freopen("bubble.out", "w", stdout);
#endif
#endif
	T = read();
	while (T --> 0) {
		memset(sum, 0, sizeof sum);
		memset(lazy, 0, sizeof lazy);
		n = read(), m = read();
		p.clear();
		rep (i, 1, n) p[read()].push_back(i);
		p[0].push_back(1);
		rep (i, 1, m) q[i].l = read(), q[i].r = read(), q[i].s = read();
		sort(q + 1, q + 1 + m);
		map <int, vector <int> >::iterator iter = p.begin();
		bool flg = 0;
		rep (i, 1, m) {
			if (q[i].l > q[i].r) {
				while (next(iter) != p.end() && next(iter) -> first <= q[i].r) {
					iter++;
					for (auto x : iter -> second) modify(1, 1, n, x, 1);
				}
				if (modify(1, 1, n, q[i].s, -1)) {
					puts("NO");
					flg = 1;
					break;
				}
				p[q[i].l].push_back(q[i].s);
			}
		}
		if (!flg) puts("YES");
	}
	return 0;
}
