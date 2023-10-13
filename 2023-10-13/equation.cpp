#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {
		if (c == '-') f = -1;
		c = getchar();
	}
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

#define int ll

int T, p;
int a, n, d, sum[10000005];

int qpow(int a, int b, int p) {
	int res = 1;
	while (b) {
		if (b & 1) res = (res * a) % p;
		a = (a * a) % p;
		b >>= 1;
	}
	return res;
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("equation.in", "r", stdin);
	freopen("equation.out", "w", stdout);
#endif
#endif
	read(T), read(p);
	while (T --> 0) {
		read(a), read(d), read(n);
		if (sum[0] == 0) {
			sum[0] = a % p;
			rep (i, 1, p - 1) {
				sum[i] = (sum[i - 1] * (a + i * d) % p);
			}
		}
		int blk = n / p;
		int ans = qpow(sum[p - 1], blk, p);
		rep (i, blk * p, n - 1) {
			ans = (ans * (a + i * d) % p);
		}
		//n % p
		print(ans), putchar(10);
	}
	return 0;
}
