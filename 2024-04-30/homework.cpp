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
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int BASE = 31;
const int MOD = 998244353;
const int MOD2 = 1e9 + 7;
const int MAXN = 1e3 + 5;

int n, pw[MAXN];
string s;
map <tuple <int, int, int>, int> mp;
map <int, int> bk;

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("homework.in", "r", stdin);
	freopen("homework.out", "w", stdout);
#endif
#endif
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> n >> s;
	s = ' ' + s;
	rep (l, 1, n) {
		int val = 0, h1 = 0, h2 = 0;
		rep (r, l, n) {
			val += s[r] - 'c';
			h1 = (1ll * h1 * BASE + s[r]) % MOD;
			h2 = (1ll * h2 * BASE + s[r]) % MOD2;
			bk[val] = (bk[val] + 1) % MOD;
			mp[dk(val, h1, h2)] = (mp[dk(val, h1, h2)] + 1) % MOD;
		}
	}
	int ans = 0;
	rep (l, 1, n) {
		int val = 0, h1 = 0, h2 = 0;
		rep (r, l, n) {
			val += s[r] - 'c';
			h1 = (1ll * h1 * BASE + s[r]) % MOD;
			h2 = (1ll * h2 * BASE + s[r]) % MOD2;
			ans = (1ll * ans + bk[val] - mp[dk(val, h1, h2)] + MOD) % MOD;
		}
	}
	print(ans), puts("");
	return 0;
}
