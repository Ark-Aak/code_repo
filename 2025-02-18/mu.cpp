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

ll read() {
	ll x = 0, f = 1; char c = getchar();
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

bool stmer;
const int MAXN = 1.2e7 + 5;
const int MAXM = 2e8 + 5;
int prime[MAXN], tot;
short mu[MAXM];
bitset <MAXM> vis;
bool edmer;

void init(int N) {
	mu[1] = 1;
	rep (i, 2, N) {
		if(vis[i] == 0) {
			prime[++tot] = i;
			mu[i] = -1;
		}
		for(int j = 1; j <= tot && prime[j] * i <= N; j++) {
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) {
				break;
			}
			mu[i * prime[j]] = -mu[i];
		}
	}
}

ll n, k;

int calc(ll x) {
	int flg = 1;
	rep (i, 2, sqrtl(x)) {
		if (x % i != 0) continue;
		if (x % (i * i) == 0) return 0;
		x /= i;
		flg *= -1;
	}
	return flg;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("mu.in", "r", stdin);
	freopen("mu.out", "w", stdout);
#endif
#endif
	n = read(), k = read();
	if (n <= 2e8) {
		init(2e8);
		int ans = 0;
		rep (i, 1, n - k) ans += (mu[i] * mu[i + k]) * (mu[i] * mu[i + k]);
		print(ans), puts("");
		return 0;
	}
	else if (n - k <= 500) {
		int ans = 0;
		rep (i, 1, n - k) {
			int ca = calc(i), cb = calc(i + k);
			ans += ca * ca * cb * cb;
		}
		print(ans), puts("");
	}
	else puts("0");
	return 0;
}
