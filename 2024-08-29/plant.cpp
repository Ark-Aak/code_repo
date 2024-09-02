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
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

const int MAXN = 1e3 + 5;
const int MOD = 1e9 + 7;
int n, m, c;
int s[MAXN][MAXN], a[MAXN * MAXN];
pii q[MAXN * MAXN];

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
    freopen("plant.in", "r", stdin);
    freopen("plant.out", "w", stdout);
#endif
#endif
    n = read(), m = read(), c = read();
    if (m == 1) {
        rep (i, 1, n) a[i] = read();
        int head = 1, tail = 0;
		rep (i, 1, n) {
			if (head > tail || a[i] > q[tail].ec) {
				q[++tail] = dl(a[i], i);
				continue;
			}
			if (a[i] == q[tail].ec) continue;
			while (a[i] < q[tail].ec) {
				
			}
		}
    }
    else return 0;
	return 0;
}
