/* #ifdef ONLINE_JUDGE */
/* #pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math") */
/* #pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt") */
/* #include <immintrin.h> */
/* #include <emmintrin.h> */
/* #endif */
#include <bits/stdc++.h>

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)
#define ec first
#define fb second
#define dl make_pair
#define dk(...) make_tuple(__VA_ARGS__)

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

const int MAXN = 5e5 + 5;
const int BASE = 17;
const int MOD = 1e9 + 7;
int T, n, pw[MAXN];

namespace seg {

#define ls(x) ((x) << 1)
#define rs(x) ((x) << 1 | 1)
#define mid ((L + R) >> 1)

	int fh[MAXN << 2], rh[MAXN << 2];

	void pushup(int x, int L, int R) {
		fh[x] = (1ll * fh[ls(x)] * pw[R - mid] % MOD + fh[rs(x)]) % MOD;
		rh[x] = (1ll * rh[rs(x)] * pw[mid - L + 1] % MOD + rh[ls(x)]) % MOD;
	}

	void modify(int x, int L, int R, int pos) {
		if (L == R) {
			fh[x] = rh[x] = 1;
			return;
		}
		if (pos <= mid) modify(ls(x), L, mid, pos);
		else modify(rs(x), mid + 1, R, pos);
		pushup(x, L, R);
	}

	pii askF(int x, int L, int R, int l, int r) {
		if (l <= L && R <= r) return dl(fh[x], R - L + 1);
		pii resL = dl(0, 0), resR = dl(0, 0);
		if (l <= mid) resL = askF(ls(x), L, mid, l, r);
		if (r > mid) resR = askF(rs(x), mid + 1, R, l, r);
		return dl((1ll * resL.ec * pw[resR.fb] % MOD + resR.ec) % MOD, resL.fb + resR.fb);
	}

	pii askR(int x, int L, int R, int l, int r) {
		if (l <= L && R <= r) return dl(rh[x], R - L + 1);
		pii resL = dl(0, 0), resR = dl(0, 0);
		if (l <= mid) resL = askR(ls(x), L, mid, l, r);
		if (r > mid) resR = askR(rs(x), mid + 1, R, l, r);
		return dl((1ll * resR.ec * pw[resL.fb] % MOD + resL.ec) % MOD, resL.fb + resR.fb);
	}
} // namespace seg

int a[MAXN];

void solve() {
	memset(seg::fh, 0, sizeof seg::fh);
	memset(seg::rh, 0, sizeof seg::rh);
	n = read();
	rep (i, 1, n) a[i] = read();
	rep (i, 1, n) {
		seg::modify(1, 1, n, a[i]);
		int len = min(a[i], n - a[i] + 1);
		int resL = seg::askF(1, 1, n, a[i] - len + 1, a[i] + len - 1).ec;
		int resR = seg::askR(1, 1, n, a[i] - len + 1, a[i] + len - 1).ec;
		if (resL != resR) return puts("Y"), void();
	}
	puts("N");
}

signed main() {
	pw[0] = 1;
	rep (i, 1, 5e5) pw[i] = 1ll * pw[i - 1] * BASE % MOD;
	T = read();
	while (T --> 0) solve();
	return 0;
}
/*
1
10
1 9 5 3 7 4 8 10 2 6
*/
