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

const int MAXN = 2005;
int n, m, a[MAXN], b[MAXN], c[MAXN], d[MAXN];
int suma = 0, sumb = 0;

namespace subtask1 {

	int qa[MAXN], qb[MAXN], ca, cb;
	int dp[MAXN][MAXN];

	void solve() {
		rep (i, 1, n) rep (j, 1, a[i]) qa[++ca] = c[i];
		rep (i, 1, m) rep (j, 1, b[i]) qb[++cb] = d[i];
		rep (i, 1, ca) {
			rep (j, 1, cb) {
				dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1] + (qa[i] == qb[j]));
			}
		}
		print(dp[ca][cb]), puts("");
	}

} // namespace subtask1

namespace wrong_solution {

	vector <int> pos;
	vector <tuple <int, int, int> > qa, qb;
	vector <pii> ca, cb;
	int dp[MAXN][MAXN];

	void solve() {
		int sum = 0;
		rep (i, 1, n) sum += a[i], pos.emplace_back(sum), a[i] += a[i - 1];
		sum = 0;
		rep (i, 1, m) sum += b[i], pos.emplace_back(sum), b[i] += b[i - 1];
		sort(pos.begin(), pos.end());
		pos.erase(unique(pos.begin(), pos.end()), pos.end());
		rep (i, 1, n) qa.emplace_back(a[i - 1] + 1, a[i], c[i]);
		rep (i, 1, m) qb.emplace_back(b[i - 1] + 1, b[i], d[i]);
		for (auto p : pos) {
			sort(qa.begin(), qa.end());
			for (auto &[l, r, v] : qa) {
				if (l <= p && p < r) {
					qa.emplace_back(p + 1, r, v);
					r = p;
					break;
				}
			}
		}
		for (auto p : pos) {
			sort(qb.begin(), qb.end());
			for (auto &[l, r, v] : qb) {
				if (l <= p && p < r) {
					qb.emplace_back(p + 1, r, v);
					r = p;
					break;
				}
			}
		}
		sort(qa.begin(), qa.end());
		sort(qb.begin(), qb.end());
		for (auto [l, r, v] : qa) ca.emplace_back(v, r - l + 1);
		for (auto [l, r, v] : qb) cb.emplace_back(v, r - l + 1);
		rep (i, 1, qa.size()) {
			rep (j, 1, qb.size()) {
				dp[i][j] = max(max(dp[i - 1][j], dp[i][j - 1]),
							   dp[i - 1][j - 1] + ca[i - 1].fb * (ca[i - 1].ec == cb[j - 1].ec));
			}
		}
		print(dp[qa.size()][qb.size()]), puts("");
	}
} // namespace wrong_solution

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("lcs.in", "r", stdin);
	freopen("lcs.out", "w", stdout);
#endif
#endif
	n = read(), m = read();
	rep (i, 1, n) c[i] = read(), suma += (a[i] = read());
	rep (i, 1, m) d[i] = read(), sumb += (b[i] = read());
	if (suma <= 1000 && sumb <= 1000) return subtask1::solve(), 0;
	else return wrong_solution::solve(), 0;
	return 0;
}
