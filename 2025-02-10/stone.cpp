#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)
#define de(val) cerr << #val << " = " << (val) << endl

using namespace std;

typedef long long ll;
typedef __int128 i128;
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
	if (x < 0) putchar('-'), x = -x;
	static int sta[40];
	int top = 0;
	do sta[top++] = x % 10, x /= 10; while (x);
	while (top) putchar(sta[--top] + 48);
}

const int MAXN = 1e6 + 5;
const int V = 1e6;
const int INF = 1e8;
multiset <int> v1[MAXN], v2[MAXN];

namespace seg {

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)
	
	int maxl[MAXN << 2], minr[MAXN << 2], ans[MAXN << 2];

	void build(int x, int L, int R) {
		maxl[x] = -INF, minr[x] = INF, ans[x] = INF;
		if (L == R) return;
		build(ls(x), L, mid);
		build(rs(x), mid + 1, R);
	}

	void pushup(int x) {
		maxl[x] = max(maxl[ls(x)], maxl[rs(x)]);
		minr[x] = min(minr[ls(x)], minr[rs(x)]);
		ans[x] = min(min(ans[ls(x)], ans[rs(x)]), minr[rs(x)] - maxl[ls(x)] + 1);
	}

	void change(int x, int L, int R, int p) {
		if (L == R) {
			if (v1[L].empty()) minr[x] = INF;
			else minr[x] = *v1[L].begin();
			if (v2[L].empty()) maxl[x] = -INF;
			else maxl[x] = *v2[L].rbegin();
			return;
		}
		if (p <= mid) change(ls(x), L, mid, p);
		else change(rs(x), mid + 1, R, p);
		pushup(x);
	}
	
} // namespace seg

int q;
multiset <pii> p1, p2;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("stone.in", "r", stdin);
	freopen("stone.out", "w", stdout);
#endif
#endif
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> q;
	seg::build(1, 1, V);
	while (q --> 0) {
		char op;
		int x, y;
		cin >> op >> x >> y;
		y--;
		if (op == 'A') {
			v1[x].insert(y);
			v2[y].insert(x);
			p1.insert({ -x, y });
			p2.insert({ y, -x });
		}
		else {
			v1[x].erase(v1[x].find(y));
			v2[y].erase(v2[y].find(x));
			p1.erase(p1.find({ -x, y }));
			p2.erase(p2.find({ y, -x }));
		}
		seg::change(1, 1, V, x);
		seg::change(1, 1, V, y);
		if (seg::ans[1] <= V) cout << seg::ans[1] << '\n';
		else {
			int maxl = (*p1.begin()).fb;
			int minr = -(*p2.begin()).fb;
			cout << maxl - minr + 1 << '\n';
		}
	}
	return 0;
}
