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

int T;

int ch[65];

void solve() {
	int n = read(), m = read();
	int p = 0, ans = 0;
	_rep (i, 62, 0) {
		ch[i] = (n >> i) & 1;
	}
	_rep (i, 62, 0) {
		p <<= 1;
		p |= ch[i];
		// if (i == 0) cout << "???:" << p << " " << ch[i] << endl;
		if (p == 0) continue;
		if (i == 0 || (p << 1 | ch[i - 1]) > m) {
			ans += (1 << i);
			cout << "i:" << i << endl;
			p -= m;
		}
	}
	print(ans), puts("");
}

signed main() {
	T = read();
	while (T --> 0) solve();
	return 0;
}
