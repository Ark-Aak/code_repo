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

//g(n) = f(n) - \sum_{d|n, d != n} g(d) * n / d

#define int ll

const int MAXN = 1e5 + 5;
int n, k;
const int MOD = 998244353;
int h[MAXN], qz[MAXN];

int qpow(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = res * a % MOD;
		a = a * a % MOD;
		b >>= 1;
	}
	return res;
}

void sieve() {
	rep (i, 1, n) {
		for (int j = i + i; j <= n; j += i) {
			h[j] -= h[i] * (j / i) % MOD;
			h[j] += MOD;
			h[j] %= MOD;
		}
	}
}

signed main() {
#ifndef LOCAL
#ifndef ONLINE_JUDGE
	freopen("palindrome.in", "r", stdin);
	freopen("palindrome.out", "w", stdout);
#endif
#endif
	cin >> n >> k;
	h[1] = h[2] = k % MOD;
	qz[1] = k % MOD, qz[2] = 2 * k % MOD;
	rep (i, 3, n) h[i] = h[i - 2] * k % MOD, h[i] %= MOD, qz[i] = qz[i - 1] + h[i], qz[i] %= MOD;
	rep (i, 1, n) h[i] = qz[i];
	rep (i, 0, n) cout << h[i] << " ";
	cout << endl;
	sieve();
	rep (i, 0, n) cout << h[i] << " ";
	return 0;
}