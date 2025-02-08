#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
#endif
#include <bits/stdc++.h>

#define int ll

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
const int MOD = 1e9 + 7;
int id, T;
int n, m;
int l[MAXN], r[MAXN], c[MAXN];

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

namespace subtask1 {

	int ch[20], ans;

	void dfs(int step) {
		if (step > n) {
			rep (i, 1, m) {
				int buc[3] = { 0 };
				rep (j, l[i], r[i]) {
					buc[ch[j]] = 1;
				}
				int cnt = buc[0] + buc[1] + buc[2];
				if (cnt != c[i]) return;
			}
			ans++;
			ans %= MOD;
			return;
		}
		ch[step] = 0;
		dfs(step + 1);
		ch[step] = 1;
		dfs(step + 1);
		ch[step] = 2;
		dfs(step + 1);
	}
	
	void solve() {
		ans = 0;
		dfs(1);
		print(ans), puts("");
	}

} // namespace subtask1

namespace subtask2 {
	
	void solve() {
		int ans = 1;
		int sumlen = 0;
		rep (i, 1, m) sumlen += r[i] - l[i] +1;
		ans = qpow(3, n - sumlen);
		rep (i, 1, m) {
			const int len = r[i] - l[i] + 1;
			int pl = 0;
			if (c[i] == 3) pl = (qpow(3, len) - 3 * qpow(2, len) % MOD + MOD + 3) % MOD;
			else if (c[i] == 2) pl = (3 * qpow(2, len) - 6 + MOD) % MOD;
			else pl = 3;
			if (len < c[i]) pl = 0;
			ans *= pl;
			ans %= MOD;
		}
		print(ans), puts("");
	}

} // namespace subtask2

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("stars.in", "r", stdin);
	freopen("stars.out", "w", stdout);
#endif
#endif
	id = read(), T = read();
	while (T --> 0) {
		n = read(), m = read();
		if (m == 0) {
			print(qpow(3, n)), puts("");
			continue;
		}
		rep (i, 1, m) l[i] = read(), r[i] = read(), c[i] = read();
		if (id >= 5 && id <= 6) subtask2::solve();
		else subtask1::solve();
	}
	return 0;
}
