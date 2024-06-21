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
#define int ll

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

#define id(x) ((x) - 'a')
int n, m, ans = 1e18, w[30], ch[30];
string s, t;

struct BIT {
	int c[50];
	void add(int x, int v) { for (; x <= n; x += x & -x) c[x] += v; }
	int query(int x, int res = 0) { for (; x; x -= x & -x) res += c[x]; return res; }
} bit[26];

bool check() {
	string h = " ";
	rep (i, 1, n) if (!ch[i]) h += s[i];
	return h == t;
}

void dfs(int step) {
	if (check()) {
		int W = 0;
		rep (i, 1, n) if (ch[i]) W += w[i];
		ans = min(ans, W);
		return;
	}
	if (step > n) return;
	if (bit[id(s[step])].query(step - 1) == 0 ||
		bit[id(s[step])].query(n) - bit[id(s[step])].query(step) == 0
	) {
		ch[step] = 1;
		bit[id(s[step])].add(step, -1);
		dfs(step + 1);
		bit[id(s[step])].add(step, 1);
	}
	ch[step] = 0;
	dfs(step + 1);
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("edit.in", "r", stdin);
	freopen("edit.out", "w", stdout);
#endif
#endif
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> s >> t;
	n = s.size(), m = t.size();
	s = ' ' + s;
	t = ' ' + t;
	rep (i, 1, n) w[i] = read();
	rep (i, 1, n) bit[id(s[i])].add(i, 1);
	dfs(1);
	print(ans == 1e18 ? -1 : ans);
	return 0;
}
