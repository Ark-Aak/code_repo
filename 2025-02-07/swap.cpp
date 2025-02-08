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
int n, m, k;
string s, t;
int a[MAXN], b[MAXN];
int ansl = 0, ansr = 0, ans = 0;

void update(int a, int l, int r) {
	if (a > ans) {
		ansl = l, ansr = r;
		ans = a;
	}
	else if (a == ans) {
		if (ansr - ansl < r - l) {
			ansl = l, ansr = r;
		}
		else if (ansr - ansl == r - l && l < ansl) {
			ansl = l, ansr = r;
		}
	}
}

namespace subtask1 {

void solve() {
	rep (i, 1, n - m + 1) {
		int oc = 0;
		rep (i, 1, k) oc += s[i] == t[i];
		rep (j, i, n) {
			oc -= s[a[j]] == t[a[j]];
			oc -= s[b[j]] == t[b[j]];
			swap(s[a[j]], s[b[j]]);
			oc += s[a[j]] == t[a[j]];
			oc += s[b[j]] == t[b[j]];
			if (j - i + 1 >= m) update(oc, i, j);
		}
		_rep (j, n, i) swap(s[a[j]], s[b[j]]);
		if (clock() * 1.0 / CLOCKS_PER_SEC > 1.95) break;
	}
	print(ans), puts("");
	print(ansl), putchar(32), print(ansr), puts("");
}

} // namespace subtask1

namespace subtask2 {

	int f[2][1 << 20], g[2][1 << 20];
	
	inline int get(int x, int y) {
		return x >> (y - 1) & 1;
	}

	inline int set(int x, int y, int v) {
		return x - (get(x, y) << (y - 1)) + (v << (y - 1));
	}

	inline int swap(int x, int a, int b) {
		int x1 = get(x, a), x2 = get(x, b);
		return set(set(x, a, x2), b, x1);
	}

	inline int trans(string &s, int k) {
		int res = 0;
		_rep (i, k, 1) res = (res << 1) | (s[i] ^ 48);
		return res;
	}

	void solve() {
		const int st = trans(s, k);
		const int target = trans(t, k);
		g[0][st] = 1;
		vector <int> p[2];
		p[1].emplace_back(st);
		rep (i, 1, n) {
			const int op1 = i & 1, op2 = !op1;
			rep (j, 0, (1 << k) - 1) f[op1][j] = g[op1][j] = 0;
			p[op2].clear();
			g[op1][swap(st, a[i], b[i])] = 1;
			p[op2].emplace_back(swap(st, a[i], b[i]));
			f[op1][swap(st, a[i], b[i])] = 1;
			int cnt = 0;
			//rep (j, 0, (1 << k) - 1) {
			for (auto j : p[op1]) {
				//if (!g[op2][j]) continue;
				//++cnt;
				const int nxt = swap(j, a[i], b[i]);
				if (!g[op1][nxt]) p[op2].emplace_back(nxt);
				g[op1][nxt] = 1;
				f[op1][nxt] = max(f[op1][nxt], f[op2][j] + 1);
			}
			//rep (j, 0, (1 << k) - 1) {
			for (auto j : p[op2]) {
				//if (!g[op1][j]) continue;
				update(k - __builtin_popcount(j ^ target), i - f[op1][j] + 1, i);
			}
		}
		print(ans), puts("");
		print(ansl), putchar(32), print(ansr), puts("");
	}

} // namespace subtask2

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("swap.in", "r", stdin);
	freopen("swap.out", "w", stdout);
#endif
#endif
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> m >> k;
	cin >> s >> t;
	s = ' ' + s;
	t = ' ' + t;
	rep (i, 1, n) cin >> a[i] >> b[i];
	if (k <= 8) subtask2::solve();
	else subtask1::solve();
	return 0;
}
