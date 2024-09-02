#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt")
#include <immintrin.h>
#include <emmintrin.h>
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
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 5e5 + 5;
const int MOD = 1e9 + 7;
int pw[MAXN], ans[MAXN];
int n, k, a[MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
    freopen("knight.in", "r", stdin);
    freopen("knight.out", "w", stdout);
#endif
#endif
    n = read(), k = read();
    pw[0] = 1;
    rep (i, 1, n) pw[i] = 1ll * pw[i - 1] * 23 % MOD;
    rep (i, 1, n) a[i] = read();
    rep (i, 1, k) {
        ans[i] = max(ans[i - 1], a[i]);
    }
    if (n <= 2000) {
        rep (i, k + 1, n) {
            int res = 2e9, mx = 0;
            _rep (j, i, i - k + 1) {
                mx = max(mx, a[j]);
                res = min(res, mx + ans[j - 1]);
            }
            ans[i] = res % MOD;
        }
    }
    else {
        int mx = 0, sum = 0;
        rep (i, 1, n) {
            mx = max(mx, a[i]);
            ans[i] = (sum + mx) % MOD;
            if (!(i % k)) sum += mx, mx = 0, sum %= MOD;
        }
    }
    int pans = 0;
    rep (i, 1, n) pans = (pans + pw[n - i] * ans[i] % MOD) % MOD;
    print(pans), puts("");
	return 0;
}
