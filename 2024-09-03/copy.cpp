#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
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
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 2e5 + 5;
int k, m;
string s;
int q;
list <int> out[MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("copy.in", "r", stdin);
	freopen("copy.out" , "w", stdout);
#endif
#endif
	ios::sync_with_stdio(0);
	cin >> k >> m;
	cin >> s;
	cin >> q;
	while (q --> 0) {
		int l, r, x;
		cin >> l >> r >> x;
		r--;
		string res = s.substr(l, r - l + 1);
		s.insert(x, res);
		s = s.substr(0, m);
	}
	rep (i, 0, k - 1) putchar(s[i]);
	puts("");
	return 0;
}
