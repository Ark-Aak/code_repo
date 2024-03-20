#include <bits/stdc++.h>

#define rep(i, a, b) for(auto i = (a); i <= (b); i++)
#define _rep(i, a, b) for(auto i = (a); i >= (b); i--)

using namespace std;

#define int ll

typedef long long ll;
typedef pair <int, int> pii;

template <typename _Tp>
void read(_Tp& first) {
	_Tp x = 0, f = 1; char c = getchar();
	while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
	while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
	first = x * f;
}

template <typename _Tp>
void print(_Tp x) {
	if (x < 0) x = (~x + 1), putchar('-');
	if (x > 9) print(x / 10);
	putchar(x % 10 + '0');
}

int qpow(int a, int b, int p) {
	int res = 1;
	while (b) {
		if (b & 1) res = (res * a) % p;
		a = (a * a) % p;
		 b >>= 1;
	}
	return res;
}

int n, x, t[1005], f[1000005], ans;

signed main() {
	cin >> n >> x;
	const int inv = qpow(n, 998244351, 998244353);
	rep (i, 1, n) cin >> t[i];
	f[0] = 1;
	rep (i, 0, x) {
		rep (j, 1, n) {
			if (i + t[j] > x && j == 1) {
				ans = (ans + f[i] * inv) % 998244353;
			}
			f[i + t[j]] = (f[i + t[j]] + f[i] * inv) % 998244353;
		}
	}
	cout << ans;
	return 0; 
}
