#include <bits/stdc++.h>

#define int ll

#define rep(i, a, b) for(int i = (a), i##end = (b); i <= i##end; i++)
#define _rep(i, a, b) for(int i = (a), i##end = (b); i >= i##end; i--)

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

const int MAXN = 1e5;
const long double PI = acos(-1.0);
int T, tot, prime[MAXN + 5], mu[MAXN + 5], vis[MAXN + 5];
int G[MAXN + 5], val[MAXN];

void init() {
	mu[1] = 1;
	rep (i, 2, MAXN) {
		if(vis[i] == 0) {
			prime[++tot] = i;
			mu[i] = -1;
		}
		for(int j = 1; j <= tot && prime[j] * i <= MAXN; j++) {
			vis[i * prime[j]] = 1;
			if(i % prime[j] == 0) {
				break;
			}
			mu[i * prime[j]] = -mu[i];
		}
	}
}

int F(int x, int res = 0) {
	rep (d, 1, sqrt(x)) {
		int s = 0;
		if(!(d & 1)) continue;
		rep (i, 1, ((int) sqrt(x)) / d) {
			int z = sqrt(x - i * i * d * d) / d;
			if (i & 1) s += z - (z + 1) / 2;
			else s += (z + 1) / 2;

		}
		res += mu[d] * s;
	}
	// 莫反单点 F
	return res >> 1;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("pi.in", "r", stdin);
	freopen("pi.out", "w", stdout);
#endif
#endif
	init();
	T = read();
	while (T --> 0) {
		int l = read(), r = read();
		int f = F(l - 1);
		rep (i, 0, r - l) G[i] = 1, val[i] = i + l;
		rep (i, 1, tot) {
			rep (j, ceil(l * 1.0 / prime[i]), r / prime[i]) {
				int now = prime[i] * j - l;
				while (val[now] % prime[i] == 0) {
					val[now] /= prime[i];
				}
				if (prime[i] % 4 == 1) G[now] <<= 1;
				else G[now] = 0;
			}
		}
		// 区间筛 F 增量
		rep (i, 0, r - l) {
			if (val[i] ^ 1) {
				if (val[i] % 4 == 1) G[i] <<= 1;
				else G[i] = 0;
			}
		}
		// 剩下的大素数
		int ta = 1, tb = 0;
		long double ans = 2e9;
		rep (i, l, r) {
			f += G[i - l] / 2;
			long double nw = fabs((long double) i / 2 / f - PI);
			ans = abs((long double) ta / tb - PI);
			if (nw < ans) ans = nw, ta = i, tb = f << 1;
		}
		int GCD = __gcd(ta, tb);
		ta /= GCD, tb /= GCD;
		printf("%lld / %lld\n", ta, tb);
	}
	return 0;
}
