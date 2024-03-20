#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

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

const int MAXN = 10, MOD = 1e9 + 7;
int n, a[MAXN], ch[MAXN], ta[MAXN], ord[MAXN];

namespace BIT {
	int c[MAXN];

	void add(int x, int v) {
		if (!x) return;
		for (int o = x; o < MAXN; o += (o & -o))
			c[o] += v;
	}

	int query(int x, int res = 0) {
		for (int o = x; o; o -= (o & -o))
			res += c[o];
		return res;
	}

	void clear() { memset(c, 0, sizeof c); }
} // namespace BIT

inline void inc(int &x, const int &y) { x = (x + y >= MOD ? x + y - MOD : x + y); }

int check() {
	BIT::clear();
	int res = 0;
	rep (i, 1, n) {
		inc(res, BIT::query(n) - BIT::query(ta[i]));
		BIT::add(ta[i], 1);
	}
	return res;
}

int ans = 0;

void dfs(int step) {
	if (step > n) {
		vector <int> s;
		s.push_back(0);
		rep (i, 1, n) if (ch[i])
			s.push_back(i);
		int N = s.size() - 1;
		if (!N) return;
		rep (i, 1, N) ord[i] = i;
		do {
			rep (i, 1, n) ta[i] = a[i];
			rep (i, 1, N) {
				ta[s[i]] = a[s[ord[i]]];
			}
			inc(ans, check());
			/* rep (i, 1, n) cout << ta[i] << " "; */
			/* cout << check(); */
			/* cout << endl; */
		} while (next_permutation(ord + 1, ord + 1 + N));
		return;
	}
	ch[step] = 1;
	dfs(step + 1);
	ch[step] = 0;
	dfs(step + 1);
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("subivs.in", "r", stdin);
	freopen("subivs.out", "w", stdout);
#endif
#endif
	/* BIT::add(2, 1); */
	/* BIT::add(3, 1); */
	/* cout << BIT::query(2); */
	n = read();
	rep (i, 1, n) a[i] = read();
	dfs(1);
	rep (i, 1, n) ta[i] = a[i];
	inc(ans, check());
	print(ans);
	return 0;
}
