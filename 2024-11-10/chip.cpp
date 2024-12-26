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
int T, k;
vector <pii> s;
int col[MAXN];

void solve() {
	k = read();
	s.clear();
	rep (i, 1, k) col[i] = 0;
	rep (i, 1, k) {
		int c = read();
		rep (j, 1, c) s.push_back(dl(read(), i));
	}
	sort(s.begin(), s.end());
	// for (auto [x , id] : s) {
		// cout << x << " + " << id << endl;
	// }
	col[s[0].fb]++;
	const int n = s.size();
	int cnt = 1;
	int ans = 2e9;
	for (int l = 0, r = 0; l <= r; l++) {
		while (cnt < k && r < n - 1) {
			r++;
			col[s[r].fb]++;
			if (col[s[r].fb] == 1) cnt++;
		}
		if (cnt == k) ans = min(ans, s[r].ec - s[l].ec);
		col[s[l].fb]--;
		if (col[s[l].fb] == 0) cnt--;
	}
	print(ans), puts("");
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("chip.in", "r", stdin);
	freopen("chip.out", "w", stdout);
#endif
#endif
	T = read();
	while (T --> 0) solve();
	return 0;
}
