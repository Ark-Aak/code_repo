#include <bits/stdc++.h>

#define int __int128

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

const int MAXN = 1e4 + 5;
const int SQRT = ceil(sqrt(1e9));
const int MOD = 1e9 + 7;
int n, m;
int a[MAXN];
vector <int> p;
bitset <100000> vis;

void init() {
	rep (i, 2, SQRT) {
		if (vis[i]) continue;
		p.emplace_back(i);
		rep (j, 1, SQRT / i) vis[i * j] = 1;
	}
}

int minFactor(int x) {
	for (auto i : p) {
		if (x % i == 0) return i;
	}
	return x;
}

multiset <int> s, t;
map <multiset <int>, int> v;
map <int, multiset <int> > ans;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("factor.in", "r", stdin);
	freopen("factor.out", "w", stdout);
#endif
#endif
	/* freopen("output.txt", "w", stdout); */
	init();
	n = read(), m = read();
	rep (i, 1, n) a[i] = read();
	if (true) {
		rep (i, 1, n) s.insert(a[i]);
		int len = LONG_LONG_MAX;
		int st = 0;
		rep (i, 1, m) {
			int sm = 1;
			t.clear();
			for (auto v : s) sm *= minFactor(v);
			for (auto v : s) t.insert(v / minFactor(v));
			t.insert(sm);
			t.erase(1);
			if (v.count(t)) {
				len = i - v[t];
				st = v[t];
				break;
			}
			v[t] = i, ans[i] = t;
			t.swap(s);
			/* for (auto v : s) { */
			/* 	print(v), putchar(32); */
			/* } */
			/* putchar(10); */
		}
		if (st == 0) {
			multiset <int> Ans = ans[m];
			print(Ans.size()), putchar(10);
			for (auto v : Ans) {
				print(v % MOD), putchar(32);
			}
			return 0;
		}
		m -= st - 1;
		multiset <int> Ans = ans[(m % len == 0 ? len : m % len) + st - 1];
		print(Ans.size()), putchar(10);
		for (auto v : Ans) {
			print(v % MOD), putchar(32);
		}
		return 0;
	}
	return 0;
}
