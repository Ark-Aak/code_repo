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

const int MAXN = 20005;
pii bd[MAXN], gd[MAXN];
int n, m, a, b;

signed main() {
	cin >> n >> m >> a >> b;
	rep (i, 0, m - 1) cin >> bd[i].first >> bd[i].second;
	int gd_cnt = 0;
	if (m == 0) gd[gd_cnt++] = { 1, n };
	else {
		if (bd[0].first > 1) {
			gd[gd_cnt++] = {1, bd[0].first - 1};
		}
		rep (i, 0, m - 2) {
			ll s = bd[i].second + 1;
			ll e = bd[i + 1].first - 1;
			if (s <= e) {
				gd[gd_cnt++] = {s, e};
			}
		}
		if (bd[m - 1].second < n) {
			gd[gd_cnt++] = {bd[m - 1].second + 1, n};
		}
	}
	ll cl = 1, ch = 1;
	rep (i, 0, gd_cnt - 1) {
		ll gs = gd[i].first, ge = gd[i].second;
		ll nl = max(gs, cl + a);
		ll nh = min(ge, ch + b);
		if (nl > nh) continue;
		bool upd = 1;
		while (upd) {
			upd = 0;
			ll tl = max(gs, nl + a);
			ll th = min(ge, nh + b);
			if (tl > th) break;
			if (tl > nl || th > nh) {
				nl = tl;
				nh = th;
				upd = 1;
			}
		}
		cl = nl;
		ch = nh;
		if (ch >= n) {
			puts("Yes");
			return 0;
		}
	}
	if (ch >= n) puts("Yes");
	else puts("No");
	return 0;
}
