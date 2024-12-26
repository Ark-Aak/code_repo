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

set <tuple <int, int, int> > s;

set <tuple <int, int, int> >::iterator split(int x) {
    auto iter = s.lower_bound(dk(x, 0, 0));
    if (get<0>(*iter) == x) return iter;
	iter--;
	int l = 0, r = 0, f = 0;
	tie(l, r, f) = *iter;
    s.erase(iter);
	s.insert(dk(l, x - 1, f));
	auto nxt = s.insert(dk(x, r, f)).first;
    return nxt;
}

int fa[MAXN];

int find(int x) {
	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

void insert(int l, int r, int id) {
	auto R = split(r + 1), L = split(l);
	fa[id] = id;
	for (auto iter = L; iter != R; iter++) {
		tuple <int, int, int> val = *iter;
		if (get<2>(val)) fa[find(get<2>(val))] = id;
	}
	while (find(get<2>(*R)) == id) R++;
	while (find(get<2>(*prev(L))) == id) L--;
	int fl = get<0>(*L), fr = get<1>(*prev(R));
	s.erase(L, R);
	s.insert(dk(fl, fr, id));
}

int n, cnt;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("dna.in", "r", stdin);
	freopen("dna.out", "w", stdout);
#endif
#endif
	n = read();
	const int INF = 1e9 + 1;
	s.insert(dk(0, INF, 0));
	rep (i, 1, n) {
		// cerr << "set:" << endl;
		// for (auto [l, r, id] : s) cerr << "a:" << l << " " << r << " " << id << endl;
		int op = read();
		if (op == 1) {
			int l1 = read(), r1 = read(), l2 = read(), r2 = read();
			cnt++;
			insert(l1, r1, cnt);
			insert(l2, r2, cnt);
		}
		else {
			int x = read(), y = read();
			if (x == y) {
				puts("Yes");
				continue;
			}
			int fax = get<2>(*prev(s.lower_bound(dk(x, INF + 1, 0))));
			int fay = get<2>(*prev(s.lower_bound(dk(y, INF + 1, 0))));
			// cerr << "de2:" << fax << " " << fay << endl;
			if (find(fax) == find(fay) && fax) puts("Yes");
			else puts("No");
		}
	}
	return 0;
}
