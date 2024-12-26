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
		if (c == '-') f =  - 1;
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

const int MOD = 998244353;
const int MAXN = 2005;
int n, m;
int b[MAXN], pre[MAXN], suf[MAXN];
int pmin[MAXN], pmax[MAXN];
int gmin[MAXN], gmax[MAXN];

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

signed main(){
	n = read(), m = read();
    rep (i, 1, n) b[i] = read();
    pmin[0] = m;
	rep (i, 1, n) {
        if (b[i] == -1) pmin[i] = pmin[i - 1];
        else pmin[i] = min(pmin[i - 1], b[i]);
    }
	_rep (i, n, 1) {
        if (b[i] == -1) pmax[i] = pmax[i + 1];
        else pmax[i] = max(pmax[i + 1], b[i]);
    }
    rep (i, 1, n) pre[i] = pre[i - 1] + (b[i] == -1);
    _rep (i, n, 1) suf[i] = suf[i + 1] + (b[i] == -1);
	int ans = 0;
	rep (p, 1, n) {
        rep (j, 1, m) gmin[j] = gmax[j] = 0;
        rep (j, 1, pmin[p]) gmin[j] = qpow(m - j + 1, pre[p]);
		rep (j, pmax[p + 1], m) gmax[j] = qpow(j, suf[p + 1]);
        rep (j, 2, m) ans = (ans + gmin[j] * (gmax[j - 1] - gmax[j - 2]) % MOD) % MOD;
    }
	ans = ans + MOD;
    ans = (ans + qpow(m, pre[n])) % MOD;
	print(ans), puts("");
    return 0;
}
