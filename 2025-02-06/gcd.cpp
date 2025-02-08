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

const int MAXN = 15;
int n, a[MAXN];
int p[MAXN], flg[MAXN], b[MAXN];
vector <vector <int> > aa[MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("gcd.in", "r", stdin);
	freopen("gcd.out", "w", stdout);
#endif
#endif
	n = read();
	rep (i, 1, n) a[i] = read();
	rep (i, 1, n) p[i] = i;
	do {
		memset(flg, 0, sizeof flg);
		int cnt = 0, res = 1;
		vector <int> rr;
		rep (i, 1, n) {
			if (!flg[i]) {
				int cur = i;
				++cnt;
				int minn = 1e9;
				do {
					flg[cur] = 1;
					minn = min(minn, a[p[cur]]);
					cur = p[cur];
				} while (!flg[cur]);
				res *= minn;
				rr.push_back(minn);
			}
		}
		aa[cnt].push_back(rr);
		b[cnt] += res;
	} while (next_permutation(p + 1, p + 1 + n));
	int ans = b[1];
	rep (i, 2, n) ans = __gcd(ans, b[i]);
	ans %= 998244353;
	print(ans), puts("");
	return 0;
}
